#include "Divisores.h"
#include <iostream>

Divisores* Divisores::InserirPilha(Divisores *T, int Nume) {
    Divisores *aux = new Divisores();
    aux->Num = Nume;
    aux->elo = T;
    T = aux;
    return T;
}

Divisores* Divisores::InserirFila(Divisores *F, int Nume) {
    Divisores *novo = new Divisores();
    novo->Num = Nume;
    novo->elo = NULL;
    if(F != NULL){
        F->elo = novo;
    }
    F = novo;
    return F;
}
void Divisores::PercorrerPilha(Divisores *T) {
    Divisores *aux = T;
    if(aux == NULL) {
        std::cout << "\nPilha vazia" << std::endl;
    } else {
        while (aux != NULL) {
            std::cout << aux->Num << " ";
            aux = aux->elo;
        }
    std::cout << std::endl;
    }
}

void Divisores::PercorrerFila(Divisores *I) {
    Divisores *aux = I;
    while (aux != NULL) {
        std::cout << aux->Num << " ";
        aux = aux->elo;
    }
    std::cout << std::endl;
}
Divisores* Divisores::RemoverPilha(Divisores *T) {
    Divisores *aux = T;
    T = T->elo;
    delete(aux);
    return T;
}
Divisores* Divisores::RemoverFila(Divisores *I) {
    Divisores *aux = I;
    I = I->elo;
    delete(aux);
    return I;
}
Divisores* Divisores::RemoverPilhaCompleto(Divisores *T) {
    Divisores *aux = T;
    while(aux != NULL) {
        T = T->elo;
        delete(aux);
        aux = T;
    }
    return T;
}
Divisores* Divisores::RemoverFilaCompleto(Divisores *I) {
    Divisores *aux = I;
    while(I != NULL) {
        I = I->elo;
        delete(aux);
        aux = I;
    }
    return I;
}
