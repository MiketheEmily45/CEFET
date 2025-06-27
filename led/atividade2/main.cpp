#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    char senhaC[4], cores[4] = {'v', 'a', 'p', 'b'};
    for (int i = 0; i <= 3; i++) {
        senhaC[i] = cores[rand() % 4];
    }
    char senhaJ[4];
    int acertos;
    cout << "Seja bem vindo!\nEsse jogo é fácil, você tem 10 tentativas, e cada uma dela você tem que informar uma senha, a senha que o programa criou é aleatória com 4 caracteres, e ele vai falar o número de acertos que você teve a cada tentativa\nas cores são:\np = Preto,\nb = Branco,\na = Azul\ne v = Vermelho" << endl;
    for (int i = 1; i <= 10; i++){
        acertos = 0;
        cout << "tentativa " << i << endl;
        cout << "Insira a senha:" << endl;
        cin >> senhaJ[0] >> senhaJ[1] >> senhaJ[2] >> senhaJ[3];
        for (int j = 0; j <= 3; j++){
            if (senhaJ[j] == senhaC[j]){
                acertos++;
            }
        }
        if (acertos == 4) {
            cout << "Parabéns você acertou!!" << endl;
            cout << "A senha é: ";
            for (int j = 0; j <= 3; j++) {
                cout << senhaC[j];
            }
            return 0;
        }
        cout << "Acertos: " << acertos << endl;
    }
    cout << "Você perdeu!!" << endl;
    cout << "A senha é: ";
    for(int i = 0; i <= 3; i++) {
        cout << senhaC[i];
    }

    return 0;
}
