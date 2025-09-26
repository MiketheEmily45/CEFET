#include <iostream>
#include "lode.h"
#include "lose.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    lose O, **S;
    S = new lose*[2];
    S[0] = S[1] = NULL;

    lode Q, **D;
    D = new lode*[2];
    D[0] = D[1] = NULL;

    int num = 0;

    while(num != 3) {
        num = 1 + (rand() % 100);
        if(num == 3){
            break;
        }
        D = Q.Inserir(D, num);
        S = O.Inserir(S, num);
    }

    Q.Listar(D[0]);
    O.Listar(S[0]);

    return 0;
}
