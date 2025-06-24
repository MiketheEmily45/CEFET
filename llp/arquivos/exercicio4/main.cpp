#include <iostream> 
#include <fstream> 
#include <cstdlib> 

using namespace std;

int main() {

    ifstream arquivo1("lindo.txt");

    ifstream arquivo2("miau.txt");

    ofstream arquivo3("miadolindo.txt");

    if(!arquivo1.is_open()) {
        cerr << "Erro: Não foi possível abrir o primeiro arquivo." << endl;
        return 0;
    }
    if(!arquivo2.is_open()) {
        cerr << "Erro: Não foi possível abrir o segundo arquivo." << endl;
        return 0;
    }
    if(!arquivo3.is_open()) {
        cerr << "Erro: Não foi possível abrir o primeiro arquivo." << endl;
        return 0;
    }
    string linha;
    while(getline(arquivo1, linha)) {
        arquivo3 << linha << endl;
    }
    while(getline(arquivo2, linha)) {
        arquivo3 << linha << endl;
    }

    return 0;
}