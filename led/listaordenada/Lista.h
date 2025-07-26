#include <iostream>
class Lista
{
    public:
       std::string URL;
       int Acessos;
       Lista *elo;
       Lista** Inserir(Lista**, std::string, int);
       void Listar(Lista*);
       Lista** Excluir(Lista**, std::string);
       Lista* Procurar(Lista*, std::string);
};
