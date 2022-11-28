#ifndef CLIENTE_H
#define CLIENTE_H

#include "../Restaurante/Restaurante.h"
#include <string>
#include <vector>

class Cliente
{
    private:
        std::string _nome;
        int _codigo;
        int _mesa;

    public:
        Cliente();
        ~Cliente();
        Cliente(std::string nome, int codigo, int mesa);            // construtor
        std::string get_nome(); //Gets
        int get_codigo();
        int get_mesa();
        void fazer_pedido();
        void avaliar_restaurante(Restaurante &rest, double avaliacao);
};

#endif
