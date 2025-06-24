#include "Palavra.h"
#include <iostream>

using namespace std;
static bool comp= false;
static int num = 0;

int main(){

    char palpites[26] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
	int pos = 0, tentativas, opcao;
    bool achou = false, win = false;
	char next;
    Palavra P("saturno");
    do {
		cout << "escolha 1 para fácil, 2 para médio ou 3 para difícil"<<endl;
		cin >> opcao;

	 	switch(opcao){
			case 1:
				tentativas = 10;
				break;
			case 2:
				tentativas = 8;
				break;
			case 3:
				tentativas = 5;
				break;
			default:
				cout << "Opção inválida, tente novamente." << endl;
				continue;}

		do{
			
        	P.Exibir(comp, num, palpites);

   			cout << "Insira uma letra:" << endl;
        	cin >> palpites[pos];
        	for (int i = 1; i < pos + 1; i++) {
            	if (palpites[pos] == palpites[pos - i]) {
                	cout << "Tente novamente, você já tentou essa letra: ";
                	cin >> palpites[pos];
                    i = 0;
            	}
        	}
        	for(int i = 0; i < P.getPalavra().length(); i++){
            	if (P.getPalavra()[i] == palpites[pos]) {
                	achou = true;
            	}
        	}
        	pos++;
        	if (!achou) {
            	tentativas--;
        	}
        	achou = false;

        } while(tentativas > 0 && !win);

		cout << "Gostaria de jogar novamente? (S/s para sim, N/n para não): ";
		cin >> next;
	} while (next == 'S' || next == 's');
    	

return 0;
}