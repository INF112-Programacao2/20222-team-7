#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h"
#include "Garcom.h"

class Gerente : public Funcionario{
    public:
        int avaliar_garcom(Garcom &garcom, double avaliacao);
        void demitir_funcionario();
        Garcom contratar_garcom();
        Gerente(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario);
        ~Gerente();
        void calcular_salariofinal() override;
          
};

#endif
