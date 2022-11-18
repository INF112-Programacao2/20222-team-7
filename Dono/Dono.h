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
        void definir_salario(Funcionario &aux);
        void demitir_gerente();
        void contratar_gerente();
        void avaliar_gerente();     // se nao for ter, tem que excluir o atributo "avaliacao" do gerente

};

#endif
