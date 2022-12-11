#include <iostream>
#include <string>
#include <algorithm>
#include "Pedido.h"
#include <sqlite3.h>

int Pedido::_qtd_pedidos=0;


Pedido::Pedido(Cliente& cliente, std::vector <int> lista_itens, int mesa, int forma_pag, std::string descricao){
    _qtd_pedidos++;
    this->_cliente = cliente;
    this->_lista_itens = lista_itens;
    this->_mesa = mesa;
    this->_forma_pagamento = forma_pag;
    this->_descricao = descricao;
    this->_preco = 0;
    
    try{
        sqlite3 *db;
        int rc;
        char* msg_erro;
        rc = sqlite3_open("./db.sqlite3", &db);

        std::string query = "SELECT preco FROM core_item WHERE id = ";
        // for(int i=0; i<lista_itens.size(); i++){
        //     std::string query_aux = query + std::to_string(lista_itens[i]);
        //     sqlite3_stmt *stmt;
        //     rc = sqlite3_prepare_v2(db, query_aux.c_str(), -1, &stmt, NULL);
        //     if (rc != SQLITE_OK)
        //     {
        //         sqlite3_close(db);
        //         throw std::invalid_argument("Não foi possível calcular o preço total do pedido");
        //     }
        //     else
        //     {
        //         rc = sqlite3_step(stmt);
        //         if (rc == SQLITE_ROW)
        //         {
        //             this->_preco += sqlite3_column_double(stmt, 0);
        //         }
        //         else
        //         {   
        //             sqlite3_close(db);
        //             throw std::invalid_argument("Não foi possível calcular o preço total do pedido");
        //         }
        //     }
        // }
        this->_preco = 0;
        query = "INSERT INTO core_pedido (cliente_id, mesa, forma_pagamento, descricao) VALUES ("+std::to_string(cliente.get_codigo())+", "+std::to_string(mesa)+", "+std::to_string(forma_pag)+", '"+descricao+"' )";
        rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(db);
            throw std::invalid_argument(msg_erro);
        }
        else
        {
            if(!msg_erro && sqlite3_changes(db) > 0)
                std::cout << "Pedido em análise !" << std::endl;
            else
                std::cout << "Não foi possível concluir alteração"<<std::endl;
        }
        int pedido_id = sqlite3_last_insert_rowid(db);
        for (int i = 0; i < lista_itens.size(); i++)
        {
            query = "INSERT INTO core_pedido_lista_itens (pedido_id, item_id) VALUES ("+std::to_string(pedido_id)+", "+std::to_string(lista_itens[i])+")";
            rc = sqlite3_exec(db, query.c_str(), NULL, NULL, &msg_erro);
            if (rc != SQLITE_OK)
            {
                sqlite3_close(db);
                throw std::invalid_argument(msg_erro);
            }
            else
            {
                continue;
            }
        }
        
        if(!msg_erro && sqlite3_changes(db)>0)
            std::cout<<"Pedido cadastrado com sucesso!"<<std::endl;
        else
            std::cout<<"Erro ao cadastrar pedido!"<<std::endl;
        
    }
    catch (std::exception &e)
    {
        std::cout << "Erro ao acessar banco de dados: "<<e.what() << std::endl;
    }

}
double Pedido::get_preco()
{
    return this->_preco;
}

    
int Pedido::get_mesa(){
    return this->_mesa;
}

std::string Pedido::get_forma_pagamento(){
    return this->_forma_pagamento;
}

int Pedido::get_codigo(){
    return this->_codigo;
}

std::string Pedido::get_descricao(){

    return this->_descricao;
}

double Pedido::get_tempo_espera(){
    return _qtd_pedidos*30;

}

Pedido::~Pedido(){

}