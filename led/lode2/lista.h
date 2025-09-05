#include <iostream>

class lista
{
    public:
        std::string nome_do_cliente;
        char tipo_do_cliente;
        int idade;
        lista *proximo;
        lista *anterior;
        lista** Inserir(lista**, std::string, int);
        void Listar(lista*);
        lista** Excluir(lista**, char);
};
