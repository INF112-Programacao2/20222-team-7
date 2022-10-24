#include <iostream>
#include <string>
#include <algorithm>
#include "Dono.h"
#include "Funcionario.h"
#include "Item.h"
#include "Restaurante.h"

Restaurante::Restaurante(Dono _dono, std::string _localizacao, std::string _nome, int _num_funcionarios, std::string _horario_funcionamento, vector <Item> _cardapio, std::string _telefone)
{
    this->_dono = _dono;
    this->_localizacao = _localizacao;
    this->_nome = _nome;
    this->_num_funcionarios - _num_funcionarios;
    this->_lista_funcionarios = 0;
    this->_horario_funcionamento = _horario_funcionamento;
    this->_cardapio = _cardapio; 
    this->_telefone = _telefone;
    _soma_avaliacao = 0;
    _n_avaliacao = 0;
}

double Restaurante::get_avaliacaomedia()
{
    return this->_avaliacaomedia;
}

Dono Restaurante::get_dono()
{
    return this->_dono;
}

std::string Restaurante::get_localizacao()
{
    return this->_localizacao;
}

std::string Restaurante::get_nome()
{
    return this->_nome;
}

int Restaurante::get_num_funcionarios()
{
    return this->_num_funcionarios;
}

std::string Restaurante::get_horario_funcionamento()
{
    return this->_horario_funcionamento;
}

std::string Restaurante::get_telefone()
{

    return this->_telefone;
}

void Restaurante::set_avaliacao(double avaliacao)
{
    _soma_avaliacao += avaliacao;
    _n_avaliacao++;
}

double Restaurante::get_avaliacaomedia()
{
    return (this->_soma_avaliacao)/(this->_n_avaliacao);
}