#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <string>
#include "Dono.h"
#include "Funcionario.h"
#include "Item.h"
#include <algorithm>

class Restaurante
{
    private:
        Dono _dono;
        std::string _localizacao;
        std::string _nome;
        int _num_funcionarios;
        vector <Funcionario> _lista_funcionarios;
        std::string _horario_funcionamento;
        vector <Item> _cardapio; 
        std::string _telefone;
        double _soma_avaliacao;
        int _n_avaliacao;

    public:
        Restaurante(Dono _dono, std::string _localizacao, std::string _nome, int _num_funcionarios, std::string _horario_funcionamento, vector <Item> _cardapio, std::string _telefone);
        
        double get_avaliacaomedia();
        Dono get_dono();                //Esse get talvez possa ser apagado
        std::string get_localizacao();
        std::string get_nome();
        int get_num_funcionarios();
        std::string get_horario_funcionamento(); 
        std::string get_telefone();
        void set_avaliacao(double avaliacao);
        double get_avaliacaomedia();
        
};

#endif