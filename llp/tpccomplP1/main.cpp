#include <iostream>
#include <string>
#define TAM 100
using namespace std;

class pacote{
private:
string tipo, sufixo, nome;
int codigo;
static int qtd;
public:
    pacote(){
        tipo = "";
        sufixo = "";
        nome = "";
        codigo = 0;
    }
    pacote(string tipo, string sufixo, int codigo){
        this->tipo = tipo;
        this->sufixo = sufixo;
        this->codigo = codigo;
        qtd++;
    }
    string imprimir() {
    
        if(!nome.empty()) {
            return tipo + to_string(codigo) + sufixo + ", foi recebido por: " + nome;
        } else {
            return tipo + to_string(codigo) + sufixo;
        }
    }

    void setNome(string nome) {
        this->nome = nome;
    }

};

int pacote::qtd = 0;

int main(){
    int num_pact = 0;
    pacote pacotes[TAM];
    string tipo, sufixo, codigocru, nome;
    int codigo;
      do{

        do
        {
        cout << "Digite o codigo do pacote (ou 'sair' para encerrar): ";
        cin >> codigocru;

        
        if (codigocru == "sair") {
            break;
        }

        if(codigocru.length() != 13)
        cout<<"Codigo invalido! Deve ter exatamente 13 caracteres." << endl;
            
        } while (codigocru.length() < 13 || codigocru.length() > 13);
        
        
        if (codigocru == "sair") {
            break;
        }
        codigo = stoi(codigocru.substr(2, 9));

        tipo = codigocru.substr(0, 2);
        sufixo = codigocru.substr(11, 2);
        
        

        pacotes[num_pact] = pacote(tipo, sufixo, codigo);
        num_pact++;
        cout << "Pacote adicionado com sucesso!" << endl;
        cout << "quer adicionar o nome do destinatario? (s/n): ";
        char resposta;
        cin >> resposta;
        if (resposta == 'n' || resposta == 'N') {
            continue;
        } 
        cout << "Digite o nome de quem recebeu o pacote: ";
        cin >> nome;
        pacotes[num_pact - 1].setNome(nome);
      } while (num_pact < TAM);
    for(int i = 0; i < num_pact; i++) {
        cout << pacotes[i].imprimir() << endl;
    }

    return 0;
}