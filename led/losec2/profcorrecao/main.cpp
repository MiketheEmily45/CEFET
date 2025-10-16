#include "Lista.h"

using namespace std;

void Menu(){
    system("clear");
    cout << "1 - Inserir\n";
    cout << "2 - Listar\n";
    cout << "3 - Excluir\n";
    cout << "4 - Finalizar\n";
    cout << "Escolha: ";
}

int main()
{
    srand(time(NULL));
    Lista **L, obj, *resp;
    L = new Lista*[2];
    L[0] = L[1] = NULL;
    int n, q, op;
    do{
        Menu();
        cin >> op;
        switch(op){
            case 1:
                resp = NULL;
                do{
                    n = rand() % 101;
                    if(n != 0){
                        if(L[0] != NULL)
                            resp = obj.Pesquisar(L, n);
                        if(resp == NULL){
                            L = obj.Inserir(L, n, 1);
                        }else{
                            q = resp->Quant + 1;
                            L = obj.Excluir(L, n);
                            L = obj.Inserir(L, n, q);
                        }
                    }
                }while(n != 0);
                cout << "\nInseridos!\n";
                break;
            case 2:
                if(L[0] != NULL){
                    cout << "\nLISTA\n";
                    obj.Listar(L);
                }
                break;
            case 3:
                if(L[0] != NULL){
                    cout << "Informe o número: ";
                    cin >> n;
                    resp = obj.Pesquisar(L, n);
                    if(resp != NULL)
                        L = obj.Excluir(L, n);
                    else
                        cout << "Não tem!\n";
                }
                break;
            case 4:
                cout << "\nFIM!\n";
                break;
            default:
                cout << "\nINVÁLIDO!\n";
        }
        cout << "\nTECLE ENTER PARA CONTINUAR!\n";
        cin.ignore().get();
    }while(op != 4);
    return 0;
}
