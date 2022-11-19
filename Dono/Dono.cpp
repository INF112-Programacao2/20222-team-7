#include <iostream>
#include <string>
#include "Dono.h"

Dono::Dono(int codigo, std::string nome){
    this->_codigo = codigo;
    this->_nome = nome;
}

void Dono::definir_salario(Funcionario &aux)
{
//A desenvolver...
}

void Dono::demitir_gerente()
{
//A desenvolver...
}

Gerente Dono::contratar_gerente(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario){
    Gerente g1 = Gerente(nome, codigo, contratadoem,cargahoraria, avaliacao, telefone, salario);
    return g1;

}

void Dono::avaliar_gerente(Gerente &gerente, double avaliacao){
    if(avaliacao > 10 || avaliacao < 0){
        throw std::invalid_argument("Avaliacao deve ser um valor entrew 0 e 10");
    } else{
        gerente.set_avaliacao(avaliacao);
    }
    
}
