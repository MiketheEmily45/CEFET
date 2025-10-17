#include <iostream>

class losec
{
    public:
        std::string nome;
        int idade;
        losec *elo;
        losec** Inserir(losec**, std::string, int);
        losec** Excluir(losec**, std::string);
        void Listar(losec**);
        void Sortear(losec**);
};
