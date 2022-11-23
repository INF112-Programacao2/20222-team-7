#include <iostream>
#include <string>
#include "Item.h"

Item::Item(std::string nome, std::string subtitulo, double preco, int codigo){
    _nome = nome;
    _preco = preco;
    _codigo = codigo;
    _descricao = subtitulo;
}

void Item::ImprimeItem(){
    std::cout << _nome << " " << _descricao << "    R$" << _preco << std::endl;  
}

std::string Item::get_nome()
{
    return this->_nome;
}

double Item::get_preco()
{
    return this->_preco;
}

int Item::get_codigo()
{
    return this->_codigo;
}

double Item::get_tempo_preparo()
{
    return 30;
}

Item::~Item()
{
    std::cout << "Item destruido" << std::endl;
}