#include "Notas.h"

Notas** Notas::Inserir(Notas **R, int M, float No){
    Notas *novo = new Notas();
    novo->Matricula = M;
    novo->Nota = No;
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->elo = NULL;
    }
    else{
        Notas *ant = NULL, *atual = R[0];
        while(atual != NULL && novo->Matricula > atual->Matricula){
            ant = atual;
            atual = atual->elo;
        }
        if(ant == NULL){
            novo->elo = R[0];
            R[0] = novo;
        }
        else if(atual == NULL){
            R[1]->elo = novo;
            R[1] = novo;
            R[1]->elo = NULL;
        }
        else{
            ant->elo = novo;
            novo->elo = atual;
        }
    }
    return R;
};
Notas* Notas::Pesquisar(Notas **R, int M){
    Notas *aux = R[0];
    while(aux != NULL && aux->Matricula != M)
        aux = aux->elo;
    return aux;
};
void Notas::Exibir(Notas **R, int M){
    Notas *aux = R[0];
    while(aux != NULL){
        if(aux->Matricula == M){
            std::printf("%.1f  ", aux->Nota);
        }
        aux = aux->elo;
    }
};
Notas** Notas::Excluir(Notas **R, int M){
    Notas *ant = NULL, *atual = R[0];
    while(atual->Matricula != M){
        ant = atual;
        atual = atual->elo;
    }
    if(ant == NULL){
        R[0] = R[0]->elo;
    }
    else if(atual == R[1]){
        R[1] = ant;
        R[1]->elo = NULL;
    }
    else{
        ant->elo = atual->elo;
    }
    delete(atual);
    return R;
};