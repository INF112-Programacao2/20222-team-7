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
    return _nome;
}
    
int Funcionario::get_codigo()
{
    return _codigo;
}

std::string Funcionario::get_data_contrato()
{
    return _data_contrato;
}

double Funcionario::get_salario()
{
    return _salariofixo;
}

int Funcionario::get_avaliacao()
{
    return _avaliacao;
}

std::string Funcionario::get_telefone()
{
    return _telefone;
}

double Funcionario::calcular_salario()
{
//A desenvolver...
}