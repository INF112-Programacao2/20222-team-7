# Generated by Django 4.1.2 on 2022-10-19 02:20

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('core', '0002_remove_funcionario_avaliação_funcionario_avaliacao'),
    ]

    operations = [
        migrations.AddField(
            model_name='pedido',
            name='forma_pagamento',
            field=models.IntegerField(choices=[(0, 'Cartão de crédito'), (1, 'PIX'), (2, 'Dinheiro à vista')], default=2),
        ),
    ]
