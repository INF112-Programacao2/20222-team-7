#ifndef DONO_H
#define DONO_H

#include "Gerente.h"
#include <string>
#include "Funcionario.h"

class Dono
{
    private:
        int _codigo;
        std::string _nome;

    public:
        Dono(int codigo, std::string nome);
        void definir_salario(Funcionario &aux);
        void demitir_gerente();
        Gerente contratar_gerente(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario);
        void avaliar_gerente(Gerente &gerente, double avaliacao);

};

#endif
