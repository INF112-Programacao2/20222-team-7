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

double Item::get_tempo_preparo()
{

    return this->_tempo_preparo;
}

int Item::get_codigo()
{
    return this->_codigo;
}

void passargorjeta(){
    _gorjetatotaldomes += 0.1 * _preco;
}
