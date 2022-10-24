#include <iostream>
#include <string>
#include "Funcionario.h"

Funcionario::Funcionario(std::string nome, int codigo, std::string contratadoem, double salario, double cargahoraria, int avaliacao, std::string telefone){
    _nome = nome;
    _codigo = codigo;
    _data_contrato = contratadoem;
    _salariofixo = salario;
    _carga_horaria = cargahoraria;
    _avaliacao = avaliacao;
    _telefone = telefone;

}

Funcionario::~Funcionario(){        // destrutor
}

std::string Funcionario::get_nome()
{
    return this->_nome;
}
    
int Funcionario::get_codigo()
{
    return this->_codigo;
}

std::string Funcionario::get_data_contrato()
{
    return this->_data_contrato;
}

double Funcionario::get_salario()
{
    return this->_salariofixo;
}

int Funcionario::get_avaliacao()
{
    return this->_avaliacao;
}

std::string Funcionario::get_telefone()
{
    return this->_telefone;
}

double Funcionario::calcular_salario()
{
//A desenvolver...
}