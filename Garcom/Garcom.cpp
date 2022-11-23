#include "Garcom.h"
#include <iostream>

Garcom::Garcom(std::string nome, std::string cpf,int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario):
    Funcionario(nome, cpf, codigo,contratadoem,cargahoraria,avaliacao,telefone, salario, "G2"){};


void Garcom::calcular_salariofinal(){
    if(_carga_horaria <= 8){
        _salariofinal = _salariominimo;
    } else{
        _horaextra = 8 - _carga_horaria;
        _salariofinal = _salariominimo + 5.5 * (_horaextra);         
    };

}

void Garcom::verPedidos(){
    std::cout<< "Visualizando pedidos" << std::endl;
}

void Garcom::finalizarPedidos(){
    std::cout<< "Finalizando pedidos" << std::endl;
}
Garcom::~Garcom(){
    std::cout<< "Garcom destruido" << std::endl;
}


