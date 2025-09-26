#include <iostream>

class programas
{
    public:
        std::string nome;
        int bytes;
        programas *proximo;
        programas *anterior;
        programas** Inserir(programas**, std::string, int);
        programas** Excluir(programas**, std::string);
        void Listar(programas*);
        programas* Pesquisar(programas*, std::string);
        int Bytes(programas*);
};
