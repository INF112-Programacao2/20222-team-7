from django.shortcuts import render, reverse
from .models import *
from .forms import *
from django.http import HttpResponseRedirect
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.contrib import messages

@login_required(login_url="login")
def index(request):
    itens = Item.objects.all()
    if request.method =='GET':
        pedido_form = PedidoForm(initial = {"cliente":request.user})

    if request.method == 'POST':
        pedido_form = PedidoForm(request.POST)
        if pedido_form.is_valid():
            pedido_form.save()
            messages.success(request, "Pedido salvo com sucesso!")
            return HttpResponseRedirect(reverse('pedidos'))
        else:
            messages.warning(request, "Algo errado com o formulário de pedidos")
            return render(request=request, template_name='core/index.html', context={"pedido_form":pedido_form, "itens":itens})
    
    return render(request=request, template_name='core/index.html', context={"pedido_form":pedido_form, "itens":itens})
    

@login_required(login_url="login")
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
def gerencia(request):
    funcionarios = Funcionario.objects.all()
    if request.method=='GET':
        funcionarios_demissao = request.GET.getlist("func")
        if funcionarios_demissao:
            funcionarios_demissao = [int(i) for i in funcionarios_demissao]
            Funcionario.objects.filter(id__in=funcionarios_demissao).delete()
            messages.success(request, "Funcionário desligado com sucesso!")

        funcionario_form = FuncionarioForm()
    if request.method == 'POST':
        funcionario_form = FuncionarioForm(request.POST)
        if funcionario_form.is_valid():
            funcionario_form.save()
            messages.success(request, "Funcionário cadastrado com sucesso!")

            return HttpResponseRedirect(reverse('gerencia'))
        else:
            return render(request, template_name='core/gerencia.html', context = {"funcionario_form":funcionario_form, "funcionarios":funcionarios})

    return render(request, template_name='core/gerencia.html', context = {"funcionario_form":funcionario_form, "funcionarios":funcionarios})


@login_required(login_url="login")
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
