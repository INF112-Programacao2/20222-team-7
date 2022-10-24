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
<<<<<<< HEAD
    return this->_nome;
=======
    return _nome;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}
    
int Funcionario::get_codigo()
{
<<<<<<< HEAD
    return this->_codigo;
=======
    return _codigo;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

std::string Funcionario::get_data_contrato()
{
<<<<<<< HEAD
    return this->_data_contrato;
=======
    return _data_contrato;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

double Funcionario::get_salario()
{
<<<<<<< HEAD
    return this->_salariofixo;
=======
    return _salariofixo;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

int Funcionario::get_avaliacao()
{
<<<<<<< HEAD
    return this->_avaliacao;
=======
    return _avaliacao;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

std::string Funcionario::get_telefone()
{
<<<<<<< HEAD
    return this->_telefone;
=======
    return _telefone;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

double Funcionario::calcular_salario()
{
//A desenvolver...
}