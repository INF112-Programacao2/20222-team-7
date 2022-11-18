#include <iostream>
#include <string>
#include "Restaurante.h"
#include "Pedido.h"
#include "Cliente.h"


Cliente::Cliente(std::string nome, std::string cpf, int mesa){
    this->_nome = nome;
    this->_cpf = cpf;
    this->_mesa = mesa;
}

std::string Cliente::get_nome()
{
    return this->_nome;
}

std::string Cliente::get_cpf()
{
    return this->_cpf;
}

int Cliente::get_mesa()
{
    return this->_mesa;
}

void Cliente::fazer_pedido(vector <Item> lista_itens, std::string forma_pag, std::string descricao)
{   
    Pedido pedido(this, lista_itens, this->_mesa, forma_pag, descricao);
}

void Cliente::avaliar_restaurante(Restaurante rest, double avaliacao)
{
    rest.set_avaliacao(avaliacao);
}

void Cliente::fazer_pedido()
{
//A desenvolver...
}

int Cliente::soma()
{
//A desenvolver...
}

int Cliente::avaliar_restaurante()
{
//A desenvolver...
}