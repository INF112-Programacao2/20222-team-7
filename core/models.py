from django.db import models
from django.contrib.auth.models import User

# Create your models here.
class Item(models.Model):
    class Meta:
        permissions = [
            ("pode_cadastrar_item", "Pode cadastrar um novo item")
        ]
    nome = models.CharField(verbose_name= "Nome do Item", max_length=256)
    preco = models.FloatField(verbose_name="Valor")
    tempo_preparo_minutos = models.FloatField(verbose_name="Tempo de preparo(minutos)")

    def __str__(self):
        return f"{self.nome}"

class Restaurante(models.Model):
    avaliacao_media = models.FloatField(verbose_name="Avaliação Média")
    proprietario = models.CharField(max_length=250, verbose_name="Nome do Proprietário")
    localizacao = models.CharField(max_length=400, verbose_name="Localização")
    nome = models.CharField(max_length=200, verbose_name="Nome do Restaurante")
    qtd_funcionarios = models.IntegerField(verbose_name="Quantidade de Funcionários")
    horario_funcionamento = models.CharField(max_length=100, verbose_name="Horário de Funcionamento")
    cardapio = models.ManyToManyField(Item, verbose_name="Cardápio")
    telefone = models.CharField(max_length=25, verbose_name="Telefone do Restaurante")

    def __str__(self):
        return f"{self.nome}"

class Funcionario(models.Model):
    class Meta:
        permissions=[
            ("pode_gerenciar_funcionarios", "Pode gerenciar funcionários")
        ]
    CARGO_CHOICES = (
        ("G1", "Gerente"),
        ("G2", "Garçom"),
    )
    nome = models.CharField(max_length=256, null=True, blank=True, verbose_name="Nome do Funcionário")
    cpf = models.CharField(max_length=25, null=True, blank=True, verbose_name="CPF do Funcionário", unique=True)
    cargo = models.CharField(max_length=3, choices=CARGO_CHOICES, blank=False, null=False, verbose_name="Cargo")
    data_contrato = models.DateField(verbose_name="Data de contrato")
    salario = models.FloatField(verbose_name="Salário Inicial")
    carga_horaria = models.FloatField(verbose_name="Carga Horária")
    avaliacao = models.FloatField(blank=True, null=True, verbose_name="Avaliação do Funcionário")
    telefone = models.CharField(max_length=20, verbose_name="Telefone do Funcionário")
    restaurante = models.ForeignKey(Restaurante, on_delete=models.DO_NOTHING)

    def __str__(self):
        return f"{self.nome} ({self.cpf})"

class Pedido(models.Model):
    class Meta:
        permissions = [
            ("pode_modificar_pedidos","Pode modificar pedidos")
        ]
    PAGAMENTO_CHOICES = (
        (0,"Cartão de crédito"),
        (1,"PIX"),
        (2,"Dinheiro à vista")
    )
    
    cliente = models.ForeignKey(User, on_delete=models.DO_NOTHING, verbose_name="Cliente")
    lista_itens = models.ManyToManyField(Item, verbose_name="Lista de Itens")
    mesa = models.IntegerField(verbose_name="Mesa N°")
    forma_pagamento = models.IntegerField(choices=PAGAMENTO_CHOICES, default=2, verbose_name="Forma de Pagamento")
    descricao = models.CharField(max_length = 300, verbose_name="Descrição", null = True)

    def __str__(self):
        return f"{self.cliente}"