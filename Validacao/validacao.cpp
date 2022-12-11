#include "Validacao.h"
#include <iostream>

bool Validacao::validarData(std::string data) {
    // 2020-10-10 exemplo de data aceita
    if (data.length() != 10) {
        std::cout << "Data inválida. Digite a data no formato AAAA-MM-DD" << std::endl;
        return false;
    }
    if (data[4] != '-' || data[7] != '-') {
        std::cout << "Data inválida. Digite a data no formato AAAA-MM-DD" << std::endl;
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (data[i] < '0' || data[i] > '9') {
            std::cout << "Data inválida. Digite a data no formato AAAA-MM-DD" << std::endl;
            return false;
        }
    }
    int ano = std::stoi(data.substr(0, 4));
    int mes = std::stoi(data.substr(5, 2));
    int dia = std::stoi(data.substr(8, 2));
    if (ano < 1900 || ano > 2022) {
        std::cout << "Data inválida. Digite um ano entre 1900 e 2022" << std::endl;
        return false;
    }
    if (mes < 1 || mes > 12) {
        std::cout << "Data inválida. Digite um mês entre 01 e 12" << std::endl;
        return false;
    }
    if (mes==2 && dia > 29) {
        std::cout << "Data inválida. Fevereiro não tem mais de 29 dias" << std::endl;
        return false;
    }
    if (dia < 1 || dia > 31) {
        std::cout << "Data inválida. Digite um dia entre 01 e 31" << std::endl;
        return false;
    }
    if ((mes==4 || mes==6 || mes==9 || mes==11) && dia > 30) {
        std::cout << "Data inválida. Este mês não tem mais de 30 dias" << std::endl;
        return false;
    }
    
    return true;
}

bool Validacao::validarCPF(std::string cpf) {
    if (cpf.length() != 11) {
        std::cout << "CPF inválido. Digite o CPF no formato 00000000000 (apenas os algarismos)" << std::endl;
        return false;
    }
    for (int i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return false;
        }
    }
    return true;
}

bool Validacao::validarTelefone(std::string telefone) {
    if (telefone.length() != 11) {
        std::cout << "Telefone inválido. Digite o telefone no formato 00000000000 (apenas os algarismos)" << std::endl;
        return false;
    }
    for (int i = 0; i < 11; i++) {
        if (telefone[i] < '0' || telefone[i] > '9') {
            std::cout << "Telefone inválido. Digite o telefone no formato 00000000000 (apenas os algarismos)" << std::endl;
            return false;
        }
    }
    return true;
}

bool Validacao::validarNome(std::string nome) {
    if (nome.length() < 3) {
        std::cout << "Nome inválido. Digite um nome com pelo menos 3 caracteres" << std::endl;
        return false;
    }
    for (int i = 0; i < nome.length(); i++) {
        if (nome[i] < 'A' || nome[i] > 'z') {
            std::cout << "Nome inválido. Digite um nome com apenas letras" << std::endl;
            return false;
        }
    }
    return true;
}

