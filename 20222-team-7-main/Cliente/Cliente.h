#ifndef CLIENTE_H
#define CLIENTE_H

#include "Restaurante.h"
#include "Pedido.h"
#include <string>

class Cliente
{
    protected:
        std::string _nome;
        std::string _cpf;
        int _mesa;

    public:
        Cliente(std::string nome, int codigo, int mesa);            // construtor
        std::string get_nome(); //Gets
        std::string get_cpf();
        int get_mesa();
        Pedido fazer_pedido(vector <Item> lista_itens, std::string forma_pag, std::string descricao);
        void avaliar_restaurante(Restaurante rest, double avaliacao);
         
};

#endif