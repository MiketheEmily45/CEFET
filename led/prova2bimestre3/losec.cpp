#include <time.h>
#include <stdlib.h>
#include "losec.h"

losec** losec::Inserir(losec **R, std::string nome, int idade) {
    losec *novo = new losec;
    novo->nome = nome;
    novo->idade = idade;
    if (R[0] == NULL) {
        novo->elo = novo;
        R[0] = novo;
        R[1] = novo;
    } else {
        losec *ant = R[0];
        losec *atual = R[0];
        while(atual != R[1] && atual->idade < idade) {
            ant = atual;
            atual = atual->elo;
        }
        while(atual != R[1] && atual->nome > nome) {
            ant = atual;
            atual = atual->elo;
        }
        if(atual == R[0]) {
            R[1]->elo = novo;
            novo->elo = R[0];
            R[0] = novo;
        }else if(atual == R[1]) {
            R[1]->elo = novo;
            novo->elo = R[0];
            R[1] = novo;
        }else {
            ant->elo = novo;
            novo-> elo = atual;
        }
    }
    return R;
}

losec** losec::Excluir(losec **R, std::string nome) {
    losec *ant = R[0];
    losec *atual = R[0];
    while(atual != R[1] && atual->nome != nome) {
        ant = atual;
        atual = atual->elo;
    }
    if (atual->nome == nome) {
        if(atual == R[0]) {
            R[1]->elo = R[0]->elo;
            delete R[0];
            delete atual;
            R[0] = R[1]->elo;
        }else if(atual == R[1]) {
            ant->elo = R[0];
            delete R[1];
            delete atual;
            R[1] = ant;
        }else {
            ant->elo = atual->elo;
            delete atual;
        }
    }
    return R;
}

void losec::Listar(losec **R) {
    losec *aux = R[0];
    do {
        std::cout << "Nome: " << aux->nome << " | Idade: " << aux->idade << std::endl;
        aux = aux->elo;
    } while (aux != R[0]);
}

void losec::Sortear(losec **R) {
    int contagem;
    std::string nome;
    losec L;
    losec *aux = R[0];
     while (R[0] != R[1]) {
        contagem =  1 + (rand() % 100);
        while (contagem != 0) {
            aux = aux->elo;
            contagem--;
            nome = aux->nome;
        }
        aux = aux->elo;
        R = L.Excluir(R, nome);
    }
    std::cout << "O vencedor foi: " << aux->nome << "!!!" << std::endl;
}
