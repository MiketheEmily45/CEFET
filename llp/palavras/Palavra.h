#include <string>
#ifndef PALAVRA_H
#define PALAVRA_H


class Palavra {
    private:
        std::string palavra;
    public:
        Palavra(std::string);
        void Exibir(bool&, int&, char[]);
        std::string getPalavra();

};
#endif // PALAVRA_H
