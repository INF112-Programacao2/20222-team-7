#ifndef GARCOM_H
#define GARCOM_H

#include "Funcionario.h"

class Garcom : public Funcionario {
    private:
        void verPedidos();
        void finalizarPedidos();
    public:
        Garcom(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario);
        virtual void calcular_salariofinal() override;


};

#endif
