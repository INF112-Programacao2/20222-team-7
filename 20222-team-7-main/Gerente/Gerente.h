#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"

class Gerente : public Funcionario
{
    protected:
        int avaliar_funcionario();
        void demitir_funcionario();
        void contratar_funcionario();

    public:
        Gerente(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone);
        ~Gerente();
        void calcular_salariofinal() override;
          

};

#endif