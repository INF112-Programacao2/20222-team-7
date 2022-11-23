#include <iostream>
#include <string>
#include "Dono.h"

Dono::Dono(){
    
}

Dono::~Dono(){
    std::cout<< "Dono destruido" << std::endl;
}

Dono::Dono(int codigo, std::string nome){
    this->_codigo = codigo;
    this->_nome = nome;
}

void Dono::definir_salario(Funcionario &aux)
{
//A desenvolver...
    std::cout<< "Definir salario" << std::endl;
}

void Dono::demitir_gerente()
{
//A desenvolver...
    std::cout<< "Demitir gerente" << std::endl;     
}

void Dono::contratar_gerente(std::string nome, std::string cpf,int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario){
    Gerente g1 = Gerente(nome, cpf, codigo, contratadoem,cargahoraria, avaliacao, telefone, salario);
}

void Dono::avaliar_gerente(Gerente &gerente, double avaliacao){
    if(avaliacao > 10 || avaliacao < 0){
        throw std::invalid_argument("Avaliacao deve ser um valor entrew 0 e 10");
    } else{
        gerente.set_avaliacao(avaliacao);
    }
    
}

std::string Dono::get_nome(){
    return this->_nome;
}

int Dono::get_codigo(){
    return this->_codigo;
}
