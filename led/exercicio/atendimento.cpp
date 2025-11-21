#include <iostream>
#include "atendimento.h"

Atendimento* Atendimento::RegistrarAcao(Atendimento* T, std::string acao){
    Atendimento* aux = new Atendimento () ;
    aux->acao = acao;
    aux->proximo = T ;
    T = aux ;
    return T;
};

void Atendimento::MostrarAcoes (Atendimento* T){
    Atendimento* aux = T;
    if(aux == NULL){
        std::cout << "\nNenhuma acao registrada !\n ";
    } else {
        std::cout << "\nAcoes Registradas\n";
        while(aux != NULL){
            std::cout << aux->acao << std::endl;
            aux = aux->proximo;
        }
    }
};

Atendimento* Atendimento::DesfazerAcao(Atendimento* T){
    Atendimento* aux = T;
    T = T->proximo;
    delete (aux);
    return T;
};

Atendimento* Atendimento::EsvaziarAcoes(Atendimento* T){
    Atendimento* aux = T;
    while(aux != NULL){
        T = T->proximo;
        delete (aux);
        aux = T;
    }
    return T;
};