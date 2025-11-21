#include <iostream>
#include "Clientes.h"

using namespace std;

int main()
{
    string nome;
    int id, pont, ano, op, minimo, total;
    Clientes A, D, **AP, **DP;
    AP = new Clientes*[2];
    DP = new Clientes*[2];
    AP[0] = AP[1] = NULL;
    DP[0] = DP[1] = NULL;
    cout << "Seja bem-vindo!" << endl;
    do {
        cout << "Opções:\n1-Inserir\n2-Remover por condição\n3-Atualizar pontuação\n4-Exibir lista de todos os clientes\n5-Exibir o total de clientes\n6-Sair" << endl;
        cin >> op;
        switch (op){
            case 1:
                cout << "Insira o nome:" << endl;
                cin >> nome;
                cout << "Insira o ano:" << endl;
                cin >> ano;
                cout << "Insira a pontuação:" << endl;
                cin >> pont;
                cout << "Insira o id:" << endl;
                cin >> id;
                if (ano < 2000) {
                    AP = A.Inserir(AP, id, nome, ano, pont);
                } else {
                    DP = D.Inserir(DP, id, nome, ano, pont);
                }
                cout << "Cliente inserido com sucesso!" << endl;
                break;
            case 2:
                cout << "Insira a condição (número mínimo para permanencia):" << endl;
                cin >> minimo;
                AP = A.Exclusao(AP, minimo);
                DP = D.Exclusao(DP, minimo);
                cout << "Clientes excluídos com sucesso!" << endl;
                break;
            case 3:
                cout << "Insira o nome:" << endl;
                cin >> nome;
                cout << "Insira o ano:" << endl;
                cin >> ano;
                cout << "Insira a pontuação nova:" << endl;
                cin >> pont;
                AP = A.Atualizar(AP, nome, ano, pont);
                DP = D.Atualizar(AP, nome, ano, pont);
                break;
            case 4:
                A.Exibir(AP);
                D.Exibir(DP);
                break;
            case 5:
                total = A.Contar(AP) + D.Contar(DP);
                cout << "O total de clientes é: " << total << endl;
                break;
            case 6:
                cout << "Tchau!" << endl;
                break;
            default:
                cout << "Erro: opção inválida" << endl;
                break;
        }
    } while (op != 6);
    return 0;
}
