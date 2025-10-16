#include "Lista.h"

Lista** Lista::Inserir(Lista **R, int N, int Q){
    Lista *novo = new Lista();
    novo->Num = N;
    novo->Quant = Q;
    
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->elo = R[0];
    }else{
        Lista *ant = NULL, *atual = R[0];
        while(atual != R[1] && novo->Quant < atual->Quant){
            ant = atual;
            atual = atual->elo;
        }
        while(atual != R[1] && novo->Quant == atual->Quant && novo->Num > atual->Num){
            ant = atual;
            atual = atual->elo;
        }
        if((atual == R[0] && novo->Quant > atual->Quant) ||
           (atual == R[0] && novo->Quant == atual->Quant && novo->Num < atual->Num)){
            novo->elo = R[0];
            R[0] = novo;
            R[1]->elo = R[0];
        }else if((atual == R[1] && novo->Quant < atual->Quant) ||
                (atual == R[1] && novo->Quant == atual->Quant && novo->Num > atual->Num)){
            R[1]->elo = novo;
            R[1] = novo;
            R[1]->elo = R[0];
        }else{
            ant->elo = novo;
            novo->elo = atual;
        }
    }
    return R;
};
void Lista::Listar(Lista **R){
    Lista *aux = R[0];
    while(aux != R[1]){
        std::cout << "Número: " << aux->Num << " - repetiu: " << aux->Quant << " vez(es)\n";
        aux = aux->elo;
    }
    std::cout << "Número: " << aux->Num << " - repetiu: " << aux->Quant << " vez(es)\n";
};
Lista* Lista::Pesquisar(Lista **R, int N){
    Lista *aux = R[0];
    while(aux != R[1] && aux->Num != N)
        aux = aux->elo;
    if(aux->Num != N)
        aux = NULL;
    return aux;
};
Lista** Lista::Excluir(Lista **R, int N){
    Lista *ant = NULL, *aux = R[0];
    while(aux != R[1] && aux->Num != N){
        ant = aux;
        aux = aux->elo;
    }
    if(R[0] == R[1]){
        R[0] = NULL;
        R[1] = NULL;
    }
    else if(aux == R[0]){
        R[0] = R[0]->elo;
        R[1]->elo = R[0];
    }else if(aux == R[1]){
        R[1] = ant;
        R[1]->elo = R[0];
    }else{
        ant->elo = aux->elo;
    }
    delete(aux);
    return R;
};
