#include <iostream>
#include <string>
#include <algorithm>
#include "Cliente.h"
#include "Item.h"
#include "Pedido.h"

double get_preco()
{
    return _preco;
}
    
int get_mesa()
{
    return _mesa;
}

std::string get_forma_pagamento()
{
    return _forma_pagamento;
}

int get_codigo()
{
    return _codigo;
}