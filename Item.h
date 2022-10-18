#include <string>

class Item
{
    private:
        std::string _nome;
        double _preco;
        double _tempo_preparo;
        int _codigo;

    public:
        std::string get_nome();
        double get_preco();
        double get_tempo_preparo();
        int get_codigo();
};