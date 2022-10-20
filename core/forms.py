from django.forms import ModelForm
from .models import *
from django.contrib.auth.forms import AuthenticationForm

class ItemForm(ModelForm):
    class Meta:
        model = Item
        fields = "__all__"

    def __init__(self, *args, **kwargs):
        super(ItemForm, self).__init__(*args, **kwargs)
        for f in self.fields:
            self.fields[f].widget.attrs["class"] = "form-control"

class FuncionarioForm(ModelForm):
    class Meta:
        model=Funcionario
        fields = "__all__"

    def __init__(self, *args, **kwargs):
        super(FuncionarioForm, self).__init__(*args, **kwargs)
        for f in self.fields:
            self.fields[f].widget.attrs["class"] = "form-control"

        self.fields["restaurante"].initial = Restaurante.objects.first().id
        self.fields["restaurante"].disabled = True
            
class PedidoForm(ModelForm):
    class Meta:
        model = Pedido
        fields = "__all__"

    def __init__(self, *args, **kwargs):
        super(PedidoForm, self).__init__(*args, **kwargs)
        for f in self.fields:
            self.fields[f].widget.attrs["class"] = "form-control"
        #self.fields["cliente"].disabled = True

class LoginForm(AuthenticationForm):
    class Meta:
        fields = "__all__"

    def __init__(self,*args, **kwargs):
        super(LoginForm,self).__init__(*args, **kwargs)
        for f in self.fields:
            self.fields[f].widget.attrs["class"] = "form-control"
        self.fields["username"].label = "Usuário"
        self.fields["password"].label = "Senha"