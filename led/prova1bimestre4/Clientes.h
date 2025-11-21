#include <iostream>

class Clientes
{
    public:
        int id;
        std::string nome;
        int ano;
        int pont;
        Clientes *prox;

        int Contar(Clientes**);
        Clientes** Inserir(Clientes**, int, std::string, int, int);
        Clientes** Excluir(Clientes**, std::string, int);
        Clientes** Exclusao(Clientes**, int);
        Clientes** Atualizar(Clientes**, std::string, int, int);
        void Exibir(Clientes**);
};
