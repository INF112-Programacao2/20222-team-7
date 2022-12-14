#ifndef PEDIDO_H
#define PEDIDO_H

#include "../Cliente/Cliente.h"
#include "../Item/Item.h"
#include "../Garcom/Garcom.h"
#include <string>
#include <algorithm>

class Cliente;

class Pedido{
    private:
        Cliente _cliente;
        double _preco;
        std::vector <int> _lista_itens;
        int _mesa;
        int _codigo;
        std::string _forma_pagamento;
        std::string _descricao;
        static int _qtd_pedidos;

    public:
        Pedido(Cliente& cliente, std::vector <int> lista_itens, int mesa, int forma_pag, std::string descricao);
        double get_preco();
        int get_mesa();
        std::string get_forma_pagamento();
        std::string get_descricao();
        int get_codigo();
        double get_tempo_espera();
        ~Pedido();
};

#endif
