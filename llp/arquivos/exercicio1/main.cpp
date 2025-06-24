#include <iostream> 
#include <fstream> 
#include <cstdlib> 

using namespace std;

int main() {

    string nomeArq;

    cout << "Digite o nome do arquivo" << endl;

    getline(cin, nomeArq);

    ofstream arquivo(nomeArq + ".txt");

    if (arquivo.is_open()) {
        arquivo << "está é a primeira frase. \n";
        arquivo << "está é a segunda frase. \n";
        arquivo << "está é a terceira frase. \n";

        cout << "Frases gravadas com sucesso no arquivo" << endl;
        arquivo.close();
    } else {
        cerr << "Erro: não houve como executar o programa." << endl;
    }

    return 0;
}