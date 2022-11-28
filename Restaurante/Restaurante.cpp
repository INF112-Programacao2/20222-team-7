#include <iostream>
#include <string>
#include <algorithm>
#include "Restaurante.h"
#include <sqlite3.h>

static int callback_itens(void* data, int argc, char** argv, char** azColName)
{
    int i;
    
    for (i = 0; i < argc; i++) {
        std::cout << azColName[i] <<" = "<< (argv[i] ? argv[i] : "NULL") << std::endl;  
    }
  
    std::cout <<"=============================================="<< std::endl;
    return 0;
}

Restaurante::Restaurante(Dono& _dono, std::string _localizacao, std::string _nome, int _num_funcionarios, std::string _horario_funcionamento, std::string _telefone)
{
    this->_dono = _dono;
    this->_localizacao = _localizacao;
    this->_nome = _nome;
    this->_num_funcionarios = _num_funcionarios;
    this->_horario_funcionamento = _horario_funcionamento;
    this->_telefone = _telefone;
    _soma_avaliacao = 0;
    _n_avaliacao = 0;
}

std::string Restaurante::get_nome_dono(){
    return this->_dono.get_nome();
}

std::string Restaurante::get_localizacao(){
    return this->_localizacao;
}

std::string Restaurante::get_nome(){
    return this->_nome;
}

std::string Restaurante::get_horario_funcionamento(){
    return this->_horario_funcionamento;
}

std::string Restaurante::get_telefone(){
    return this->_telefone;
}

void Restaurante::set_avaliacao(double avaliacao)
{
    _soma_avaliacao += avaliacao;
    _n_avaliacao++;
}

double Restaurante::get_avaliacaomedia(){
    return (this->_soma_avaliacao)/(this->_n_avaliacao);
}

Restaurante::~Restaurante()
{
    
}

void Restaurante::mostrar_cardapio(){
    try{
        char *msg_erro;
        sqlite3 *db;

        int rc;
        sqlite3_stmt *stmt;
        std::string query = "SELECT * FROM core_item";
        rc = sqlite3_open("./db.sqlite3", &db);
        std::cout << "==========================CARDÁPIO===========================" << std::endl;
        rc = sqlite3_exec(db, query.c_str(), callback_itens, (void*)"", &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument(msg_erro);
        }
        else
        {
            sqlite3_close(db);
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: "<< e.what() << std::endl;
    }
}
