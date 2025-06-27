#include <string>
#ifndef PALAVRA_H
#define PALAVRA_H


class Palavra {
    private:
        std::string palavra;
    public:
        Palavra(std::string);
        Palavra();
        void Exibir(bool&, int&, char[]);
        std::string getPalavra();
        void setPalavra(std::string);

};
#endif // PALAVRA_H
