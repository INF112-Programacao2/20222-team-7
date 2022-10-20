from django.urls import path
from . import views

urlpatterns = [
    path("inicio", views.index, name="index"),
    path("pedidos", views.pedidos, name="pedidos"),
    path("gerencia",views.gerencia, name="gerencia"),
    path("cadastrar_item", views.cadastrar_item, name="cadastro_itens"),
    path("avaliacao_funcionario", views.avaliacao_funcionario, name="avaliacao_funcionario"),
    path("login", views.login_usr, name="login"),
    path("logout",views.logout_usr, name="logout"),
]