#include <iostream>
#include "Restaurante.h"
#include "Cliente.h"
#include "Funcionario.h"
#include "Gerente.h"
#include "Item.h"
#include "Pedido.h"


bool cliente_logado = false;
bool garcom_logado = false;
bool dono_logado = false;
bool gerente_logado = false;

void cabecalho_gerente(){
    //Contém todas as funções que o código terá, exemplo: Contaratar funcionário,
    //
    std::cout << "Contratar funcionário - 1\n";
    std::cout << "Demitir funcionário - 2\n";
    std::cout << "Listar Pedidos - 3\n";
    std::cout << "Fazer Pedido - 4\n";
    std::cout << "Adicionar Item - 5\n";
    std::cout << "Finalizar Pedido - 6\n";
}

void cabecalho_garcom(){
// Mesma coisa com gerente;
    std::cout << "Listar Pedidos - 3\n";
    std::cout << "Fazer Pedido - 4\n";
    std::cout << "Finalizar Pedido - 6\n";
}

void cabecalho_cliente(){
    std::cout << "Fazer pedido - 4\n";
}

void logar_cliente(){
    std::string usuario, senha;
    std::cout<< "Login de cliente: \n\n";

    std::cout<< "Usuario: \n";
    std::cin >> usuario;
    std::cout<< "Senha: \n";
    std::cin >> senha;
    if(usuario == "cliente" && senha == "cliente"){
        cliente_logado = true;
        system("clear");
        std::cout << "Cliente logado\n";
    }
}

void logar_garcom(){
    std::string usuario, senha;
    std::cout<< "Login de garçom: \n\n";


    std::cout<< "Usuario: \n";
    std::cin >> usuario;
    std::cout<< "Senha: \n";
    std::cin >> senha;
    if(usuario == "garcom" && senha == "garcom"){
        garcom_logado = true;
        system("clear");
        std::cout << "Garçom logado\n";
    }
}

void logar_gerente(){
    std::string usuario, senha;
    std::cout<< "Login de Gerente: \n\n";

    std::cout<< "Usuario: \n";
    std::cin >> usuario;
    std::cout<< "Senha: \n";
    std::cin >> senha;
    if(usuario == "gerente" && senha == "gerente"){
        gerente_logado = true;
        system("clear");
        std::cout << "Gerente logado\n";
    }
}

void logar_dono(){
    std::string usuario, senha;
    std::cout<< "Login de proprietário: \n\n";

    std::cout<< "Usuario: \n";
    std::cin >> usuario;
    std::cout<< "Senha: \n";
    std::cin >> senha;
    
    if(usuario == "dono" && senha == "dono"){
        dono_logado = true;
        system("clear");
        std::cout << "Dono logado\n";
    }
}

int cabecalho_login(){
    std::cout << "Login Proprietário - 1\n";
    std::cout << "Login Gerente - 2\n";
    std::cout << "Login Garçom - 3\n";
    std::cout << "Login Cliente - 4\n";
    int opc;
    std::cout << "Escolha uma opção: \n";
    std::cin >> opc;
    system("clear");
    return opc;
}
int main(){
    int opc_login;
    opc_login = cabecalho_login();
    switch (opc_login)
    {
    case 1:
        logar_dono();
        break;
    case 2:
        logar_gerente();
        break;
    case 3:
        logar_garcom();
        break;
    case 4:
        logar_cliente();
        break;
    
    default:
        std::cout<< "OPCÃO INVÁLIDA\n";
    }
    if (dono_logado)
        cabecalho_gerente(); // dono e gerente tem praticamente as mesmas funções
    else if(gerente_logado)
        cabecalho_gerente();
    else if(garcom_logado)
        cabecalho_garcom();
    else if(cliente_logado)
        cabecalho_cliente();

    
    
    return 0;
}

