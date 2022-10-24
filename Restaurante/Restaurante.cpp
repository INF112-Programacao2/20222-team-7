#include <iostream>
#include <string>
#include <algorithm>
#include "Dono.h"
#include "Funcionario.h"
#include "Item.h"
#include "Restaurante.h"

<<<<<<< HEAD
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
=======
double Restaurante::get_avaliacaomedia()
{
    return _avaliacaomedia;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

Dono Restaurante::get_dono()
{
<<<<<<< HEAD
    return this->_dono;
=======
    return _dono;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

std::string Restaurante::get_localizacao()
{
<<<<<<< HEAD
    return this->_localizacao;
=======
    return _localizacao;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

std::string Restaurante::get_nome()
{
<<<<<<< HEAD
    return this->_nome;
=======
    return _nome;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

int Restaurante::get_num_funcionarios()
{
<<<<<<< HEAD
    return this->_num_funcionarios;
=======
    return _num_funcionarios;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

std::string Restaurante::get_horario_funcionamento()
{
<<<<<<< HEAD
    return this->_horario_funcionamento;
=======
    return _horario_funcionamento;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}

std::string Restaurante::get_telefone()
{
<<<<<<< HEAD

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
=======
    return _telefone;
>>>>>>> 9d5f263f12945717fdfa0b6babac866bb4308fcf
}