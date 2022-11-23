#include <iostream>
#include "Gerente.h"
#include <stdexcept>

Gerente::Gerente(std::string nome, std::string cpf, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario):
    Funcionario(nome,cpf, codigo,contratadoem,cargahoraria,avaliacao,telefone, salario, "G1"){};

void Gerente::avaliar_garcom(Garcom &garcom, double avaliacao){
    if(avaliacao > 10 || avaliacao < 0){
        throw std::invalid_argument("Avaliacao deve ser um valor entrew 0 e 10");
    } else{
    garcom.set_avaliacao(avaliacao);
    }
}

void Gerente::calcular_salariofinal(){
    if(this->_carga_horaria <= 8){
        this->_salariofinal = this->_salariominimo;
    } else{
        this->_horaextra =  this->_carga_horaria - 8 ;
        this->_salariofinal = this->_salariominimo + 7.5 * (this->_horaextra);            //7.5 o valor da hora extra do salario minimo
    }
}


void Gerente::demitir_funcionario()
{
//A desenvolver...
    std::cout<< "Demitir funcionario" << std::endl;
}

void Gerente::contratar_garcom(){
//A desenvolver...
    std::cout<< "Contratar garcom" << std::endl;
}

Gerente::~Gerente(){
    std::cout<< "Gerente destruido" << std::endl;
}
