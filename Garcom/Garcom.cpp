#include "Funcionario.h"
#include "Garcom.h"
#include <iostream>

Garcom::Garcom(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario):
    Funcionario(nome,codigo,contratadoem,cargahoraria,avaliacao,telefone, salario){};


void Funcionario::calcular_salariofinal(){
    if(_carga_horaria <= 8){
        _salariofinal = _salariominimo;
    } else{
        _horaextra = 8 - _carga_horaria;
        _salariofinal = _salariominimo + 5.5 * (_horaextra);         
    };

}

void Garcom::verPedidos(){

}

void Garcom::finalizarPedidos(){
}


