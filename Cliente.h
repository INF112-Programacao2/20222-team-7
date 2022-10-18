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
        std::string get_nome(); //Gets
        int get_codigo();
        int get_mesa();

        void fazer_pedido();
        int soma();
        int avaliar_restaurante();
         
};