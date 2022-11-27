#include <iostream>
#include <string>
#include <algorithm>
#include "Pedido.h"

int Pedido::_qtd_pedidos=0;


Pedido::Pedido(Cliente& cliente, std::vector <Item> lista_itens, int mesa, std::string forma_pag, std::string descricao){
    _qtd_pedidos++;
    this->_cliente = cliente;
    this->_lista_itens = lista_itens;
    this->_mesa = mesa;
    this->_forma_pagamento = forma_pag;
    this->_descricao = descricao;
    this->_preco = 0;
    for(int i=0; i<lista_itens.size(); i++)
        this->_preco+=lista_itens[i].get_preco();

}
double Pedido::get_preco()
{
    return this->_preco;
}

    
int Pedido::get_mesa(){
    return this->_mesa;
}

std::string Pedido::get_forma_pagamento(){
    return this->_forma_pagamento;
}

int Pedido::get_codigo(){
    return this->_codigo;
}

std::string Pedido::get_descricao(){

    return this->_descricao;
}

double Pedido::get_tempo_espera(){
    return _qtd_pedidos*30;

}

Pedido::~Pedido(){
    
}