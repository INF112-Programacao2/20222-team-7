#include <iostream>
#include "Gerente.h"
#include <stdexcept>
#include <sqlite3.h>
#include <cstring>
#include <string>

static int callback_garcom(void *data, int argc, char **argv, char **azColName)
{
    int i;

    for (i = 0; i < argc; i++)
    {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "   ";
    }

    std::cout << std::endl;
    return 0;
}

Gerente::Gerente()
{
}

Gerente::Gerente(std::string nome, std::string cpf, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario) : Funcionario(nome, cpf, codigo, contratadoem, cargahoraria, avaliacao, telefone, salario, "G1"){};

void Gerente::avaliar_garcom()
{
    std::string cpf_garcom;
    double avaliacao;
    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;

        rc = sqlite3_open("./db.sqlite3", &db);

        std::string query = "SELECT cpf, nome FROM core_funcionario WHERE cargo = 'G2'";
        std::cout << "LISTA DE GARÇONS: " << std::endl;

        rc = sqlite3_exec(db, query.c_str(), callback_garcom, NULL, &msg_erro);
        std::cout << "=======================================================" << std::endl;
        std::cout << "PREENCHA O FORMULÁRIO ABAIXO PARA A AVALIAÇÃO DO GARÇOM" << std::endl;
        std::cout << "=======================================================" << std::endl;
        std::cout << "CPF DO GARÇOM: " << std::endl;
        std::cin >> cpf_garcom;
        std::cout << "AVALIAÇÃO: " << std::endl;
        std::cin >> avaliacao;
        
        query = "UPDATE core_funcionario SET avaliacao = " + std::to_string(avaliacao) + " WHERE cpf = " + cpf_garcom;

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
                std::cout << "Avaliação de garçom cadastrada com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados"<< e.what() << std::endl;
    }
}

void Gerente::calcular_salariofinal()
{
    if (this->_carga_horaria <= 8)
    {
        this->_salariofinal = this->_salariominimo;
    }
    else
    {
        this->_horaextra = this->_carga_horaria - 8;
        this->_salariofinal = this->_salariominimo + 7.5 * (this->_horaextra); // 7.5 o valor da hora extra do salario minimo
    }
    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        std::string query = "UPDATE core_funcionario SET salario = " + std::to_string(this->_salariofinal) + " WHERE cpf = " + this->_cpf;

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
                std::cout << "Salário final do gerente cadastrado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados" << std::endl;
    }
}

void Gerente::demitir_garcom()
{
    std::string cpf_garcom;
    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;

        rc = sqlite3_open("./db.sqlite3", &db);
        std::string query = "SELECT cpf, nome FROM core_funcionario WHERE cargo = 'G2'";
        std::cout << "LISTA DE GARÇONS: " << std::endl;
        rc = sqlite3_exec(db, query.c_str(), callback_garcom, NULL, &msg_erro);
        std::cout << "=======================================" << std::endl;
        std::cout << "PREENCHA O CPF DO GARÇOM A SER DEMITIDO" << std::endl;
        std::cout << "=======================================" << std::endl;
        std::cout << "CPF: ";
        std::cin >> cpf_garcom;
        query = "DELETE FROM core_funcionario WHERE cpf = " + cpf_garcom;

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
                std::cout << "Funcionário demitido com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados" << std::endl;
    }
}

void Gerente::contratar_garcom()
{
    std::string nome, cpf, contratadoem, telefone;
    int codigo, cargahoraria, avaliacao;
    double salario;
    std::cout << "==========================================================" << std::endl;
    std::cout << "PREENCHA O FORMULÁRIO ABAIXO PARA CONTRATAR UM NOVO GARÇOM" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "NOME: " << std::endl;
    std::cin >> nome;
    std::cout << "CPF: " << std::endl;
    std::cin >> cpf;
    std::cout << "TELEFONE: " << std::endl;
    std::cin >> telefone;
    std::cout << "DATA DE CONTRATAÇÃO: " << std::endl;
    std::cin >> contratadoem;
    std::cout << "CARGA HORÁRIA: " << std::endl;
    std::cin >> cargahoraria;
    std::cout << "AVALIAÇÃO INICIAL: " << std::endl;
    std::cin >> avaliacao;
    std::cout << "CÓDIGO IDENTIFICADOR: " << std::endl;
    std::cin >> codigo;
    std::cout << "SALÁRIO: " << std::endl;
    std::cin >> salario;

    Garcom *garcom = new Garcom(nome, cpf, codigo, contratadoem, cargahoraria, avaliacao, telefone, salario);
    garcom->calcular_salariofinal();

    delete garcom;
}

Gerente::~Gerente()
{
}
