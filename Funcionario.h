#include <string>

class Funcionario
{
    protected:
        std::string _nome;
        int _codigo;
        std::string _data_contrato;
        double _salario;
        double _carga_horaria;
        int _avaliacao;
        std::string _telefone;

    public:
        double calcular_salario();
};