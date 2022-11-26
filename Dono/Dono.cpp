#include <iostream>
#include <string>
#include "Dono.h"
#include <sqlite3.h>

Dono::Dono(){
    
}

Dono::~Dono(){
    
}

Dono::Dono(int codigo, std::string nome){
    this->_codigo = codigo;
    this->_nome = nome;
}

void Dono::definir_salario()
{
    std::string cpf_funcionario;
    double salario;
    std::cout<< "=========================================" << std::endl;
    std::cout<< "PREENCHA OS DADOS DO FUNCIONÁRIO A SEGUIR" << std::endl;
    std::cout<< "=========================================" << std::endl;
    std::cout<< "CPF DO FUNCIONÁRIO: \n";
    std::cin>> cpf_funcionario;
    std::cout<< "SALÁRIO DO FUNCIONÁRIO: \n";
    std::cin>> salario;
    std::cout<< "=========================================" << std::endl;
    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        std::string query = "UPDATE core_funcionario SET salario = " +std::to_string(salario)+ " WHERE cpf = "+ cpf_funcionario;

        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument("Erro ao definir salário de funcionário");
        }
        else
        {
            sqlite3_close(db);
            std::cout << "Salário de funcionário definido com sucesso!" << std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }     

}   

void Dono::demitir_gerente()
{
    std::string cpf_gerente;
    std::cout<<"========================================"<<std::endl;
    std::cout<<"PREENCHA O CPF DO GERENTE A SER DEMITIDO"<<std::endl;
    std::cout<<"========================================"<<std::endl;
    std::cout<<"CPF: ";
    std::cin>> cpf_gerente;

    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        std::string query = "DELETE FROM core_funcionario WHERE cpf = "+ cpf_gerente;
        std::cout << query << std::endl;

        rc = sqlite3_open("./db.sqlite3", &db);
        std::cout << "Ok!\n";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument("Erro ao deletar funcionário do banco de dados");
        }
        else
        {
            sqlite3_close(db);
            std::cout << "Funcionário demitido com sucesso!" << std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados" << std::endl;
    }     
}

void Dono::contratar_gerente(){
    std::string nome, cpf, contratadoem, telefone;
    int codigo, cargahoraria, avaliacao; 
    double salario;
    std::cout<< "==========================================================" << std::endl;
    std::cout<< "PREENCHA O FORMULÁRIO ABAIXO PARA A CONTRATAÇÃO DO GERENTE" << std::endl;
    std::cout<< "==========================================================" << std::endl;
    std::cout<< "NOME: " << std::endl;
    std::cin >> nome;
    std::cout<< "CPF: " << std::endl;
    std::cin >> cpf;
    std::cout<< "TELEFONE: " << std::endl;
    std::cin >> telefone;
    std::cout<< "CARGA HORÁRIA: " << std::endl;
    std::cin >> cargahoraria;
    std::cout<< "AVALIAÇÃO INICIAL: " << std::endl;
    std::cin >> avaliacao;
    std::cout<< "SALÁRIO: " << std::endl;
    std::cin >> salario;
    std::cout<< "DATA DE CONTRATAÇÃO (AAAA-MM-DD): " << std::endl;
    std::cin >> contratadoem;
    std::cout<< "CÓDIGO IDENTIFICADOR: " << std::endl;
    std::cin >> codigo;

    Gerente *g1 = new Gerente(nome, cpf, codigo, contratadoem,cargahoraria, avaliacao, telefone, salario);
    try{
        g1->calcular_salariofinal();
    }
    catch(const std::exception& e){
        std::cout << "Erro ao calcular salario final: " << e.what() << std::endl;
        delete g1;
    }
    std::cout<< "GERENTE CONTRATADO COM SUCESSO!" << std::endl;
    delete g1;
}

void Dono::avaliar_gerente(){
    std::string cpf_gerente;
    double avaliacao;
    std::cout<< "==========================================================" << std::endl;
    std::cout<< "PREENCHA O FORMULÁRIO ABAIXO PARA A AVALIAÇÃO DO GERENTE" << std::endl;
    std::cout<< "==========================================================" << std::endl;
    std::cout<< "CPF DO GERENTE: " << std::endl;
    std::cin >> cpf_gerente;
    std::cout<< "AVALIAÇÃO: " << std::endl;
    std::cin >> avaliacao;

    if(avaliacao > 10 || avaliacao < 0){
        throw std::invalid_argument("Avaliação deve ser um valor entre 0 e 10");
    } else{
        try{
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        std::string query = "UPDATE core_funcionario SET avaliacao = "+ std::to_string(avaliacao) +" WHERE cpf = "+ cpf_gerente;
        std::cout << query << std::endl;

        rc = sqlite3_open("./db.sqlite3", &db);
        std::cout << "Ok!\n";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument("Erro atualizar avaliação de gerente no banco de dados");
        }
        else
        {
            sqlite3_close(db);
            std::cout << "Avaliação de gerente cadastrada com sucesso!" << std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: " << e.what() <<std::endl;
    }
    }
    
}

std::string Dono::get_nome(){
    return this->_nome;
}

int Dono::get_codigo(){
    return this->_codigo;
}
