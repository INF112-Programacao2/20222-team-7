#include <iostream>
#include <string>
#include "Dono.h"
#include <sqlite3.h>
#include <iomanip>
#include "../Validacao/Validacao.h"
#include <boost/algorithm/string.hpp>

static int callback_gerente(void *data, int argc, char **argv, char **azColName)
{
    int i;

    for (i = 0; i < argc; i++)
    {
        std::cout<<std::setw(5) << boost::to_upper_copy<std::string>(std::string(azColName[i])) << " = " << (argv[i] ? argv[i] : "NULL") << "   ";
    }

    std::cout << std::endl;
    return 0;
}

Dono::Dono()
{
}

Dono::~Dono()
{
}

Dono::Dono(int codigo, std::string nome)
{
    this->_codigo = codigo;
    this->_nome = nome;
}

void Dono::definir_salario()
{
    Validacao *validador = new Validacao();
    std::string cpf_funcionario;
    double salario;

    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_open("./db.sqlite3", &db);
        std::string query = "SELECT cpf, nome, cargo FROM core_funcionario";
        std::cout << "LISTA DE FUNCIONÁRIOS: " << std::endl;
        rc = sqlite3_exec(db, query.c_str(), callback_gerente, NULL, &msg_erro);
        std::cout << "============================================================" << std::endl;
        std::cout << "PREENCHA OS DADOS DO FUNCIONÁRIO QUE TERÁ O SALÁRIO DEFINIDO" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << "CPF DO FUNCIONÁRIO: \n";
        std::cin >> cpf_funcionario;
        while (!validador->validarCPF(cpf_funcionario))
        {
            std::cin >> cpf_funcionario;
        }
        std::cout << "SALÁRIO DO FUNCIONÁRIO: \n";
        std::cin >> salario;
        std::cout << "=========================================" << std::endl;
        query = "UPDATE core_funcionario SET salario = " + std::to_string(salario) + " WHERE cpf = " + cpf_funcionario;

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
                std::cout << "Salário de funcionário definido com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: " << e.what() << std::endl;
    }
    delete validador;
}

void Dono::demitir_gerente()
{
    Validacao *validador = new Validacao();
    std::string cpf_gerente;

    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_open("./db.sqlite3", &db);
        std::string query = "SELECT cpf, nome FROM core_funcionario WHERE cargo = 'G1'";
        std::cout << "LISTA DE GERENTES: " << std::endl;
        rc = sqlite3_exec(db, query.c_str(), callback_gerente, NULL, &msg_erro);
        std::cout << "========================================" << std::endl;
        std::cout << "PREENCHA O CPF DO GERENTE A SER DEMITIDO" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "CPF: ";
        std::cin >> cpf_gerente;
        while (!validador->validarCPF(cpf_gerente))
        {
            std::cin >> cpf_gerente;
        }
        query = "DELETE FROM core_funcionario WHERE cpf = " + cpf_gerente;

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
        std::cout << "Erro ao acessar banco de dados"<<e.what() << std::endl;
    }
    delete validador;
}

void Dono::contratar_gerente()
{
    Validacao *validador = new Validacao();
    std::string nome, cpf, contratadoem, telefone;
    int codigo, cargahoraria, avaliacao;
    double salario;
    std::cout << "==========================================================" << std::endl;
    std::cout << "PREENCHA O FORMULÁRIO ABAIXO PARA A CONTRATAÇÃO DO GERENTE" << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "NOME: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, nome);
    while (!validador->validarNome(nome))
    {
        std::getline(std::cin, nome);
    }
    std::cout << "CPF: " << std::endl;
    std::cin >> cpf;
    while (!validador->validarCPF(cpf))
    {
        std::cin >> cpf;
    }
    std::cout << "TELEFONE: " << std::endl;
    std::cin >> telefone;
    while (!validador->validarTelefone(telefone))
    {
        std::cin >> telefone;
    }
    std::cout << "CARGA HORÁRIA: " << std::endl;
    std::cin >> cargahoraria;
    std::cout << "AVALIAÇÃO INICIAL: " << std::endl;
    std::cin >> avaliacao;
    std::cout << "SALÁRIO: " << std::endl;
    std::cin >> salario;
    std::cout << "DATA DE CONTRATAÇÃO (AAAA-MM-DD): " << std::endl;
    std::cin >> contratadoem;
    while (!validador->validarData(contratadoem))
    {
        std::cin >> contratadoem;
    }
    std::cout << "CÓDIGO IDENTIFICADOR: " << std::endl;
    std::cin >> codigo;
    
    Gerente *g1;
    try
    {
        g1 = new Gerente(nome, cpf, codigo, contratadoem, cargahoraria, avaliacao, telefone, salario);
        g1->calcular_salariofinal();
    }
    catch (const std::exception &e)
    {
        std::cout << "Erro no registro do Gerente: " << e.what() << std::endl;
        delete g1;
    }
    delete g1;
    delete validador;
}

void Dono::avaliar_gerente()
{
    Validacao *validador = new Validacao();
    std::string cpf_gerente;
    double avaliacao;

    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        rc = sqlite3_open("./db.sqlite3", &db);

        std::string query = "SELECT cpf, nome FROM core_funcionario WHERE cargo = 'G1'";
        std::cout << "LISTA DE GERENTES: " << std::endl;
        rc = sqlite3_exec(db, query.c_str(), callback_gerente, NULL, &msg_erro);
        std::cout << "==========================================================" << std::endl;
        std::cout << "PREENCHA O FORMULÁRIO ABAIXO PARA A AVALIAÇÃO DO GERENTE" << std::endl;
        std::cout << "==========================================================" << std::endl;
        std::cout << "CPF DO GERENTE: " << std::endl;
        std::cin >> cpf_gerente;
        while (!validador->validarCPF(cpf_gerente))
        {
            std::cin >> cpf_gerente;
        }
        std::cout << "AVALIAÇÃO: " << std::endl;
        std::cin >> avaliacao;
        query = "UPDATE core_funcionario SET avaliacao = " + std::to_string(avaliacao) + " WHERE cpf = " + cpf_gerente;

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
                std::cout << "Avaliação de gerente cadastrada com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: " << e.what() << std::endl;
    }
    delete validador;
}

std::string Dono::get_nome()
{
    return this->_nome;
}

int Dono::get_codigo()
{
    return this->_codigo;
}
