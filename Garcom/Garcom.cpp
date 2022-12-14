#include "Garcom.h"
#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <cstring>

//Função auxiliar para impressão de dados de itens do pedido
static int callback_itens(void* data, int argc, char** argv, char** azColName)
{
    int i;
    
    for (i = 0; i < argc; i++) {
        std::cout << azColName[i] <<" = "<< (argv[i] ? argv[i] : "NULL") << std::endl;  
    }
  
    std::cout << std::endl;
    return 0;
}

// Função auxiliar para a impressão dos dados dos pedidos
static int callback_pedidos(void* data, int argc, char** argv, char** azColName)
{
    int i;
    std::cout << "PEDIDO"<< std::endl;
    std::vector<std::string> formas_pagamento = {"Cartão de crédito", "PIX", "Dinheiro à vista"};
  
    for (i = 0; i < argc; i++) {
        if(strcmp(std::string("forma_pagamento").c_str(), azColName[i]) == 0){
            std::cout << azColName[i] <<" = "<< (argv[i] ? formas_pagamento[std::stoi(argv[i])] : "NULL") << std::endl;
        }
        else{
            std::cout << azColName[i] <<" = "<< (argv[i] ? argv[i] : "NULL") << std::endl;
        }

    }
    
    std::cout<<"+++++++++++++++++++++++++++++ITENS DO PEDIDO++++++++++++++++++++++++++++++"<<std::endl;
    std::string query = "SELECT pd.item_id, c.nome FROM core_pedido_lista_itens pd, core_item c WHERE pedido_id = "+ std::string(argv[0])+
    " AND pd.item_id = c.id";
    try{
        char *msg_erro;
        sqlite3 *db;
        int rc;
        rc = sqlite3_open("./db.sqlite3", &db);
        // select dos itens do pedido
        rc = sqlite3_exec(db, query.c_str(), callback_itens, NULL, &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument(msg_erro);
        }
        else
        {
            sqlite3_close(db);
            // tudo certo
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }

    std::cout<<"============================================================"<<std::endl;
  
    std::cout << std::endl;
    return 0;
}


Garcom::Garcom(){
}

Garcom::Garcom(std::string nome, std::string cpf,int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario):
    Funcionario(nome, cpf, codigo,contratadoem,cargahoraria,avaliacao,telefone, salario, "G2"){};

void Garcom::calcular_salariofinal(){
    // Esse método é responsável por calcular o salário final do garçom
    // Aqui utiliizamos o POLIMORFISMO, dado que a classe Garcom herda da classe Funcionario, e a classe Funcionario também 
    // possui o método calcular_salariofinal, mas é implementado de forma diferente
    if(_carga_horaria <= 8){
        _salariofinal = _salariominimo;
    } else{
        _horaextra = 8 - _carga_horaria;
        _salariofinal = _salariominimo + 5.5 * (_horaextra);         
    }
    try{
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        std::string query = "UPDATE core_funcionario SET salario = "+ std::to_string(this->_salariofinal) +" WHERE cpf = "+ this->_cpf;
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument(msg_erro);
        }
        else
        {
            sqlite3_close(db);
            if(!msg_erro && sqlite3_changes(db) > 0)
                std::cout << "Salário final do garçom cadastrado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados"<< e.what() << std::endl;
    }
}

void Garcom::verPedidos(){
    // Esse método é responsável por listar todos os pedidos que ainda constam no banco de dados
    std::cout<<"==========================PEDIDOS==========================="<<std::endl;

    try{
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        std::string query = "SELECT * FROM core_pedido";
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), callback_pedidos, (void*)"", &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument(msg_erro);
        }
        else
        {
            sqlite3_close(db);
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: "<< e.what() << std::endl;
    }
    //select 
}

void Garcom::finalizarPedido(){
    //  Esse método é responsável por recuperar as informações do pedido que o garçom deseja finalizar
    //  e deletar o pedido do banco de dados.
    int id_pedido;
    std::cout << "\n==========================FINALIZAR PEDIDO===========================" << std::endl;
    std::cout << "Digite o ID do pedido que deseja finalizar: ";
    std::cin >> id_pedido;
    std::cout << std::endl;
    try{
        char *msg_erro;
        sqlite3 *db;

        int rc1, rc2;
        sqlite3_stmt *stmt;
        std::string query = "DELETE FROM core_pedido WHERE id = "+ std::to_string(id_pedido);
        
        rc1 = sqlite3_open("./db.sqlite3", &db);
        rc1 = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
        query = "DELETE FROM core_pedido_lista_itens WHERE pedido_id = "+ std::to_string(id_pedido);
        rc2 = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);

        if (rc1 != SQLITE_OK || rc2 != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument(msg_erro);
        }
        else
        {
            sqlite3_close(db);
            if(!msg_erro && sqlite3_changes(db) > 0)
                std::cout << "Pedido finalizado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados" << e.what()<< std::endl;
    }
}
Garcom::~Garcom(){
    
}


