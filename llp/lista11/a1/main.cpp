#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14;

double retangulo (double base, double altura){
    return base * altura;
}

double esfera (double raio){
    return (raio * raio * raio) * PI * (4.0/3.0);
}

int main(){
    double opcao, base, altura, raio;
   
    cout << "Bem-vindo!" << endl;
    cout << "Escolha:" << endl;
    cout << "(1) área retângulo" << endl;
    cout << "(2) volume esfera" << endl;
    cin >> opcao;

    if (opcao == 1)
    {
        cout << "insira a base:" << endl;
        cin >> base;
        cout << "insira a altura:" << endl;
        cin >> altura;
        cout << "a área é: " << retangulo(base, altura) << endl;
    } else if (opcao == 2) {
        cout << "insira o raio:" << endl;
        cin >> raio;
        cout << "o volume é: " << esfera(raio) << endl;
    } else {
        cout << "ERRO: a opcao não é válida" << endl;
    }

    return 0;
}