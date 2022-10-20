#include <string>

class Funcionario
{
    private:
        std::string _nome;
        int _codigo;
        std::string _data_contrato;
        double _salariofixo;
        double _carga_horaria;
        int _avaliacao;
        std::string _telefone;

    public:
        Funcionario(std::string nome, int codigo, std::string contratadoem, double salario, double cargahoraria, int avaliacao, std::string telefone);
        ~Funcionario();
        std::string get_nome();
        int get_codigo();
        std::string get_data_contrato();
        double get_salario();
        int get_avaliacao();
        std::string get_telefone();

        double calcular_salario();
};