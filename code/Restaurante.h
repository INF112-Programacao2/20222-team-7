#include <string>
#include "Dono.h"
#include "Funcionario.h"
#include "Item.h"
#include <algorithm>

class Restaurante
{
    private:
        double _avaliacaomedia;
        Dono _dono;
        std::string _localizacao;
        std::string _nome;
        int _num_funcionarios;
        vector <Funcionario> _lista_funcionarios;
        std::string _horario_funcionamento;
        vector <Item>; 
        std::string _telefone;

    public:
        double get_avaliacaomedia();
        Dono get_dono(); //Esse get talvez possa ser apagado
        std::string get_localizacao();
        std::string get_nome();
        int get_num_funcionarios();
        std::string get_horario_funcionamento(); 
        std::string get_telefone();
        
};