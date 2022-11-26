#ifndef DONO_H
#define DONO_H

#include "../Gerente/Gerente.h"
#include <string>
#include "../Funcionario/Funcionario.h"

class Dono
{
    private:
        int _codigo;
        std::string _nome;

    public:
        Dono();
        ~Dono();
        Dono(int codigo, std::string nome);
        void definir_salario();
        void demitir_gerente();
        void contratar_gerente();
        void avaliar_gerente();
        std::string get_nome();
        int get_codigo();
};

#endif
