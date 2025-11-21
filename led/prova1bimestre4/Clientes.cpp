#include "Clientes.h"

Clientes** Clientes::Inserir(Clientes **R, int id, std::string nome, int ano, int pont) {
    Clientes *novo = new Clientes;
    novo->id = id;
    novo->nome = nome;
    novo->ano = ano;
    novo->pont = pont;
    if (R[0] == NULL) {
        R[0] = R[1] = novo;
    } else {
        Clientes *aux = R[0];
        while(aux->ano < novo->ano && aux != NULL){
            aux = aux->prox;
        }
        while(aux->nome < novo->nome && aux != NULL) {
            aux = aux->prox;
        }
        if (aux == R[0]) {
            novo->prox = R[0];
            R[0] = novo;
        } else if (aux == NULL) {
            R[1]->prox = novo;
            R[1] = novo;
        } else{
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    return R;
}

Clientes** Clientes::Excluir(Clientes **R, std::string nome, int ano) {
    Clientes *aux2 = R[0];
    Clientes *aux = R[0];
    while(aux->ano != ano) {
        aux2 = aux;
        aux = aux->prox;
    }
    while(aux->nome != nome) {
        aux2 = aux;
        aux = aux->prox;
    }
    if (aux == R[0]) {
        R[0] = R[0]->prox;
        delete aux;
    }
    else if (aux == R[1]) {
        aux->prox = NULL;
        R[1] = aux2;
        delete aux;
    }
    else {
        aux2->prox = aux->prox;
        delete aux;
    }
    return R;
}

Clientes** Clientes::Exclusao(Clientes **R, int minimo) {
    Clientes *aux = R[0];
    Clientes *aux2 = R[0];
    Clientes E;
    while (aux != NULL) {
        if(aux->pont < minimo) {
            aux2 = aux;
            aux = aux->prox;
            R = E.Excluir(R, aux2->nome, aux2->ano);
        }
        if(aux->pont >= minimo) {
            aux = aux->prox;
        }
    }
    return R;
}

Clientes** Clientes::Atualizar(Clientes **R, std::string nome, int ano, int pont) {
    Clientes *aux = R[0];
        while(aux->ano != ano && aux != NULL){
            aux = aux->prox;
        }
        while(aux->nome != nome && aux != NULL) {
            aux = aux->prox;
        }
        if (aux->nome != nome || aux->ano != ano) {
            std::cout << "Erro: Pessoa não encontrada" << std::endl;
            return R;
        } else {
            aux->pont = pont;
            std::cout << "Pontuação atualizada com sucesso!" << std::endl;
        }
    return R;
}

int Clientes::Contar(Clientes **R) {
    Clientes *aux = R[0];
    int contagem = 0;
    while(aux != NULL) {
        contagem++;
        aux = aux->prox;
    }
    return contagem;
}

void Clientes::Exibir(Clientes **R) {
    Clientes *aux = R[0];
    int contagem = 0;
    while(aux != NULL) {
        std::cout << aux->nome << " - id: " << aux->id << " - ano de registro: " << aux->ano << " - pontuação de fidelidade: " << aux->pont << std::endl;
        aux = aux->prox;
    }
}

