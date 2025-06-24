#include <iostream>
#include <fstream>
#include "peca.h"

using namespace std;

class Peca {
    protected:
    int cor;
    int valor;
    public:
    int getcor () {
        return cor;
    }
    virtual int getvalor () {
        return valor;
    }
    void setcor (int cor){
        this->cor = cor;
    }
    void setvalor(int valor){
        this->valor = valor;
    }
    virtual string descricao() {
        return "";
    }
};
class Peao : public Peca{
public:
    string descricao() {
        if (cor == CORBRANCA) {
            return "WP";
        } else {
            return "BP";
        }
    }   
    int getvalor() {
        return PECAPEAO;
    }
};
class Bispo : public Peca{
    public:
    string descricao() {
        if (cor == CORBRANCA) {
            return "WB";
        } else {
            return "BB";
        }
    }
    int getvalor() {
        return PECABISPO;
    }
};
class Cavalo : public Peca{
    public:
    string descricao() {
        if (cor == CORBRANCA) {
            return "WH";
        } else {
            return "BH";
        }
    }
    int getvalor() {
        return PECACAVALO;
    }
};
class Torre : public Peca{
    public:
    string descricao() {
        if (cor == CORBRANCA) {
            return "WR";
        } else {
            return "BR";
        }
    }
    int getvalor() {
        return PECATORRE;
    }
};
class Dama : public Peca{
    public:
    string descricao() {
        if (cor == CORBRANCA) {
            return "WQ";
        } else {
            return "BQ";
        }
    }

    int getvalor() {
        return PECADAMA;
    }
};
class Rei : public Peca{
    public:
    string descricao() {
        if (cor == CORBRANCA) {
            return "WK";
        } else {
            return "BK";
        }
    }
    int getvalor() {
        return PECAREI;
    }
};

ofstream arquivo("analise.txt");

class Tabuleiro {
    protected:
    Peca* tabuleiro[8][8];
    public:

    Tabuleiro() {
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                tabuleiro[i][j] = nullptr;
            }
        }
    }
    void setPeca(int i, int j, Peca* peca) {
        tabuleiro[i][j] = peca;
    }
    Peca* getPeca(int i, int j) {
        return tabuleiro[i][j];
    }

    void imprimirMovimentosPossiveis() {


    }
};

int main() {
    int cor;
    int tipo;
    Peca* peca = nullptr;
    Tabuleiro tabul;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << "Há alguma peça na posição [" << i << "][" << j << "]? (2, sim e é preta, 1 - sim e é branca, 0 - não): ";
            cin >> cor;

            if (cor != 0) 
        { 
                cout << "Qual o tipo da peça? (1 - peao, 2 - bispo, 3 - cavalo, 4 - torre, 5 - dama, 6 - rei): ";
                cin >> tipo;
                switch(tipo) {
                    case 1:
                        peca = new Peao();
                        break;
                    case 2:
                        peca = new Bispo();
                        break;
                    case 3:
                        peca = new Cavalo();
                        break;
                    case 4:
                        peca = new Torre();
                        break;
                    case 5:
                        peca = new Dama();
                        break;
                    case 6:
                        peca = new Rei();
                        break;
                    default:
                        cout << "Tipo de peça inválido!" << endl;
                        continue;
                }
                peca->setcor(cor);
                tabul.setPeca(i, j, peca);
            } else {
                tabul.setPeca(i, j, nullptr); 
            }
        }
    }

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (tabul.getPeca(i, j) != nullptr) {
                cout << tabul.getPeca(i, j)->descricao() << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}