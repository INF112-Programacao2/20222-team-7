#include <iostream>
#include "./Restaurante/Restaurante.h"
#include "./Cliente/Cliente.h"
#include "./Gerente/Gerente.h"
#include "./Garcom/Garcom.h"
#include "./Item/Item.h"
#include "./Pedido/Pedido.h"
#include <boost/function.hpp>
#include <boost/bind.hpp>

bool cliente_logado = false;
bool garcom_logado = false;
bool dono_logado = false;
bool gerente_logado = false;
Dono *dono_unico = new Dono(1, "GRUPO DILA");
Restaurante *restaurante_unico = new Restaurante(*dono_unico, "Rua 1", "CompFood", 0, "8:00 - 22:00", "123456789");

int main();

void redirecionamento(boost::function<void()>funcao_cabecalho){
    std::string opcao;
    std::cout << "DESEJA VOLTAR AO MENU ANTERIOR? (1 - SIM / 2 - NÃO)" << std::endl;
    std::cin >> opcao;
    if(opcao == "1"){
        system("clear");
        funcao_cabecalho();
    }else{
        std::cout << "OBRIGADO POR UTILIZAR NOSSO SISTEMA" << std::endl;
        std::exit(0);
    }
}

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
    std::cout << "SAIR - 0\n";
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
            redirecionamento( boost::bind( &cabecalho_dono, dono ));
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
            redirecionamento(  boost::bind( &cabecalho_dono, dono ));
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
            redirecionamento(  boost::bind( &cabecalho_dono, dono ));
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
            redirecionamento( boost::bind( &cabecalho_dono, dono ));
            break;
        case 0:
            std::cout << "OBRIGADO POR UTILIZAR NOSSO SISTEMA" << std::endl;
            std::exit(0);
            break;
        default:
            std::cout << "OPÇÃO INVÁLIDA" << std::endl;
            redirecionamento( boost::bind( &cabecalho_dono, dono ));
            break;
    }


}

void cabecalho_gerente(Gerente &gerente){
    int opc;
    std::cout << "=============================================================" << std::endl;
    std::cout << "CONTRATAR GARCOM - 1\n";
    std::cout << "DEMITIR GARCOM - 2\n";
    std::cout << "AVALIAR GARCOM - 3\n";
    std::cout << "SAIR - 0\n";
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
            redirecionamento(boost::bind( &cabecalho_gerente, gerente ));
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
            redirecionamento(boost::bind( &cabecalho_gerente, gerente ));
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
            redirecionamento(boost::bind( &cabecalho_gerente, gerente ));
            break;
        case 0:
            std::cout << "OBRIGADO POR UTILIZAR NOSSO SISTEMA" << std::endl;
            std::exit(0);
            break;
        default:
            std::cout << "OPÇÃO INVÁLIDA" << std::endl;
            redirecionamento(boost::bind( &cabecalho_gerente, gerente ));
            break;
    }
}

void cabecalho_garcom(Garcom &garcom){
    int opc;
    std::cout << "=============================================================" << std::endl;    
    std::cout << "LISTAR PEDIDOS - 4\n";
    std::cout << "FINALIZAR PEDIDO - 5\n";
    std::cout << "SAIR - 0\n";
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
            redirecionamento(boost::bind( &cabecalho_garcom, garcom) );
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
            redirecionamento(boost::bind( &cabecalho_garcom, garcom) );
            break;
        case 0:
            std::cout << "OBRIGADO POR UTILIZAR NOSSO SISTEMA" << std::endl;
            std::exit(0);
            break;
        default:
            std::cout << "OPÇÃO INVÁLIDA" << std::endl;
            redirecionamento(boost::bind( &cabecalho_garcom, garcom) );
            break;
    }
}

void cabecalho_cliente(Cliente &cliente){
    int opc;
    std::cout << "=============================================================" << std::endl;
    std::cout << "FAZER PEDIDO - 6\n";
    std::cout << "AVALIAR RESTAURANTE - 7\n";
    std::cout << "SAIR - 0\n";
    std::cout << "=============================================================" << std::endl;
    std::cout << "ESCOLHA UMA OPÇÃO: "<< std::endl;
    std::cin >> opc;
    switch (opc)
    {
        case 6:
            try
            {
                restaurante_unico->mostrar_cardapio();
                cliente.fazer_pedido();
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            redirecionamento(boost::bind( &cabecalho_cliente, cliente) );
            break;
        case 7:
            try
            {
                int avaliacao;
                std::cout << "================='AVALIAÇÃO'=================" << std::endl;
                std::cout << "DIGITE UMA NOTA PARA O RESTAURANTE: " << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cin >> avaliacao;

                cliente.avaliar_restaurante(*restaurante_unico, avaliacao);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            redirecionamento(boost::bind( &cabecalho_cliente, cliente) );
            break;
        case 0:
            std::cout << "OBRIGADO POR UTILIZAR NOSSO SISTEMA" << std::endl;
            std::exit(0);
            break;
        default:
            std::cout << "OPÇÃO INVÁLIDA" << std::endl;
            redirecionamento(boost::bind( &cabecalho_cliente, cliente) );
            break;
    }
    
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

        redirecionamento(boost::bind( &logar_cliente ));
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
        redirecionamento(boost::bind( &logar_garcom ));

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
        redirecionamento(boost::bind( &logar_gerente ));

    }
    Gerente gerente("Gerente Operador", "123456789", 1, "2020-01-01", 40, 5, "123456789", 1000);
    return gerente;
}

void logar_dono(){
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
    else{
        std::cout<<"====================================="<<std::endl;
        std::cout<<"USUÁRIO OU SENHA INCORRETOS =(\n";
        std::cout<<"====================================="<<std::endl;
        redirecionamento(boost::bind( &logar_dono ));

    }

}

int cabecalho_login(){
    std::cout << "================================" << std::endl;
    std::cout << "ESCOLHA O TIPO DE LOGIN: \n";
    std::cout << "================================" << std::endl;
    std::cout << "LOGIN PROPRIETÁRIO - 1\n";
    std::cout << "LOGIN GERENTE - 2\n";
    std::cout << "LOGIN GARÇOM - 3\n";
    std::cout << "LOGIN CLIENTE - 4\n";
    std::cout << "FINALIZAR - 5\n";
    int opc;
    std::cout<<"ESCOLHA UMA OPÇÃO: \n";
    std::cin >> opc;
    system("clear");
    return opc;
}
int main(){
    int opc_login;
    Gerente gerente_operador ;
    Garcom garcom_operador ;
    Cliente  cliente_operador ;
    cabecalho_boas_vindas();
    opc_login = cabecalho_login();
    switch (opc_login)
    {
    case 1:
        logar_dono();
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
    case 5:
        std::cout << "================================" << std::endl;
        std::cout << "PROGRAMA FINALIZADO COM SUCESSO\n";
        std::cout << "================================" << std::endl;
        exit(0);
        break;
    default:
        std::cout<< "OPCÃO INVÁLIDA\n";
        std::cout << "OBRIAGADO POR USAR O SISTEMA =)\n";
        break;

    }
    if (dono_logado)
        cabecalho_dono(*dono_unico);
    else if(gerente_logado)
        cabecalho_gerente(gerente_operador);
    else if(garcom_logado)
        cabecalho_garcom(garcom_operador);
    else if(cliente_logado)
        cabecalho_cliente(cliente_operador);

    delete dono_unico;
    delete restaurante_unico;
    return 0;
}
