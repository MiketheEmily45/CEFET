#include <iostream> 
#include <fstream> 
#include <cstdlib> 

using namespace std;

int main() {

    ifstream arquivo ("lindo.txt");
    if (arquivo.is_open()){

    string linha;
    while(getline(arquivo, linha)){
    cout << linha << endl;}
    arquivo.close();
    }   else {
    cerr << "Erro ao abrir o arquivo" << endl;
}

    
    return 0;
}