#include <iostream>
#include "Gerente.h"
#include "Funcionario.h"
#include <stdexcept>
#include "Garcom.h"

Gerente::Gerente(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario):
    Funcionario(nome,codigo,contratadoem,cargahoraria,avaliacao,telefone, salario){};

Gerente::~Gerente(){

}
int Gerente::avaliar_garcom(Garcom &garcom, double avaliacao){
    if(avaliacao > 10 || avaliacao < 0){
        throw std::invalid_argument("Avaliacao deve ser um valor entrew 0 e 10");
    } else{
    garcom.set_avaliacao(avaliacao);
    }
}

void Funcionario::calcular_salariofinal(){
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
}

Garcom Gerente::contratar_garcom(){

}
