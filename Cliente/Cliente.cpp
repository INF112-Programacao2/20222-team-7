#include <iostream>
#include <string>
#include "Restaurante.h"
#include "Pedido.h"
#include "Cliente.h"


Cliente::Cliente(std::string nome, int codigo, int mesa){
    _nome = nome;
    _codigo = codigo;
    _mesa = mesa;
}

std::string Cliente::get_nome()
{
    return _nome;
}

int Cliente::get_codigo()
{
    return _codigo;
}

int Cliente::get_mesa()
{
    return _mesa;
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