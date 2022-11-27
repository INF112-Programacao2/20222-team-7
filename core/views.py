from django.shortcuts import render, reverse
from .models import *
from .forms import *
from django.http import HttpResponseRedirect
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required, permission_required
from django.contrib import messages
from django.contrib.auth.models import User
from django.contrib.auth.models import Permission
from django.contrib.auth.forms import UserCreationForm

@login_required(login_url="login")
def index(request):
    itens = Item.objects.all()
    rest = Restaurante.objects.first()
    if request.method =='GET':
        pedido_form = PedidoForm(initial = {"cliente":request.user}, user=request.user)

    if request.method == 'POST':
        pedido_form = PedidoForm(request.user, request.POST)
        if pedido_form.is_valid():
            pedido_form.save()
            messages.success(request, "Pedido realizado com sucesso. Já será preparado!")
            return HttpResponseRedirect(reverse('index'))
        else:
            messages.warning(request, "Algo errado com o formulário de pedidos")
            return render(request=request, template_name='core/index.html', context={"pedido_form":pedido_form, "itens":itens, "rest":rest})
    
    return render(request=request, template_name='core/index.html', context={"pedido_form":pedido_form, "itens":itens, "rest":rest})
    

@login_required(login_url="login")
@permission_required('core.delete_pedido', raise_exception=True)
def pedidos(request):
    if request.method=="GET":
        pedidos = Pedido.objects.all()
        itens = request.GET.getlist("itens")
        if itens:
            itens = [int(i) for i in itens]
            for i in itens:
                Pedido.objects.filter(id__in = itens).delete()
            messages.success(request, "Pedidos finalizados com sucesso!")

    return render(request, template_name='core/pedidos.html', context={"pedidos":pedidos})


@login_required(login_url="login")
@permission_required("is_staff", login_url="login")
def gerencia(request):
    funcionarios = Funcionario.objects.all()
    if request.method=='GET':
        funcionarios_demissao = request.GET.getlist("func")
        if funcionarios_demissao:
            funcionarios_demissao = [int(i) for i in funcionarios_demissao]
            funcionarios_demissao_qs = Funcionario.objects.filter(id__in=funcionarios_demissao)
            User.objects.filter(username__in=funcionarios_demissao_qs.values("cpf")).delete()
            Funcionario.objects.filter(id__in=funcionarios_demissao).delete()

            messages.success(request, "Funcionário desligado com sucesso!")

        funcionario_form = FuncionarioForm()
    if request.method == 'POST':
        funcionario_form = FuncionarioForm(request.POST)
        if funcionario_form.is_valid():
            tipo_func = request.POST.get("cargo")
            if tipo_func == "G2":#Garçom
                username_fun = request.POST.get("cpf").lower()
                password_fun = request.POST.get("nome").lower()
                user = User.objects.create_user(username = username_fun, password=password_fun)
                permission = Permission.objects.get(codename='delete_pedido')
                user.user_permissions.add(permission)

            if tipo_func == "G1":#Gerente
                username_fun = request.POST.get("cpf").lower()
                password_fun = request.POST.get("nome").lower()
                user = User.objects.create_superuser(username = username_fun, password=password_fun)

            funcionario_form.save()
            messages.success(request, "Funcionário cadastrado com sucesso!")

            return HttpResponseRedirect(reverse('gerencia'))
        else:
            return render(request, template_name='core/gerencia.html', context = {"funcionario_form":funcionario_form, "funcionarios":funcionarios})

    return render(request, template_name='core/gerencia.html', context = {"funcionario_form":funcionario_form, "funcionarios":funcionarios})


@login_required(login_url="login")
@permission_required("is_staff", login_url="login")
def cadastrar_item(request):
    if request.method == 'GET':
        item_form = ItemForm()
    if request.method == 'POST':
        item_form = ItemForm(request.POST)
        print(item_form)

        if item_form.is_valid():
            item_form.save()
            return HttpResponseRedirect(reverse("index"))
        else:
            return render(request, template_name='core/cadastro_itens.html', context={"item_form":item_form})

    return render(request, template_name='core/cadastro_itens.html', context={"item_form":item_form})


@login_required(login_url="login")
@permission_required("is_staff", login_url="login")
def avaliacao_funcionario(request):
    if request.method == "POST":
        avaliacao_funcionario = request.POST.get("nota_func")
        func_avaliados = request.POST.getlist("func_aval")

        if avaliacao_funcionario and func_avaliados:
            func_avaliados = [int(i) for i in func_avaliados]
            Funcionario.objects.filter(id__in=func_avaliados).update(avaliacao=avaliacao_funcionario)
            messages.success(request, "Avaliação cadastrada com sucesso!")
            
        return HttpResponseRedirect(reverse(gerencia))

def login_usr(request):
    if request.method == 'GET':
        auth_form = LoginForm()
    if request.method == "POST":
        auth_form = LoginForm(request.POST)
        username = request.POST['username']
        password = request.POST['password']
        user = authenticate(request, username=username, password=password)

        if user is not None:
            login(request, user)
            messages.success(request, "Usuário logado com sucesso!")
            
            return HttpResponseRedirect(reverse("index"))

    return render(request, "registration/login.html", context={"auth_form":auth_form})

@login_required(login_url="login")
def logout_usr(request):
    
    logout(request)

    return HttpResponseRedirect(reverse('login'))


def criar_conta(request):
    if request.method == "GET":
        form_registro = RegistroForm()
    if request.method == "POST":
        form_registro = RegistroForm(request.POST)
        if form_registro.is_valid():
            form_registro.save()
            messages.success(request, "Cliente cadastrado com sucesso!")
            return HttpResponseRedirect(reverse("login"))

    return render(request, "registration/criar_conta.html", context={"form_registro":form_registro})

@login_required
def adicionar_usuarios(request):
    if request.method == "GET":
        funcio_sem_usuarios = Funcionario.objects.filter(tem_usuario=False)
        try:
            for func in funcio_sem_usuarios:
                if func.cargo == "G2":#Garçom
                    username_fun = func.cpf.lower()
                    password_fun = func.nome.lower()
                    user = User.objects.create_user(username = username_fun, password=password_fun)
                    permission = Permission.objects.get(codename='delete_pedido')
                    user.user_permissions.add(permission)

                if func.cargo == "G1":#Gerente
                    username_fun = func.cpf.lower()
                    password_fun = func.nome.lower()
                    user = User.objects.create_superuser(username = username_fun, password=password_fun)
                func.tem_usuario = True
                func.save()

        except Exception as e:
            messages.error(request, "Algo de errado ao cadastrar usuários para os novos funcionários")
        else:
            messages.success(request, "Usuários cadastrados com sucesso")

    return HttpResponseRedirect(reverse('index'))
