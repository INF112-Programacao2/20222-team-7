#include <iostream>
#include <string>
#include "Item.h"
#include <sqlite3.h>

Item::Item(std::string nome, std::string subtitulo, double preco, int codigo){
    _nome = nome;
    _preco = preco;
    _codigo = codigo;
    _descricao = subtitulo;

    try{
        sqlite3* db;
        char* zErrMsg = 0;
        int rc;
        std::string query = "INSERT INTO core_item (nome, preco, tempo_preparo_minutos, descricao) VALUES ('"+ _nome +"'"+ ","+ std::to_string(_preco)+",30,"+"'"+_descricao+"')";
        rc = sqlite3_open("./db.sqlite3", &db);
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument(zErrMsg);
        }
        else
        {
            sqlite3_close(db);
            if(!zErrMsg && sqlite3_changes(db) > 0)
                std::cout << "Item cadastrado com sucesso!" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }
}

void Item::ImprimeItem(){
    std::cout << _nome << " " << _descricao << "    R$" << _preco << std::endl;  
}

std::string Item::get_nome()
{
    return this->_nome;
}

double Item::get_preco()
{
    return this->_preco;
}

int Item::get_codigo()
{
    return this->_codigo;
}

double Item::get_tempo_preparo()
{
    return 30;
}

Item::~Item()
{
    
}