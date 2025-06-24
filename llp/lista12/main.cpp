#include <iostream>
#include <cmath>

using namespace std;

class Ponto2d {
  public :
  double x;
  double y;
  Ponto2d (){
  x = 0.0;
  y = 0.0;
  }
  double dist(Ponto2d p) {

 double diffx = x - p.x;
 double diffy = y - p.y;

   return sqrt(pow(diffx, 2.0)+ pow(diffy, 2.0));
   }
};
int main() {
    int qtd;
    cout << "Olá! Seja bem vindo!" << endl;
    cout << "Determine quantos pontos você deseja:" << endl;
    cin >> qtd;
    Ponto2d ponto[qtd];
    for (int i = 0; i <= (qtd - 1); i++) {
        cout << "Insira as coordenadas:" << endl;
        cin >> ponto[i].x;
        cin >> ponto[i].y;
    }
    for ( int i = 0; i <= (qtd - 1); i++)
    {
        cout << "X" << i + 1 << " é " << ponto[i].x << endl;
        cout << "Y" << i + 1 << " é " << ponto[i].y << endl;

        if ( i < ( qtd - 1) ) {
        cout << "A distancia para o proximo é " << ponto[i].dist(ponto[i + 1]) << endl;
        } else {
        cout << "A distancia para o primeiro é " << ponto[i].dist(ponto[0]) << endl;        }
    }

return 0;
}