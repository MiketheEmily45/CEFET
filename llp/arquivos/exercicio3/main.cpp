#include <iostream> 
#include <fstream> 
#include <cstdlib> 

using namespace std;

int main() {


    ifstream arquivo ("lindo.txt");

    if (arquivo.is_open()){

    string palavra;
    int num;
    while(arquivo >> palavra){
        num++;
    }
    cout << num << endl;
    
    arquivo.close();
    }   else {
    cerr << "Erro ao abrir o arquivo" << endl;
    }

    return 0;
}