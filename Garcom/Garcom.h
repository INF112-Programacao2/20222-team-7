#ifndef GARCOM_H
#define GARCOM_H

#include "../Funcionario/Funcionario.h"

class Garcom : public Funcionario {
    public:
        Garcom();
        Garcom(std::string nome, std::string cpf, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario);
        virtual void calcular_salariofinal() override;
        void verPedidos();
        void finalizarPedido();
        ~Garcom();
};

#endif
