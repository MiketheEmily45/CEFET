#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Pessoa {
    protected:
    int idade;
    public:
    Pessoa() {
        idade = (18 + (rand()) % 23);
    }
    int getidade() {
        return idade;
    }
    void setidade(int idade) {
        if (idade >= 18 && idade <= 40){
            this->idade = idade;
        } else {
            cerr << "ERRO: idade inválida" << endl;
        }
    }

    Pessoa(int idade) {
        setidade(idade);
    }
};

class Jogador : public Pessoa {
    protected:
    char posicao;
    int forca;
    public:
    Jogador() {
        Pessoa();
        posicao = 'A';
        forca = 100 - (3 * abs(idade - 21));
    }
    char getposicao() {
        return posicao;
    }
    void setposicao(char posicao) {
        if (posicao == 'A' || posicao == 'M' || posicao == 'D'){
            this->posicao = posicao;
        } else {
            cerr << "ERRO: posição inválida" << endl;
        }
    }
    int getforca() {
        return forca;
    }
    void setforca(int forca) {
        this->forca = forca;
    }
    Jogador(char posicao, int forca) {
        Pessoa();
        setposicao(posicao);
        setforca(forca);
    }
};

class Time {
    string nome;
    int divisao;
    Jogador Jogadores[11];
};

int main() {
    srand(time(NULL));


    return 0;
}