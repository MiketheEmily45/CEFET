#include <iostream>
#include "losec.h"

using namespace std;

int main()
{
    srand(time(NULL));
    int op, idade;
    string nome;
    losec L, **R;
    R = new losec*[2];
    R[0] = R[1] = NULL;
    cout << "Bem-vindo!" << endl;
        do {
            cout << "1-nserir dados\n2-Listar\n3-Realizar sorteio\n4-Finalizar Programa." << endl;
            cin >> op;
            switch (op) {
                case 1:
                    cout << "Insira o nome:" << endl;
                    cin >> nome;
                    cout << "Insira a idade:" << endl;
                    cin >> idade;
                    R = L.Inserir(R, nome, idade);
                    break;
                case 2:
                    L.Listar(R);
                    break;
                case 3:
                    cout << "Insira o nome:" << endl;
                    cin >> nome;
                    R = L.Excluir(R, nome);
                    break;
                case 4:
                    cout << "Tchau!" << endl;
                    break;
                default:
                    cout << "Erro: Opção inválida!" << endl;
                    break;
            }
        } while (op != 4);
    return 0;
}
