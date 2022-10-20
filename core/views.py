from django.shortcuts import render, reverse
from .models import *
from .forms import *
from django.http import HttpResponseRedirect


def index(request):
    if request.method =='GET':
        itens = Item.objects.all()
        pedido_form = PedidoForm(initial = {"cliente":request.user})

    if request.method == 'POST':
        pedido_form = PedidoForm(request.POST)
        if pedido_form.is_valid():
            pedido_form.save()
            return HttpResponseRedirect(reverse('pedidos'))
        else:
            return render(request=request, template_name='core/index.html', context={"pedido_form":pedido_form, "itens":itens})
    
    return render(request=request, template_name='core/index.html', context={"pedido_form":pedido_form, "itens":itens})
    

def pedidos(request):
    if request.method=="GET":
        pedidos = Pedido.objects.all()
        itens = request.GET.getlist("itens")
        if itens:
            itens = [int(i) for i in itens]
            for i in itens:
                Pedido.objects.filter(id__in = itens).delete()

    return render(request, template_name='core/pedidos.html', context={"pedidos":pedidos})

def gerencia(request):
    funcionarios = Funcionario.objects.all()
    if request.method=='GET':
        funcionarios_demissao = request.GET.getlist("func")
        if funcionarios_demissao:
            funcionarios_demissao = [int(i) for i in funcionarios_demissao]
            Funcionario.objects.filter(id__in=funcionarios_demissao).delete()

        funcionario_form = FuncionarioForm()
    if request.method == 'POST':
        funcionario_form = FuncionarioForm(request.POST)
        if funcionario_form.is_valid():
            funcionario_form.save()
            return HttpResponseRedirect(reverse('gerencia'))
        else:
            return render(request, template_name='core/gerencia.html', context = {"funcionario_form":funcionario_form, "funcionarios":funcionarios})

    return render(request, template_name='core/gerencia.html', context = {"funcionario_form":funcionario_form, "funcionarios":funcionarios})

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