#include "Garcom.h"
#include <iostream>
#include <sqlite3.h>
Garcom::Garcom(){
}

Garcom::Garcom(std::string nome, std::string cpf,int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario):
    Funcionario(nome, cpf, codigo,contratadoem,cargahoraria,avaliacao,telefone, salario, "G2"){};

void Garcom::calcular_salariofinal(){
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
        std::cout << query << std::endl;

        rc = sqlite3_open("./db.sqlite3", &db);
        std::cout << "Ok!\n";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument("Erro ao atualizar salário de garçom no banco de dados");
        }
        else
        {
            sqlite3_close(db);
            std::cout << "Salário final do garçom cadastrado com sucesso!" << std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados" << std::endl;
    }
}

void Garcom::verPedidos(){
    std::cout<< "Visualizando pedidos" << std::endl;
    
    //select 
}

void Garcom::finalizarPedido(int codigo_pedido){
    std::cout<< "Finalizando pedidos" << std::endl;
    //delete
}
Garcom::~Garcom(){
    
}


