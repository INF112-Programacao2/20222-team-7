#include <iostream>
#include "./Restaurante/Restaurante.h"
#include "./Cliente/Cliente.h"
#include "./Gerente/Gerente.h"
#include "./Garcom/Garcom.h"
#include "./Item/Item.h"
#include "./Pedido/Pedido.h"

bool cliente_logado = false;
bool garcom_logado = false;
bool dono_logado = false;
bool gerente_logado = false;


void cabecalho_boas_vindas(){
    std::cout << "===================================================" << std::endl;
    std::cout << "BOAS VINDAS AO SISTEMA DE GERENCIAMENTO DO COMPFOOD " << std::endl;
    std::cout << "===================================================" << std::endl;
}

void cabecalho_dono(Dono &dono){
    int opc;
    std::cout << "=============================================================" << std::endl; 
    std::cout << "CONTRATAR GERENTE - 7\n";
    std::cout << "DEMITIR GERENTE - 8\n";
    std::cout << "AVALIAR GERENTE - 9\n";
    std::cout << "DEFINIR SALÁRIO DE FUNCIONÁRIO - 10\n";
    std::cout << "=============================================================" << std::endl;
    std::cout << "ESCOLHA UMA OPÇÃO: "<< std::endl;
    std::cin >> opc;
    switch (opc)
    {
        case 7:
            try
            {
               dono.contratar_gerente();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            break;
        case 8:
            try
            {
                dono.demitir_gerente();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            break;
        case 9:
            try
            {
                dono.avaliar_gerente();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 10:
            try
            {
                dono.definir_salario();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            break;
        default:
            std::cout << "OPÇÃO INVÁLIDA" << std::endl;
            break;
    }


}

void cabecalho_gerente(Gerente &gerente){
    //Contém todas as funções que o código terá, exemplo: Contaratar funcionário,
    int opc;
    std::cout << "=============================================================" << std::endl;
    std::cout << "CONTRATAR GARCOM - 1\n";
    std::cout << "DEMITIR GARCOM - 2\n";
    std::cout << "AVALIAR GARCOM - 3\n";
    std::cout << "=============================================================" << std::endl;
    std::cout << "ESCOLHA UMA OPÇÃO: "<< std::endl;
    std::cin >> opc;
    switch (opc)
    {
        case 1:
            try
            {
                gerente.contratar_garcom();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            break;
        case 2:
            try
            {
                gerente.demitir_garcom();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            break;
        case 3:
            try
            {
                gerente.avaliar_garcom();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            break;
        default:
            std::cout << "OPÇÃO INVÁLIDA" << std::endl;
            break;
    }
}

void cabecalho_garcom(Garcom &garcom){
// Mesma coisa com gerente;
    int opc;
    std::cout << "=============================================================" << std::endl;    
    std::cout << "LISTAR PEDIDOS - 4\n";
    std::cout << "FINALIZAR PEDIDO - 5\n";
    std::cout << "=============================================================" << std::endl;
    std::cout << "ESCOLHA UMA OPÇÃO: "<< std::endl;
    std::cin >> opc;
    switch (opc)
    {
        case 4:
            try
            {
                garcom.verPedidos();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            break;
        case 5:
            try
            {
                garcom.verPedidos();
                garcom.finalizarPedido();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            break;
        default:
            std::cout << "OPÇÃO INVÁLIDA" << std::endl;
            break;
    }
}

void cabecalho_cliente(){
    std::cout << "=============================================================" << std::endl;
    std::cout << "FAZER PEDIDO - 6\n";
    std::cout << "=============================================================" << std::endl;
}

Cliente logar_cliente(){
    std::string usuario, senha;
    std::cout << "============================" << std::endl;
    std::cout << "LOGIN DE CLIENTES: \n";
    std::cout << "============================" << std::endl;

    std::cout<< "USUÁRIO: \n";
    std::cin >> usuario;
    std::cout<< "SENHA: \n";
    std::cin >> senha;
    if(usuario == "cliente" && senha == "cliente"){
        cliente_logado = true;
        system("clear");
        std::cout << "=================================" << std::endl;
        std::cout << "CLIENTE LOGADO COM SUCESSO =)\n";
        std::cout << "=================================" << std::endl;
    }
    else{
        std::cout << "==================================" << std::endl;
        std::cout << "USUÁRIO OU SENHA INCORRETOS =(\n";
        std::cout << "==================================" << std::endl;
    }

    Cliente cliente = Cliente("Cliente Operador", 1, 1);
    return cliente;
}

Garcom logar_garcom(){
    std::string usuario, senha;
    std::cout << "============================" << std::endl;
    std::cout << "LOGIN DE GARÇONS: \n";
    std::cout << "============================" << std::endl;


    std::cout<< "USUÁRIO: \n";
    std::cin >> usuario;
    std::cout<< "SENHA: \n";
    std::cin >> senha;
    if(usuario == "garcom" && senha == "garcom"){
        garcom_logado = true;
        system("clear");
        std::cout << "=================================" << std::endl;
        std::cout << "GARÇOM LOGADO COM SUCESSO =)\n";
        std::cout << "=================================" << std::endl;
    }
    else{
        std::cout << "==================================" << std::endl;
        std::cout << "USUÁRIO OU SENHA INCORRETOS =(\n";
        std::cout << "==================================" << std::endl;
    }
    Garcom garcom = Garcom("Garçom Operador", "12345678910", 2, "2020-01-01", 8, 10, "12345678910", 1000);
    return garcom;
}

Gerente logar_gerente(){
    std::string usuario, senha;
    std::cout << "============================" << std::endl;
    std::cout << "LOGIN DE GERENTES: \n";
    std::cout << "============================" << std::endl;

    std::cout<< "USUÁRIO: \n";
    std::cin >> usuario;
    std::cout<< "SENHA: \n";
    std::cin >> senha;
    if(usuario == "gerente" && senha == "gerente"){
        gerente_logado = true;
        system("clear");
        std::cout<<"================================="<<std::endl;
        std::cout<<"GERENTE LOGADO COM SUCESSO =)\n";
        std::cout<<"================================="<<std::endl;
    }
    else{
        std::cout<<"=================================="<<std::endl;
        std::cout<<"USUÁRIO OU SENHA INCORRETOS =(\n";
        std::cout<<"=================================="<<std::endl;
    }
    Gerente gerente("Gerente Operador", "123456789", 1, "2020-01-01", 40, 5, "123456789", 1000);
    return gerente;
}

Dono logar_dono(){
    std::string usuario, senha;
    std::cout << "============================" << std::endl;
    std::cout << "LOGIN DE PROPRIETÁRIO: \n";
    std::cout << "============================" << std::endl;

    std::cout<< "USUÁRIO: \n";
    std::cin >> usuario;
    std::cout<< "SENHA: \n";
    std::cin >> senha;
    
    if(usuario == "dono" && senha == "dono"){
        dono_logado = true;
        system("clear");
        std::cout<<"====================================="<<std::endl;
        std::cout<<"PROPRIETÁRIO LOGADO COM SUCESSO =)\n";
        std::cout<<"====================================="<<std::endl;
    }

    Dono dono_default(1, "GRUPO DILA"); 
    return dono_default;
}

int cabecalho_login(){
    std::cout << "================================" << std::endl;
    std::cout << "ESCOLHA O TIPO DE LOGIN: \n";
    std::cout << "================================" << std::endl;
    std::cout << "LOGIN PROPRIETÁRIO - 1\n";
    std::cout << "LOGIN GERENTE - 2\n";
    std::cout << "LOGIN GARÇOM - 3\n";
    std::cout << "LOGIN CLIENTE - 4\n";
    int opc;
    std::cout<<"ESCOLHA UMA OPÇÃO: \n";
    std::cin >> opc;
    system("clear");
    return opc;
}
int main(){
    int opc_login;
    Dono dono_operador;
    Gerente gerente_operador ;
    Garcom garcom_operador ;
    Cliente  cliente_operador ;
    cabecalho_boas_vindas();
    opc_login = cabecalho_login();
    switch (opc_login)
    {
    case 1:
        dono_operador = logar_dono();
        break;
    case 2:
        gerente_operador = logar_gerente();
        break;
    case 3:
        garcom_operador = logar_garcom();
        break;
    case 4:
        cliente_operador = logar_cliente();
        break;
    
    default:
        std::cout<< "OPCÃO INVÁLIDA\n";
    }
    if (dono_logado)
        cabecalho_dono(dono_operador);
    else if(gerente_logado)
        cabecalho_gerente(gerente_operador);
    else if(garcom_logado)
        cabecalho_garcom(garcom_operador);
    else if(cliente_logado)
        cabecalho_cliente();

    // Data de funcionário no estilo YYYY-MM-DD
    
    
    return 0;
}
