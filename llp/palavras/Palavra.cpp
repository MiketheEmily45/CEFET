#include <iostream>
#include <string>
#include "Palavra.h"

Palavra::Palavra(std::string p) : palavra(p) {
    this->palavra = p;
}
Palavra::Palavra() {
    this->palavra = "";
}

void Palavra::Exibir(bool& comp, int& num, char palpites[]){
	for(int i = 0; i < palavra.length(); i++){
      for(int j = 0; j < 26; j++) {
        	if (palavra[i] == palpites[j]) {
               std::cout << palavra[i];
            	comp = true;
                num++;
        	}
        }
        if (!comp){
        	std::cout << "_";
        }
    	comp = false;
    }
    std::cout << std::endl;
}

std::string Palavra::getPalavra(){
    return this->palavra;
}

void Palavra::setPalavra(std::string p) {
    this->palavra = p;
}
