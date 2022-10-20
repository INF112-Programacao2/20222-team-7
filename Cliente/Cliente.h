#include "Restaurante.h"
#include "Pedido.h"
#include <string>

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

        void fazer_pedido();
        int soma();
        int avaliar_restaurante();
         
};