#include <iostream>
using namespace std;

    class operacional {
    private:
        int vetor;
        int valores[10];
    public:
    operacional() {
        vetor = 0;
        }
    int getter(int i){
        return valores[i];
        }
    void adicionarvalores(int numero){
            valores[vetor] = numero;
            vetor++;
        }
    void somaeproduto(int num1, int num2, int &produto, int &soma) {
            soma = num1 +  num2;
            produto = num2 * num1;
        }
    void imprimir(int qtd){
        for (int i = 0; i < qtd; i++){
            cout << valores[i] << " ";
            }
    cout << endl;
        }
    };

int main() {
    int qtd, l, pos1, pos2, soma, produto;
    cout << "Insira quantos valores você quer armazenar:"<< endl;
    cin >> qtd;
    if (qtd > 10 || qtd < 1){
        cerr << "Erro: valor inválido" << endl;
        return 0;
        }
    operacional c0;
    for (int i = 0;i < qtd;i++){
        cout << "Insira o numero: " << endl;
        cin >> l;
        c0.adicionarvalores(l); 
       
    }
    c0.imprimir(qtd);
    cout << "Escolha dois valores de 1 a 10 na ordem em que se mostrou: " << endl;
    cin >> pos1;
    if (pos1 < 1 || pos1 < qtd) {
        cerr << "Erro: valor inválido" << endl;
        return 0;
    }
    cin >> pos2;
    if (pos2 < 1 || pos2 < qtd) {
        cerr << "Erro: valor inválido" << endl;
        return 0;
    }
    c0.somaeproduto(c0.getter(pos1 - 1), c0.getter(pos2 - 1), produto, soma);
    cout << "valor da soma é: " << soma << endl;
    cout << "valor do produto é: " << produto << endl;

    return 0;
}

