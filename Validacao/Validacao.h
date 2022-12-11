#ifndef VALIDACAO_H
#define VALIDACAO_H

#include <string>
class Validacao {
    public:
        bool validarData(std::string data);
        bool validarCPF(std::string cpf);
        bool validarTelefone(std::string telefone);
        bool validarNome(std::string nome);
};

#endif