#include <iostream>
#include "num.h"


using namespace std;



int main()
{
    num *Topo = NULL, P;
    int N;
    do {
        cout << "Digite: ";
        cin >> N;
        if (N != -1) {
            if(N != 0) {
                Topo = P.InserirPilha(Topo, N);
            }else{
                Topo = P.RemoverPilha(Topo);
            }
        }
    } while (N != -1);
    cout << "A soma é: " << P.Somar(Topo) << endl;
    return 0;
}
