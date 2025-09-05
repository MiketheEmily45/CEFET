#include <iostream>

class lista
{
    public:
        std::string nome_do_pet;
        std::string raca;
        int idade;
        int tipo;
        lista *proximo;
        lista *anterior;
        lista** Inserir(lista**, std::string, int, int, std::string);
        lista* Procurar(lista*, std::string, int);
        void Listar(lista*);
        lista** Excluir(lista**, std::string, int);
        void Listar_cachorros(lista*);
        void Listar_gatos(lista*);
};
