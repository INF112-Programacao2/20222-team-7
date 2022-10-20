#include <string>
#include "Item.h"
#include "Pedido.h"

class Lista_de_espera
{
    private:
        vector <Pedido> lista_pedidos;

    public:
        double calcula_tempo_espera();
        
};