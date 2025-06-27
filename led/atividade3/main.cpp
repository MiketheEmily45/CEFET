#include <iostream>

using namespace std;

void tabela(char jogo[3][3]) {
    cout << " -- -- --" << endl;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++){
            cout << "|" << jogo[i][j] << "|";
        }
        cout << "\n -- -- --" << endl;
    }
}

int main()
{
    char jogo[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char escolha, SouN;
    bool denovo, venceu1 = false, venceu2 = false, empate = false;
    int linha, coluna;
    string jogador1, jogador2;
    do {
        cout << "Insira o nome do jogador 1:" << endl;
        cin >> jogador1;
        cout << "Quer jogar de X ou O?" << endl;
        cin >> escolha;
        cout << "Insira o nome do Jogador 2:" << endl;
        cin >> jogador2;
        tabela(jogo);
        do {
                do {
                    cout << "\n" << jogador1 << " Faça sua jogada informando linha e coluna:" << endl;
                    cin >> linha >> coluna;
                } while (jogo[linha][coluna] != ' ');
                if (escolha == 'X') {
                    jogo[linha][coluna] = 'X';
                } else {
                    jogo[linha][coluna] = 'O';
                }
                tabela(jogo);
                empate = true;
                for (int i = 0; i <= 2; i++) {
                    for (int j = 0; j <= 2; j++) {
                        if (jogo[i][j] == ' ') {
                            empate = false;
                        }
                    }
                }
                if (empate) {
                    break;
                }
                if (escolha == 'X') {
                    if((jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') || (jogo[0][3] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')) {
                        venceu1 = true;
                    }
                    if((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') || (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') || (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X')) {
                        venceu1 = true;
                    }
                    if((jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') || (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') || (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X')) {
                        venceu1 = true;
                    }
                } else {
                    if((jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') || (jogo[0][3] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O')) {
                        venceu1 = true;
                    }
                    if((jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O') || (jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O') || (jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O')) {
                        venceu1 = true;
                    }
                    if((jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O') || (jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O') || (jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O')) {
                        venceu1 = true;
                    }
                }
                if (venceu1) {
                    break;
                }

                do {
                    cout << "\n" << jogador2 << " Faça sua jogada informando linha e coluna:" << endl;
                    cin >> linha >> coluna;
                } while (jogo[linha][coluna] != ' ');
                if (escolha == 'O') {
                    jogo[linha][coluna] = 'X';
                } else {
                    jogo[linha][coluna] = 'O';
                }
                tabela(jogo);
                if (escolha == 'O') {
                    if((jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') || (jogo[0][3] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')) {
                        venceu2 = true;
                    }
                    if((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') || (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') || (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X')) {
                        venceu2 = true;
                    }
                    if((jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') || (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') || (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X')) {
                        venceu2 = true;
                    }
                } else {
                    if((jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') || (jogo[0][3] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O')) {
                        venceu2 = true;
                    }
                    if((jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O') || (jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O') || (jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O')) {
                        venceu2 = true;
                    }
                    if((jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O') || (jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O') || (jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O')) {
                        venceu2 = true;
                    }
                }
                if (venceu2) {
                    break;
                }
        } while (!venceu1 && !venceu2 && !empate);

        if(empate) {
            cout << "Puts, foi empate..." << endl;
        } else if (venceu1) {
            cout << jogador1 << " venceu!!! Parabéns!";
        } else if (venceu2) {
            cout << jogador2 << " venceu!!! Parabéns!";
        }


        cout << "gostaria de jogar de novo? S/N" << endl;
        cin >> SouN;
        if (SouN == 'S' || SouN == 's') {
            denovo = true;
        } else {
            denovo = false;
        }
    } while (denovo);

    return 0;
}
