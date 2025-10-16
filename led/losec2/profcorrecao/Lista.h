#include <iostream>
class Lista
{
    public:
        int Num, Quant;
        Lista *elo;
        Lista** Inserir(Lista**, int, int);
        void Listar(Lista**);
        Lista* Pesquisar(Lista**, int);
        Lista** Excluir(Lista**, int);
};
