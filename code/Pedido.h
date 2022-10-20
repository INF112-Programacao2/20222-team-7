#include "Cliente.h"
#include "Item.h"
#include <string>
#include <algorithm>

class Pedido
{
    private:
        std::string _nome_cliente();
        double _preco;
        vector <std::string> _lista_itens;
        int _mesa;
        std::string _forma_pagamento;
        int _codigo;

    public:
        double get_preco();
        int get_mesa();
        std::string get_forma_pagamento(); //Nao sei se esse get sera util...
        int get_codigo();
};