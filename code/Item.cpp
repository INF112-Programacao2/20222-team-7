#include <iostream>
#include <string>
#include "Item.h"


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