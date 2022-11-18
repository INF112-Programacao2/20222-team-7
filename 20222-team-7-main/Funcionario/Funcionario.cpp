#include <iostream>
#include <string>
#include "Funcionario.h"

Funcionario::Funcionario(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone){
    _nome = nome;
    _codigo = codigo;
    _data_contrato = contratadoem;
    _carga_horaria = cargahoraria;
    _avaliacao = avaliacao;
    _telefone = telefone;
    _salariominimo = 1200.00
    _horaextra = 0;

}

Funcionario::~Funcionario(){        // destrutor
}

std::string Funcionario::get_nome(){

    return this->_nome;
}
    
int Funcionario::get_codigo(){
    return this->_codigo;
}

std::string Funcionario::get_data_contrato(){
    return this->_data_contrato;
}

void Funcionario::calcular_salariofinal(){
    if(_carga_horaria <= 8){
        _salariofinal = _salariominimo;
    } else{
        _horaextra = 8 - _carga_horaria;
        _salariofinal = _salariominimo + 5.5 * (_horaextra);            //5.5 o valor da hora extra do salario minimo
    }

}

double Funcionario::get_salariofinal(){
    return this->_salariofinal;
}

int Funcionario::get_horaextra(){
    return this->_horaextra;
}

int Funcionario::get_avaliacao(){
    return this->_avaliacao;
}

std::string Funcionario::get_telefone(){
    return this->_telefone;
}
