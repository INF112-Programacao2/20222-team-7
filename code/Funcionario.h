#include <string>

class Funcionario
{
    private:
        std::string _nome;
        int _codigo;
        std::string _data_contrato;
        double _salario;
        double _carga_horaria;
        int _avaliacao;
        std::string _telefone;

    public:
        std::string get_nome();
        int get_codigo();
        std::string get_data_contrato();
        double get_salario();
        int get_avaliacao();
        std::string get_telefone();

        double calcular_salario();
};