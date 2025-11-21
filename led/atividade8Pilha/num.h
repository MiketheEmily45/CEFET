#include <iostream>

class num
{
    private:

        int numero;
        num *elo;

    public:

        num* InserirPilha(num*, int);
        void PercorrerPilha (num*);
        num* RemoverPilha(num*);
        num* EsvaziarPilha(num*);
        int Somar(num*);
};
