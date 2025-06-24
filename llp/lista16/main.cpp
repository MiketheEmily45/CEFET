#include <iostream>
#include <cmath>
using namespace std;

class retangulo {
    private:

    double base;
    double altura;

    public: 

    retangulo(){
        base = 0.0;
        altura = 0.0;
    }
    double getBase() {
        return base;
    }
    void setBase(double base){
        this-> base = base;
    }
    double getAltura() {
        return altura;
    }
    void setAltura (double altura){
        this->altura = altura;
    }
    retangulo(int base, int altura){
        setBase(base);
        setAltura(altura);
    }
    double area() {
        return base * altura;
    }
};



class esfera {
    private:

    double raio;

    public:

    esfera(){
        raio = 0.0;
    }
    double getRaio() {
        return raio;
    }
    void setRaio(int raio) {
        this->raio = raio;
    }
    esfera(int raio){
        setRaio(raio);
    }
    double volume(){
        return (3.0 / 4.0) * 3.14 * pow(raio, 3);
    }
};

int main() {
    int opcao;
    double base , altura, raio ;
    retangulo *ptrR = new retangulo;
    esfera *ptrE = new esfera;
    do {
        cout << "Insira uma das 3 opções:\n(1)-área retângulo\n(2)-Volume esfera\n(3)-sair" << endl;
        cin >> opcao;
        switch (opcao)
        {
        case 1: 
            cout << "insira a base" << endl;
            cin >> base;
            cout << "insira a altura" << endl;
            cin >> altura;
            ptrR->setBase(base);
            ptrR->setAltura(altura);
            cout << ptrR->area() << endl;
            break;
        case 2:
        cout << "Insira o raio:" << endl;
        cin >> raio;
        ptrE->setRaio(raio);
        cout << ptrE->volume() << endl;
            break;
        case 3:
            break;
        default:
            cerr << "Erro, opção inválida, insira novamente" << endl;
        }
    } while (opcao != 3);
    delete ptrR;
    delete ptrE;
    return 0;
}