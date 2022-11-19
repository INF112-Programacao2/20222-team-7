#ifndef FUNCIO_H
#define FUNCIO_H

#include <string>

class Funcionario
{
    private:
        std::string _nome;
        int _codigo;
        std::string _data_contrato;
        double _salariominimo;          //salario minimo = 1200.00
        double _salariofinal;
        int _carga_horaria;
        int _avaliacao;
        std::string _telefone;
        int _horaextra;

    public:
        Funcionario(std::string nome, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario);
        ~Funcionario();
        std::string get_nome();
        int get_codigo();
        std::string get_data_contrato();
        double get_salariofinal();
        int get_avaliacao();
        void set_avaliacao(double avaliacao);
        std::string get_telefone();
        int get_horaextra();

        virtual void calcular_salariofinal();
};

#endif
