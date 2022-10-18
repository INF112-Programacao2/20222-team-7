#include <iostream>
#include <string>
#include <algorithm>
#include "Dono.h"
#include "Funcionario.h"
#include "Item.h"
#include "Restaurante.h"

double Restaurante::get_avaliacaomedia()
{
    return _avaliacaomedia;
}

Dono Restaurante::get_dono()
{
    return _dono;
}

std::string Restaurante::get_localizacao()
{
    return _localizacao;
}

std::string Restaurante::get_nome()
{
    return _nome;
}

int Restaurante::get_num_funcionarios()
{
    return _num_funcionarios;
}

std::string Restaurante::get_horario_funcionamento()
{
    return _horario_funcionamento;
}

std::string Restaurante::get_telefone()
{
    return _telefone;
}