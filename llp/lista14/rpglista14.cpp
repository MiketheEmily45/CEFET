#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class personagens {
    private:
    string nome;
    int tipo;
    int ataque;
    int defesa;
    int resistencia;
    int agilidade;
    int magia;

    public:

    //construtor vazio
    personagens(){
        nome = "monkeys";
        ataque = rand() % 20 + 1;
        defesa = rand() % 20 + 1;
        agilidade = rand() % 20 + 1;
        magia = rand() % 20 + 1;
        resistencia = rand() % 21 + 10;
        tipo = rand()% 3 + 1;}


    //Nome set e get

    void setnome(string nome){
        this->nome = nome;}

    string getnome(){
        return nome;
    }

    //tipo set e get
      void settipo(int tipo){
        if (tipo < 1 || tipo > 3) {
            cerr << "Erro tipo Inválido!!" << endl;
            return;
     }

     this->tipo = tipo;
    }
    int gettipo(){
        return tipo;
    }
    //ataque get/set
    void setataque(int ataque){ if (ataque > 20 || ataque < 1) {

    cerr << "Erro ataque inválido" << endl;
    return;
    }

        this->ataque = ataque;
    }
    int getataque(){
      return ataque;
    }
    //defesa get/set
    void setdefesa(int defesa){ if (defesa > 20 || defesa < 1) {

    cerr << "Erro defesa inválido" << endl;
    return;
    }

        this->defesa = defesa;
    }
    int getdefesa(){
        return defesa;
    }
    //Agilidade get/set
    void setagilidade(int agilidade){ if (agilidade > 20 || agilidade < 1) {

    cerr << "Erro agilidade inválido" << endl;
    return;
    }

        this->agilidade = agilidade;
    }
    int getagilidade(){
        return agilidade;
    }
   //Magia get/set
     void setmagia(int magia){ if (magia > 20 || magia < 1) {

    cerr << "Erro magia inválido" << endl;
    return;
    }

        this->magia = magia;
    }
    int getmagia(){
        return magia;
    }
    //Resistencia set/get
    void setresistencia(int resistencia){ if (resistencia > 30|| resistencia < 10) {

    cerr << "Erro resistencia inválido" << endl;
    return;
    }

        this->resistencia = resistencia;
    }
    int getresistencia(){
        return resistencia;
    }
    //construtor
    personagens(string nome, int tipo){
        setnome(nome);
        settipo(tipo);
        do{
            ataque = rand() % 20 + 1;
            defesa = rand() % 20 + 1;
            agilidade = rand() % 20 + 1;
            magia = rand() % 20 + 1;
        } while (((ataque + defesa + agilidade + magia) != 40) && (ataque = magia));
        resistencia = rand() % 21 + 10;
    }
    //ataque
    int usarAtaque(personagens inimigo){
        return (ataque * (rand() % 6 + 1)) - (inimigo.defesa * (rand() % 6 + 1));
    }
    //magia
    int usarMagia(personagens inimigo){
        return (magia * (rand() % 8 + 1)) - (inimigo.defesa * (rand() % 8 + 1));
    }
};


int main()
{
    srand(time(NULL));
    int tipo1, tipo2, resultado1, resultado2;
    string nome1, nome2;

    personagens principal, inimigo;

    cout << "Entre o nome do personagem principal:" << endl;
    getline(cin, nome1);
    cout << "(1)-Guerreiro\n(2)-Arqueiro\n(3)-mago\nentre o tipo:" << endl;
    cin >> tipo1;
    if (tipo1 > 3 || tipo1 < 1) {
    cerr << "Erro! tipo inválido" << endl;
    }
    principal = personagens(nome1, tipo1);

    cout << "Entre o nome do personagem inimigo:" << endl;
    cin.ignore();
    getline(cin, nome2);
    cout << "(1)-Guerreiro\n(2)-Arqueiro\n(3)-mago\nentre o tipo:" << endl;
    cin >> tipo2;
    if (tipo2 > 3 || tipo2 < 1) {
    cerr << "Erro! tipo inválido" << endl;
    }
    inimigo = personagens(nome2, tipo2);

    cout << "Atributos do(a) " << principal.getnome() << "\nAtaque: " << principal.getataque() << "\nDefesa: " << principal.getdefesa() << "\nAgilidade: " << principal.getagilidade() << "\nMagia: " << principal.getmagia() << "\nResistência: " << principal.getresistencia() << endl;

    cout << "Atributos do(a) " << inimigo.getnome() << "\nAtaque: " << inimigo.getataque() << "\nDefesa: " << inimigo.getdefesa() << "\nAgilidade: " << inimigo.getagilidade() << "\nMagia: " << inimigo.getmagia() << "\nResistência: " << inimigo.getresistencia() << endl;

    for(int i = 1; i <= 10; i++){
        if(principal.getagilidade() > inimigo.getagilidade()){
            if(principal.getataque() > principal.getmagia()){
                resultado1 = principal.usarAtaque(inimigo);
                cout << principal.getnome() << " Usou ataque e deu " << resultado1 << " de dano!" << endl;
            }else if(principal.getataque() < principal.getmagia()){
                resultado1 = principal.usarMagia(inimigo);
                cout << principal.getnome() << " Usou magia e deu " << resultado1 << " de dano!" << endl;
            }
            if (resultado1 > inimigo.getresistencia()){
            cout << principal.getnome() << " venceu!" << endl;
            return 0;
            }
            }if(inimigo.getataque() > inimigo.getmagia()){
                resultado2 = inimigo.usarAtaque(principal);
                cout << inimigo.getnome() << " Usou ataque e deu " << resultado2 << " de dano!" << endl;
            }else if(inimigo.getataque() < inimigo.getmagia()){
                resultado2 = inimigo.usarMagia(principal);
                cout << inimigo.getnome() << " Usou magia e deu " << resultado2 << " de dano!" << endl;
            }
            if (resultado2 > principal.getresistencia()){
            cout << inimigo.getnome() << " venceu!" << endl;
            return 0;
            }
            if(principal.getagilidade() < inimigo.getagilidade()){
            if(inimigo.getataque() > inimigo.getmagia()){
                resultado1 = principal.usarAtaque(inimigo);
                cout << inimigo.getnome() << " Usou ataque e deu " << resultado1 << " de dano!" << endl;
            }else if(inimigo.getataque() < inimigo.getmagia()){
                resultado1 = inimigo.usarMagia(principal);
                cout << inimigo.getnome() << " Usou magia e deu " << resultado1 << " de dano!" << endl;
            }
            if (resultado1 > principal.getresistencia()){
            cout << inimigo.getnome() << " venceu!" << endl;
            return 0;
            }
            if(principal.getataque() > principal.getmagia()){
                resultado2 = principal.usarAtaque(inimigo);
                cout << principal.getnome() << " Usou ataque e deu " << resultado2 << " de dano!" << endl;
            }else if(principal.getataque() < principal.getmagia()){
                resultado2 = principal.usarMagia(inimigo);
                cout << principal.getnome() << " Usou magia e deu " << resultado2 << " de dano!" << endl;
            }
            if (resultado2 > inimigo.getresistencia()){
            cout << principal.getnome() << " venceu!" << endl;
            return 0;
            }
        } else if(principal.getagilidade() ==inimigo.getagilidade()){
            while(principal.getagilidade() == inimigo.getagilidade()){
                inimigo.setagilidade(rand() % 20 + 1);
                principal.setagilidade(rand() % 20 + 1);
            }
        }
        i--;
    }
    cout << "Deu empate!" << endl;

    return 0;
}