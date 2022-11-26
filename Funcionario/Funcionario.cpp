#include <iostream>
#include <string>
#include "Funcionario.h"
#include <sqlite3.h>
// apt-get install libsqlite3-dev

#include <stdexcept>

Funcionario::Funcionario(){

}

Funcionario::Funcionario(std::string nome, std::string cpf, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario, std::string cargo)
{
    this->_nome = nome;
    this->_codigo = codigo;
    this->_data_contrato = contratadoem;
    this->_carga_horaria = cargahoraria;
    this->_avaliacao = avaliacao;
    this->_telefone = telefone;
    this->_salariominimo = salario;
    this->_horaextra = 0;
    this->_cargo = cargo;
    this->_cpf = cpf;

    // Iniciar conexão com banco de dados sqlite3
    try
    {
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        std::string query = "INSERT INTO core_funcionario (nome, cpf, data_contrato, carga_horaria, avaliacao, telefone, salario, cargo, restaurante_id) VALUES ('"+ _nome +"'"+ ",'"+_cpf+"','"+_data_contrato+"'" +
        ","+std::to_string(_carga_horaria)+","+ std::to_string(_avaliacao)+",'"+telefone+"',"+ std::to_string(_salariominimo)+",'"+ _cargo+"',2)";

        //std::cout << query << std::endl;

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
            // tudo certo
            std::cout << "TUDO PRONTO PARA CONTINUAR =)" << std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }
}

std::string Funcionario::get_nome()
{
    return this->_nome;
}

int Funcionario::get_codigo()
{
    return this->_codigo;
}

void Funcionario::calcular_salariofinal()
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
}

std::string Funcionario::get_data_contrato()
{
    return this->_data_contrato;
}

double Funcionario::get_salariofinal()
{
    return this->_salariofinal;
}

int Funcionario::get_horaextra()
{
    return this->_horaextra;
}

int Funcionario::get_avaliacao()
{
    return this->_avaliacao;
}

std::string Funcionario::get_telefone()
{
    return this->_telefone;
}

std::string Funcionario::get_cpf()
{
    return this->_cpf;
}

void Funcionario::set_avaliacao(int avaliacao)
{
    this->_avaliacao = avaliacao;
}

Funcionario::~Funcionario()
{

}