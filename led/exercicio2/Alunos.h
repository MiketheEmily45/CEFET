#include <iostream>

class Alunos{
    public:
        int Matricula;    
        std::string Nome;
        Alunos *elo;
        Alunos** Inserir(Alunos**, int, std::string);
        Alunos* Pesquisar(Alunos**, std::string);
        void Exibir(Alunos*);
        Alunos** Remover(Alunos**, std::string);
};