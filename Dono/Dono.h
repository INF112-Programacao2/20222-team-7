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
        void definir_salario(Funcionario &aux);
        void demitir_gerente();
        void contratar_gerente(std::string nome, std::string cpf, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario);
        void avaliar_gerente(Gerente &gerente, double avaliacao);
        std::string get_nome();
        int get_codigo();
};

#endif
