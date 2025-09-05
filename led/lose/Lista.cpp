#include "Lista.h"

Lista** Lista::Inserir(Lista **R, std::string U, int Q){
    Lista *novo = new Lista();
    novo->URL = U;
    novo->Acessos = Q;
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->elo = NULL;
    }else{
        Lista *ant = NULL;
        Lista *atual = R[0];
        while((atual != NULL) && (novo->Acessos < atual->Acessos)){
            ant = atual;
            atual = atual->elo;
        }
        while((atual != NULL) && (novo->Acessos == atual->Acessos) &&
               novo->URL > atual->URL){
                    ant = atual;
                    atual = atual->elo;
               }
        if(ant == NULL){
            novo->elo = R[0];
            R[0] = novo;
        }else if(atual == NULL){
            R[1]->elo = novo;
            R[1] = novo;
            R[1]->elo = NULL;
        }else{
            ant->elo = novo;
            novo->elo = atual;
        }
    }
    return R;
};
void Lista::Listar(Lista *I){
    Lista *aux = I;
    while(aux != NULL){
        std::cout << aux->URL << " - " << aux->Acessos << "\n";
        aux = aux->elo;
    }
};
Lista** Lista::Excluir(Lista **R, std::string U){
    Lista *ant = NULL;
    Lista *atual = R[0];
    while((atual != NULL) && (atual->URL != U)){
        ant = atual;
        atual = atual->elo;
    }
    if(ant == NULL){
        R[0] = R[0]->elo;
    }else if(atual == R[1]){
        R[1] = ant;
        R[1]->elo = NULL;
    }else{
        ant->elo = atual->elo;
    }
    delete(atual);
    return R;
};
Lista* Lista::Procurar(Lista *I, std::string U){
    Lista *aux = I;
    while(aux != NULL && aux->URL != U){
        aux = aux->elo;
    }
    return aux;
};






