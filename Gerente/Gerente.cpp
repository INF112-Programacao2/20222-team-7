#include <iostream>
#include "Gerente.h"
#include "Funcionario.h"


Gerente::Gerente(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone){
    _nome = nome;
    _codigo = codigo;
    _data_contrato = contratadoem;
    _carga_horaria = cargahoraria;
    _avaliacao = avaliacao;
    _telefone = telefone;
    _salariominimo = 1600.00
    _horaextra = 0;

}

Gerente::~Gerente(){

}
int Gerente::avaliar_funcionario()
{
//A desenvolver...
}
void Garcom::calcular_salariofinal(){
    if(_carga_horaria <= 8){
        _salariofinal = _salariominimo;
    } else{
        _horaextra = 8 - _carga_horaria;
        _salariofinal = _salariominimo + 7.5 * (_horaextra);            //7.5 o valor da hora extra do salario minimo
    }
}


void Gerente::demitir_funcionario()
{
//A desenvolver...
}

void Gerente::contratar_funcionario()
{
//A desenvolver...
}
