#include <iostream>
#include "Fibo.h"

Fibo* Fibo::InserirPilha(Fibo *T, int num) {
    Fibo *aux = new Fibo();
    aux->num = num;
    aux->elo = T;
    T = aux;
    return T;
}

Fibo* Fibo::InserirFila(Fibo *F, int num){
    Fibo *novo = new Fibo();
    novo->num = num;
    novo->elo = NULL;
    if (F != NULL) {
        F->elo = novo;
    }
    F = novo;
    return F;
}

void Fibo::PercorrerPilha(Fibo *T) {
    Fibo *aux = T;
    while(aux != NULL) {
        std::cout << aux->num << " ";
        aux = aux->elo;
    }
    std::cout << std::endl;
}

void Fibo::PercorrerFila(Fibo *I) {
    Fibo *aux = I;
    while(aux != NULL) {
        std::cout << aux->num << " ";
        aux = aux->elo;
    }
    std::cout << std::endl;
}

Fibo* Fibo::EsvaziarPilha(Fibo *T) {
    Fibo *aux = T;
    while (aux != NULL) {
        T = T->elo;
        delete (aux);
        aux = T;
    }
    return T;
}
Fibo* Fibo::EsvaziarFila(Fibo *I) {
    Fibo *aux = I;
    while (aux != NULL) {
        I = I->elo;
        delete (aux);
        aux = I;
    }
    return I;
}
