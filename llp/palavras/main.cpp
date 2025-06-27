#include "Palavra.h"
#include <iostream>
#include <fstream>

using namespace std;
static bool comp= false;
static int num = 0;

string LerLinha(fstream &arquivo, int pos) {
	string linha;
	int count = 0;
	arquivo.seekg(0);
	while(count < pos) {
		count++;
		arquivo.clear();
		getline(arquivo, linha);
	}
	return linha;
}

int main(){
	srand(time(NULL));

	fstream Palavras;

	Palavras.open("palavras.txt", ios::in);
	if (!Palavras.is_open()) {
		cout << "Erro ao abrir o arquivo de palavras." << endl;
		return 0;
	}
    char palpites[26] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
	int pos = 0, tentativas, opcao, sorteio[10];
    bool achou = false, win = false;
	char next;
    Palavra P[11];
    do {
		if (Palavras.eof()) {
			cout << "Arquivo de palavras está vazio ou não contém palavras suficientes." << endl;
			return 0;
		}
		P[10].setPalavra(LerLinha(Palavras, rand() % 10));
		for(int i = 0; i < 10; i++) {
			sorteio[i] = (rand() % 20) + 10;
			for (int j = 0; j < i; j++) {
				if (sorteio[i] == sorteio[j]) {
					i--;
					break;
				}
			}
			P[i].setPalavra(LerLinha(Palavras, sorteio[i]));
		}
	
		string palavra = P[10].getPalavra();
		for (char c : palavra) {
			bool repetida = false;
			for (int i = 0; i < pos; i++) {
				if (palpites[i] == c) {
					repetida = true;
					break;
				}
			}
			if (!repetida) {
				palpites[pos++] = c;
			}
		}
		
		
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
			cout << P[10].getPalavra() << endl;
			for(int i = 0; i < 10; i++) {
        		P[i].Exibir(comp, num, palpites);
			}
			cout << "Palpites: ";
			for(int i = 0; i < 26; i++) {
            	if(palpites[i] != '0') {
                	cout << palpites[i] << " ";
            	}
        	}
			cout << endl;
   			cout << "Insira uma letra:" << endl;
        	cin >> palpites[pos];
        	for (int i = 1; i < pos + 1; i++) {
            	if (palpites[pos] == palpites[pos - i]) {
                	cout << "Tente novamente, você já tentou essa letra: ";
                	cin >> palpites[pos];
                    i = 0;
            	}
        	}
			for(int i = 0; i < 10; i++) {
        		for(int j = 0; j < P[i].getPalavra().length(); j++){
            		if (P[i].getPalavra()[j] == palpites[pos]) {
                		achou = true;
            		}
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