#include "Cliente.h"
#include "Item.h"
#include <string>
#include <algorithm>

class Pedido
{
    private:
        Cliente _cliente;
        double _preco;
        vector <Item> _lista_itens;
        int _mesa;
        int _codigo;
        std::string _forma_pagamento;
        std::string _descricao;
        static int qtd_pedidos;

    public:
        Pedido(Cliente cliente, vector <Item> lista_itens, int mesa, std::string forma_pag, std::string descricao);
        double get_preco();
        int get_mesa();
        std::string get_forma_pagamento();              //Nao sei se esse get sera util...
        std::string get_descricao();
        int get_codigo();
};