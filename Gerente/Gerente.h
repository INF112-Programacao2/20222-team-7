#ifndef GERENTE_H
#define GERENTE_H

#include "../Funcionario/Funcionario.h"
#include "../Garcom/Garcom.h"

class Gerente : public Funcionario{
    public:
        Gerente();
        void avaliar_garcom();
        void demitir_garcom();
        void contratar_garcom();
        Gerente(std::string nome, std::string cpf, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario);
        virtual void calcular_salariofinal() override;
        ~Gerente();
};

#endif
