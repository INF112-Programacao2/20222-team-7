#include "Funcionario.h"
#include "Garcom.h"
#include <iostream>

Garcom::Garcom(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double gorjetatotaldomes){
    _nome = nome;
    _codigo = codigo;
    _data_contrato = contratadoem;
    _carga_horaria = cargahoraria;
    _avaliacao = avaliacao;
    _telefone = telefone;
    _salariominimo = 1200.00
    _horaextra = 0;
    _gorjetatotaldomes = gorjetatotaldomes;

}

void Funcionario::calcular_salariofinal(){
    if(_carga_horaria <= 8){
        _salariofinal = _salariominimo + _gorjetasdodia;
    } else{
        _horaextra = 8 - _carga_horaria;
        _salariofinal = _salariominimo + 5.5 * (_horaextra) + _gorjetatotaldomes;         
    }

}

void Garcom::verPedidos(){

}

void Garcom::finalizarPedidos(){
}


