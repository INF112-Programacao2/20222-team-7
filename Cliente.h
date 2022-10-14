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
        void fazer_pedido();


        int soma;
        int avaliar_restaurante();
         
};