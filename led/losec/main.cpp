#include <iostream>
#include "programas.h"

using namespace std;

int main()
{
    int opcao, tempo;
    string nome;
    programas **R, L;
    R[0] = R[1] = NULL;
    cout << "Seja bem-vindo!" << endl;
    do {
        cout<< "\nOpções:\n1-Inserir processo\n2-Exibir processos\n3-Executar processos\n4-Excluir processo\n5-Finalizar programa\n" << endl;
        cin >> opcao;
            switch (opcao) {
                case 1:
                    cout << "Insira o nome:" << endl;
                    cin >> nome;
                    cout << "Insira o tempo de processamento em segundos:" << endl;
                    cin >> tempo;
                    R = L.Inserir(R, nome, tempo);
                    break;
                case 2:
                    cout << "processos cadastrados:" << endl;
                    L.Listar(R);
                    break;
                case 3:
                    cout << "Executando processos..." << endl;
                    R = L.Executar(R);
                    cout << "Finalizado!" << endl;
                    break;
                case 4:
                    cout << "Insira o nome do processo a ser excluido:" << endl;
                    cin >> nome;
                    R = L.Excluir(R, nome);
                    break;
                case 5:
                    break;
                default:
                    cout << "Erro: Opção inválida!" << endl;
            }
    }while(opcao != 5);
        cout << "Tchau!" << endl;
    return 0;
}
