#ifndef GARCOM_H
#define GARCOM_H

#include "../Funcionario/Funcionario.h"

// Garçom é um funcionário que pode ver os pedidos e finalizá-los
// por isso, aqui usamos o conceito de HERANÇA, já que mantém os atributos e métodos da classe pai
class Garcom : public Funcionario {
    public:
        Garcom();
        Garcom(std::string nome, std::string cpf, int codigo, std::string contratadoem, int cargahoraria, int avaliacao, std::string telefone, double salario);
        virtual void calcular_salariofinal() override; // Polimorfismo
        void verPedidos();
        void finalizarPedido();
        ~Garcom();
};

#endif
