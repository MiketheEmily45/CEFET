#include <iostream>
#include <string>
#include "programas.h"

using namespace std;

int main()
{
    programas **R;
    programas *resp;
    programas M;
    int opcao, resul, bytes;
    string nome;

    cout << "Seja bem-vindo!\n" << endl;
    do {
        cout << "Opções:\n1-Inserir programa\n2-Excluir programa\n3-Listar programas\n4-Pesquisar programa\n5-Verificar quantidade\n6-Finalizar programa\n\nInsira a opção:" << endl;
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "Insira o nome: " << endl;
                cin >> nome;
                cout << "Insira o tamanho: " << endl;
                cin >> bytes;
                R = M.Inserir(R, nome, bytes);
                cout << "Inserido com sucesso!";
                break;
            case 2:
                cout << "Insira o nome: " << endl;
                cin >> nome;
                R = M.Excluir(R, nome);
                break;
            case 3:
                M.Listar(R[0]);
                break;
            case 4:
                cout << "Insira o nome: " << endl;
                cin >> nome;
                resp = M.Pesquisar(R[0], nome);
                if (resp != NULL) {
                    cout << "Programa cadastrado. Ele possui " << resp->bytes << " bytes.";
                } else {
                    cout << "Programa não cadastrado." << endl;
                }
                break;
            case 5:
                resul = M.Bytes(R[0]);
                cout << "Possui: " << resul << "bytes." << endl;
                break;
            case 6:
                break;
            default:
                cout << "Erro: Opção inválida." << endl;
                break;
        }
    } while (opcao != 6);

    cout << "\nTchau!" << endl;
    return 0;
}
