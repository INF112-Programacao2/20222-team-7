#include <iostream>
#include <string>
#include <algorithm>
#include "Restaurante.h"
#include <sqlite3.h>

// Função auxiliar para imprimir os itens do cardápio do restaurante
static int callback_itens(void* data, int argc, char** argv, char** azColName)
{
    int i;
    
    for (i = 0; i < argc; i++) {
        std::cout << azColName[i] <<" = "<< (argv[i] ? argv[i] : "NULL") << std::endl;  
    }
  
    std::cout <<"=============================================="<< std::endl;
    return 0;
}

double Restaurante::_soma_avaliacao = 0;
int Restaurante::_n_avaliacao = 1;
Restaurante::Restaurante(Dono& _dono, std::string _localizacao, std::string _nome, int _num_funcionarios, std::string _horario_funcionamento, std::string _telefone)
{
    this->_dono = _dono;
    this->_localizacao = _localizacao;
    this->_nome = _nome;
    this->_num_funcionarios = _num_funcionarios;
    this->_horario_funcionamento = _horario_funcionamento;
    this->_telefone = _telefone;
    
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

double Restaurante::get_avaliacaomedia(){
    return (this->_soma_avaliacao)/(this->_n_avaliacao);
}


void Restaurante::set_avaliacao(double avaliacao)
{
    // Esse método recebe uma avaliação do usuário e atualiza a média de avaliações do restaurante no banco de dados
    // Aqui, e em outros locais, utilizamos o conceito de ENCAPSULAMENTO, pois o usuário não tem acesso direto aos atributos da classe Restaurante
    _soma_avaliacao += avaliacao;
    _n_avaliacao++;
    double media = get_avaliacaomedia();
    try{
        char *msg_erro;
        sqlite3 *db;
        int rc;
        sqlite3_stmt *stmt;
        std::string query = "UPDATE core_restaurante SET avaliacao_media = " + std::to_string(media) + " WHERE id = 2";
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument(msg_erro);
        }
        else
        {
            std::cout << "Avaliação registrada com sucesso!" << std::endl;
            sqlite3_close(db);
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: "<< e.what() << std::endl;
    }
}


Restaurante::~Restaurante()
{
    
}

void Restaurante::mostrar_cardapio(){
    // Esse método mostra o cardápio do restaurante, buscando os itens no banco de dados
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
