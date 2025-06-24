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
class Triangulo {
    public:
    Ponto2d a;
    Ponto2d b;
    Ponto2d c;

    double hipotenusa(Triangulo h){
        double hip;
        double ab = a.dist(b);
        double bc = b.dist(c);
        double ca = c.dist(a);
        if (ab < bc) {
            hip = bc;
            if (hip < ca){
                hip = ca;
            }
        } else {
            hip = bc;
            if (hip < ca){
                hip = ca;
            }
        }
        return hip;
    }
};
int main() {
    int qtd;
    cout << "Olá! Seja bem vindo!" << endl;
    cout << "Determine quantos triangulos você deseja você deseja:" << endl;
    cin >> qtd;
    Triangulo tri[qtd];
    for (int i = 0; i <= (qtd - 1); i++) {
        cout << "Insira as coordenadas do x e y do ponto a:" << endl;
        cin >> tri[i].a.x;
        cin >> tri[i].a.y;
        cout << "Insira as coordenadas do x e y do ponto b:" << endl;
        cin >> tri[i].b.x;
        cin >> tri[i].b.y;
        cout << "Insira as coordenadas do x e y do ponto c:" << endl;
        cin >> tri[i].c.x;
        cin >> tri[i].c.y;
    }
    double maior = tri[0].hipotenusa(tri[0]);
    double menor = tri[0].hipotenusa(tri[0]);
    for (int i = 1; i <= qtd; i++){
    if (maior < tri[i].hipotenusa(tri[i])){
        maior = tri[i].hipotenusa(tri[i]);
    }
    if (menor > tri[i].hipotenusa(tri[i]))
        menor = tri[i].hipotenusa(tri[i]);
    }
    for ( int i = 0; i <= (qtd - 1); i++)
    {
        cout << "hipotenusa " << i + 1 << " é " << tri[i].hipotenusa(tri[i]) << endl;
    }
    cout << "A maior hipotenusa é: " << maior;
    cout << "A menor hipotenusa é: " << menor;
    return 0;
}