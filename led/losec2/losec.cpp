#include <iostream>
#include "losec.h"

losec** losec::Inserir(losec** R, int num, int qtd) {
    losec *novo = new losec();
    novo->num = num;
    novo->qtd = qtd;

    // lista vazia
    if (R[0] == NULL) {
        novo->elo = novo;
        R[0] = R[1] = novo;
        return R;
    }

    losec *ant = R[1];
    losec *atual = R[0];

    // procura o ponto de inserção:
    // ordenar por qtd (decrescente) e, em caso de empate, por num (crescente)
    do {
        if ((qtd > atual->qtd) || (qtd == atual->qtd && num < atual->num)) {
            break;
        }
        ant = atual;
        atual = atual->elo;
    } while (atual != R[0]);

    // insere entre ant e atual
    ant->elo = novo;
    novo->elo = atual;

    // ajusta head/tail conforme necessário
    bool insertedBeforeHead = (atual == R[0] && ((qtd > atual->qtd) || (qtd == atual->qtd && num < atual->num)));
    bool insertedAtEnd = (ant == R[1] && atual == R[0] && !insertedBeforeHead);

    if (insertedBeforeHead) {
        R[0] = novo;
        R[1]->elo = R[0];
    } else if (insertedAtEnd) {
        // novo ficou após o último elemento -> novo é o novo tail
        R[1] = novo;
    }

    return R;
}

losec** losec::Excluir(losec **R, int num) {
    if (R[0] == NULL) return R; // lista vazia

    losec *ant = R[1];
    losec *atual = R[0];
    bool found = false;

    do {
        if (atual->num == num) { found = true; break; }
        ant = atual;
        atual = atual->elo;
    } while (atual != R[0]);

    if (!found) return R; // não encontrado

    // único elemento
    if (atual == R[0] && atual == R[1]) {
        delete atual;
        R[0] = R[1] = NULL;
        return R;
    }

    // remove e ajusta apontadores
    ant->elo = atual->elo;
    if (atual == R[0]) R[0] = atual->elo;
    if (atual == R[1]) R[1] = ant;

    delete atual;
    return R;
}

losec* losec::Pesquisar(losec **R, int num) {
    if (R[0] == NULL) return NULL;

    losec *atual = R[0];
    do {
        if (atual->num == num) return atual;
        atual = atual->elo;
    } while (atual != R[0]);

    return NULL;
}

void losec::Exibir(losec **R) {
    if (R[0] == NULL) return;
    losec *aux = R[0];
    do {
        std::cout << aux->num << " - repetiu: " << aux->qtd << " vezes" << std::endl;
        aux = aux->elo;
    } while (aux != R[0]);
}