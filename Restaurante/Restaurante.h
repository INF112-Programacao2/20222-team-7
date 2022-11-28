#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "../Dono/Dono.h"
#include "../Funcionario/Funcionario.h"
#include "../Item/Item.h"

class Restaurante
{
private:
    Dono _dono;
    std::string _localizacao;
    std::string _nome;
    int _num_funcionarios;
    std::string _horario_funcionamento;
    std::string _telefone;
    double _soma_avaliacao;
    int _n_avaliacao;

public:
    Restaurante(Dono &_dono, std::string _localizacao, std::string _nome, int _num_funcionarios, std::string _horario_funcionamento, std::string _telefone);

    std::string get_nome_dono();
    std::string get_localizacao();
    std::string get_nome();
    std::string get_horario_funcionamento();
    std::string get_telefone();
    void mostrar_cardapio();
    void set_avaliacao(double avaliacao);
    double get_avaliacaomedia();
    ~Restaurante();
};

#endif
