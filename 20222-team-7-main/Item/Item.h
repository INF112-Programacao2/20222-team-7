#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
    private:
        std::string _nome;                  //titulo 
        std::string _descricao;             // subtitulo (acompanhamentos)
        double _preco;
        int _codigo;

    public:
        Item(std::string nome, std::string subtitulo, double preco, int codigo);         //construtor
        ~Item();
        void ImprimeItem();
        std::string get_nome();
        double get_preco();
        double get_tempo_preparo();
        int get_codigo();
};

#endif