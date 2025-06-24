#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	string banco[20] = {"Matematica","geografia","historia","portugues","artes","fisica","biologia","quimica","redacao","filosofia","sociologia","computadores","informatica","programacao","dados","web","mobile","laboratorio","ingles","projeto"};
	string palavra;
	bool jogar = true;
	bool comp = false;
	bool achou = false;
	int erros = 0;
	int pos = 0;
	int num = 0;
	char resposta;
	bool ganhou = false;
	char palpites[26] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
	cout << "Seja bem-vindo!\nO jogo é forca, é facil de jogar, e não há acentos nas palavras" << endl;
	while (jogar) {
    	palavra = banco[rand() % 20];

        erros = 0;
        pos = 0;
        num = 0;
        ganhou = false;
    	while (erros < 8) {
        	cout << "Erros: " << erros << endl;
        	cout << "Palpites: ";
        	for(int i = 0; i < 26; i++) {
            	if(palpites[i] != '0') {
                	cout << palpites[i] << " ";
            	}
        	}
        	cout << endl;
            int num = 0;
        	for(int i = 0; i < palavra.length(); i++){
            	for(int j = 0; j < 26; j++) {
                	if (palavra[i] == palpites[j]) {
                    	cout << palavra[i];
                    	comp = true;
                        num++;
                	}
            	}
            	if (!comp){
                	cout << "_";
            	}
            	comp = false;
        	}
        	cout << endl;

            if (num == palavra.length()) { 
                ganhou = true;
                break;
            }

        	cout << "Insira uma letra:" << endl;
        	cin >> palpites[pos];
        	for (int i = 1; i < pos + 1; i++) {
            	if (palpites[pos] == palpites[pos - i]) {
                	cout << "Tente novamente, você já tentou essa letra: ";
                	cin >> palpites[pos];
                    i = 0;
            	}
        	}
        	for(int i = 0; i < palavra.length(); i++){
            	if (palavra[i] == palpites[pos]) {
                	achou = true;
            	}
        	}
        	pos++;
        	if (!achou) {
            	erros++;
        	}
        	achou = false;
    	}
    	if (ganhou) {
        	cout << "Parabéns! Você ganhou! A palavra era: " << palavra << endl;
    	} else {
        	cout << "Você perdeu! A palavra era: " << palavra << endl;
    	}
    	cout << "quer jogar de novo? (s/n)" << endl;
    	cin >> resposta;
    	if (resposta == 's' || resposta == 'S') {
        	jogar = true;
    	} else {
        	jogar = false;
    	}
        for (int i = 0; i < 26; i++) {
        	palpites[i] = 0;
	    }
    }
    return 0;
}