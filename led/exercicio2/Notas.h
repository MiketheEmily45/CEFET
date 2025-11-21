#include <iostream>

class Notas{
    public:
        int Matricula;
        float Nota;
        Notas *elo;
        Notas** Inserir(Notas**, int, float);
        Notas* Pesquisar(Notas**, int);
        void Exibir(Notas**, int);
        Notas** Excluir(Notas**, int);
};