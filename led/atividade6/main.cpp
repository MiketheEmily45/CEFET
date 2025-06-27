#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void ClonarVetor(int vet1[], int vet2[], int fim){
    for(int i = 0; i < fim; i++){
        vet2[i] = vet1[i];
    }
}

void BolhaMelhorado(int vet[], int fim) {
    int i = 1 , j, aux;
    bool troca = true;
    while ((i <= fim) && (troca)){
        troca = false ;
        for(j = 0; j < fim - 1; j++) {
            if(vet [j] > vet [j + 1]) {
                troca = true;
                aux = vet [j];
                vet[j] = vet [j + 1];
                vet[j + 1] = aux ;
            }
        }
    i ++;
    }
}

void Insertion(int vet[], int fim) {
    int i, j, eleito;
    for(i = 1; i < fim; i ++) {
        eleito = vet [i];
        j = i - 1;
        while ((j >= 0) && (vet [j] > eleito)) {
            vet [j + 1] = vet [j];
            j--;
        }
        vet [j + 1] = eleito ;
    }
}

void Selection(int vet[], int fim) {
    int i , j , eleito , menor , pos ;
    for(i = 0; i < fim - 1; i++) {
        eleito = vet [i];
        menor = vet[i + 1];
        pos = i + 1;
        for(j = i +2; j < fim ; j++) {
            if(vet [j ] < menor) {
                menor = vet[j];
                pos = j;
            }
        }
        if(menor < eleito){
            vet [i] = vet [pos];
            vet [pos] = eleito;
        }
    }
}

int main()
{
    srand(time(NULL));
    int *vet, *cop, t, ini, fim, opc;
    bool menu = true;
    char ord;
    cout << "Seja bem-vindo!" << endl;
    do {
        cout << "Escolha sua opção:\n1-Gerar vetor\n2-Ordenações\n3-finalizar" << endl;
        cin >> opc;
        switch(opc){
            case 1:
                cout << "informe o tamanho: " << endl;
                cin >> t;
                cout << "informe o inicio do intervalo de números aleatórios: " << endl;
                cin >> ini;
                cout << "informe o fim do interfavlo de números aleatórios: " << endl;
                cin >> fim;
                vet = new int[t];
                cop = new int[t];
                for(int i = 0; i < t; i++){
                    vet[i] = rand() % (fim - ini + 1) + ini;
                    cout << vet[i] << " ";
                }
                cout << endl;
                ClonarVetor(vet, cop, t);
                break;
            case 2:
                if (vet != NULL) {
                    cout << "Escolha a ordenação:\na)Apenas bolha melhorado\nb)Apenas inserção\nc)Apenas seleção\nd)Bolha melhorado e inserção\ne)Bolha melhorado e seleção\nf)Inserção e seleção\ng)Todos os métodos." << endl;
                    cin >> ord;
                    switch(ord){
                        case 'a':
                            BolhaMelhorado(cop, t);
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            break;
                        case 'b':
                            Insertion(cop, t);
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            break;
                        case 'c':
                            Selection(cop, t);
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            break;
                        case 'd':
                            BolhaMelhorado(cop, t);
                            cout << "Bolha melhorado: " << endl;
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            Insertion(cop, t);
                            cout << "Inserção: " << endl;
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            break;
                        case 'e':
                            BolhaMelhorado(cop, t);
                            cout << "Bolha melhorado: " << endl;
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            Selection(cop, t);
                            cout << "Selection: " << endl;
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            break;
                        case 'f':
                            Insertion(cop, t);
                            cout << "Inserção: " << endl;
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            Selection(cop, t);
                            cout << "Selection: " << endl;
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            break;
                        case 'g':
                            BolhaMelhorado(cop, t);
                            cout << "Bolha melhorado: " << endl;
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            Insertion(cop, t);
                            cout << "Inserção: " << endl;
                            for(int i = 0; i < t; i++){
                                cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            Selection(cop, t);
                            cout << "Seleção: " << endl;
                            for(int i = 0; i < t; i++){
                            cout << cop[i] << " ";
                            }
                            cout << endl;
                            ClonarVetor(vet, cop, t);
                            break;
                        default:
                            cout << "Erro: opção inválida." << endl;
                            break;
                    }
                } else {
                    cout << "erro, nenhum vetor criado." << endl;
                    break;
                }
                break;
            case 3:
                delete (vet);
                menu = false;
                break;
            default:
                cout << "Erro: opção inválida." << endl;
                break;
        }
    } while (menu);
    return 0;
}
