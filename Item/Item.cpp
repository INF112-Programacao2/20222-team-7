#include <iostream>
#include <string>
#include "Item.h"

Item::Item(std::string nome, std::string subtitulo, double preco, double tempo, int codigo){
    _nome = nome;
    _preco = preco;
    _tempo_preparo = tempo;
    _codigo = codigo;
    _descricao = subtitulo;
}

void Item::ImprimeItem(){
    std::cout << _nome << " " << _descricao << "    R$" << _preco << "\n tempo de preparo= " << _tempo_preparo << std::endl;  
}

std::string Item::get_nome()
{
    return _nome;
}

double Item::get_preco()
{
    return _preco;
}

double Item::get_tempo_preparo()
{
    return _tempo_preparo;
}

int Item::get_codigo()
{
    return _codigo;
}