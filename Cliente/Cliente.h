#ifndef CLIENTE_H
#define CLIENTE_H

#include "Restaurante.h"
#include "Pedido.h"
#include <string>
#include <vector>

class Cliente
{
    protected:
        std::string _nome;
        int _codigo;
        int _mesa;

    public:
        Cliente(std::string nome, int codigo, int mesa);            // construtor
        std::string get_nome(); //Gets
        int get_codigo();
        int get_mesa();
        Pedido fazer_pedido(std::vector <Item> lista_itens, std::string forma_pag, std::string descricao);
        void avaliar_restaurante(Restaurante &rest, double avaliacao);
         
};

#endif
