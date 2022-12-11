#include <iostream>
#include <string>
#include "Cliente.h"
#include "../Pedido/Pedido.h"

Cliente::Cliente(){

}

Cliente::~Cliente(){
}

Cliente::Cliente(std::string nome, int codigo, int mesa){
    this->_nome = nome;
    this->_codigo = codigo;
    this->_mesa = mesa;
}

std::string Cliente::get_nome(){
    return this->_nome;
}

int Cliente::get_codigo(){
    return this->_codigo;
}

int Cliente::get_mesa(){
    return this->_mesa;
}

void Cliente::fazer_pedido(){
    // O código abaixo é responsável por gecuperar os dados de pedido do usuário e criar um objeto do tipo Pedido
    // de forma dinâmica. O objeto é criado e logo em seguida é destruído, pois não há necessidade de armazená-lo, dado que
    // suas informações serão salvas no banco de dados.
    std::vector <int> lista_itens;
    int mesa;
    int forma_pag; 
    std::string descricao;
    std::cout << "===================================================" << std::endl;
    std::cout << "RESPONDA AO FORMULÁRIO ABAIXO PARA FAZER SEU PEDIDO" << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << "MESA Nº: ";
    std::cin >> mesa;
    std::cout << "FORMA DE PAGAMENTO: [1 - Cartão de crédito] [2 - PIX] [3 - Dinheiro à vista]" << std::endl;
    std::cin >> forma_pag;
    while (forma_pag < 1 || forma_pag > 3){
        std::cout << "FORMA DE PAGAMENTO INVÁLIDA. TENTE NOVAMENTE." << std::endl;
        std::cin >> forma_pag;
    }
    std::cout << "DESCRIÇÃO DO PEDIDO: ";
    std::cin.ignore();
    std::getline(std::cin, descricao);
    std::cout << "ITENS DO PEDIDO: " << std::endl;
    std::cout << "Digite o id do item e pressione ENTER. Para finalizar o pedido, digite -1 e pressione ENTER." << std::endl;
    int codigo_item;
    std::cin >> codigo_item;
    while (codigo_item != -1){
        lista_itens.push_back(codigo_item);
        std::cin >> codigo_item;
    }

    Pedido *p1 = new Pedido(*this, lista_itens, mesa, forma_pag-1, descricao);

    delete p1;
}

void Cliente::avaliar_restaurante(Restaurante &rest, double avaliacao){
    // Esse método recebe um objeto do tipo Restaurante e uma avaliação, e seta a avaliação do restaurante
    rest.set_avaliacao(avaliacao);
}
