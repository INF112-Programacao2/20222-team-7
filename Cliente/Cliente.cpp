#include <iostream>
#include <string>
#include "Restaurante.h"
#include "Pedido.h"
#include "Cliente.h"


Cliente::Cliente(std::string nome, int codigo, int mesa){
    this->_nome = nome;
    this->_codigo = codigo;
    this->_mesa = mesa;
}

std::string Cliente::get_nome(){
    return this->_nome;
}

int Cliente::get_codigo(){
    return this->_codigo;
}

int Cliente::get_mesa(){
    return this->_mesa;
}

Pedido Cliente::fazer_pedido(std::vector <Item> lista_itens, std::string forma_pag, std::string descricao){   
    return Pedido(*this, lista_itens, this->_mesa, forma_pag, descricao);
}

void Cliente::avaliar_restaurante(Restaurante &rest, double avaliacao){
    if(avaliacao > 10 || avaliacao < 0){
        throw std::invalid_argument("Avaliacao deve ser um valor entrew 0 e 10");
    }else{
        rest.set_avaliacao(avaliacao);
    }
}


