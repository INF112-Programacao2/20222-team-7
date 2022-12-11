#  CompFood - uma ferramenta integrada para gerenciamento de restaurantes

O projeto consiste em um gerenciador 
de funcionários, pedidos, cardápio e clientes de 
um restaurante. A ferramenta foi pensada para atender às necessidades 
dos funcionários (como a visualização e finalização de pedidos, por exemplo), às necessidades do proprietário 
(demissão \ contratação \ avaliação de funcionário \ definição de salário) e às necessidades do cliente (visualização do
cardápio \ criação de pedido)

## Interface x código
A Interface do projeto foi moldada usando html, css, bootstrap...
e o backend em Python e Django.
O código C++ se conecta ao banco de dados da aplicação Django,
fazendo com que seja possível a interligação do projeto como um todo. As modificações feitas
via terminal utilizando o C++ são salvas no banco e, portanto, são 
acessíveis ao acessar a interface (e vice-versa)

## Compilação do projeto
Para compilar o projeto, algumas dependências devem ser 
instaladas :

## Instalação
Instale o sqlite3, usando:

```bash
  apt-get install sqlite3 libsqlite3-dev
```
Para compilar:
```bash
    g++  maintrabfinal.cpp Dono/Dono.cpp 
    Funcionario/Funcionario.cpp Cliente/Cliente.cpp
    Gerente/Gerente.cpp Garcom/Garcom.cpp Item/Item.cpp Pedido/Pedido.cpp 
    Restaurante/Restaurante.cpp Validacao/validacao.cpp -l sqlite3
```
Para executar:
```bash
    ./a.out
```
Você também precisa do Python instalado para que consiga 
executar o projeto como um todo. Feito isso, clone o projeto e, na pasta em que o projeto foi clonado, crie um ambiente virtual:
```bash
    python3 -m venv env
```
Ative o ambiente virtual:
```bash 
    source env/bin/activate
```
Agora, basta instalar as dependências que constam no arquivo requirements.txt:
```bash
    pip install -r requirements.txt
```

Para ativar o servidor local e conseguir acessar o projeto:
```bash
    python manage.py runserver
```
Pronto, acesse 127.0.0.1:8000 e já terá acesso à interface
