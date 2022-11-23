#ifndef FUNCIO_H
#define FUNCIO_H

#include <string>

class Funcionario
{
    protected:
        std::string _nome;
        int _codigo;
        std::string _data_contrato;
        double _salariominimo;          //salario minimo = 1200.00
        double _salariofinal;
        int _carga_horaria;
        int _avaliacao;
        std::string _telefone;
        int _horaextra;
        std::string _cargo; // G1 para gerente ou G2 para Garçom
        std::string _cpf;

    public:
        Funcionario(std::string nome, std::string cpf ,int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario, std::string cargo);
        std::string get_nome();
        int get_codigo();
        std::string get_data_contrato();
        double get_salariofinal();
        int get_avaliacao();
        void set_avaliacao(double avaliacao);
        std::string get_telefone();
        int get_horaextra();
        std::string get_cpf();
        virtual void calcular_salariofinal();
        ~Funcionario();
};

#endif
