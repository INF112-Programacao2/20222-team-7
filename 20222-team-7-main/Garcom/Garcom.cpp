#include "Funcionario.h"
#include "Garcom.h"
#include <iostream>

Garcom::Garcom(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone){
    _nome = nome;
    _codigo = codigo;
    _data_contrato = contratadoem;
    _carga_horaria = cargahoraria;
    _avaliacao = avaliacao;
    _telefone = telefone;
    _salariominimo = 1200.00
    _horaextra = 0;

}

void Garcom::verPedidos(){

}

void Garcom::finalizarPedidos(){
}


