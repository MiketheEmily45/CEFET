#include <iostream>

class programas
{
    public:
        std::string nome;
        int tempo;
        programas* proximo;
        programas** Inserir(programas**, std::string, int);
        programas** Excluir(programas**, std::string);
        programas** Executar(programas**);
        void Listar(programas**);
};
