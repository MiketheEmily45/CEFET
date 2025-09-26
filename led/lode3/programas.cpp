#include "programas.h"

programas** programas::Inserir(programas **R, std::string nome, int bytes) {
    programas *novo = new programas();
    novo->bytes = bytes;
    novo->nome = nome;
    if(R[0] == NULL) {
        novo->proximo = NULL;
        novo->anterior = NULL;
        R[0] = novo;
        return R;
    }
    programas *aux = R[0];
    while (aux != NULL && (aux->bytes > novo->bytes && aux->nome < novo->nome)) {
        aux = aux->proximo;
    }
    if (aux == R[0]) {
        R[0]->anterior = novo;
        novo->proximo = R[0];
        novo->anterior = NULL;
        R[0] = novo;
    } else if (aux == NULL) {
        R[1]->proximo = novo;
        novo->anterior = R[1];
        novo->proximo = NULL;
        R[1] = novo;
    } else {
        novo->anterior = aux;
        novo->proximo = aux->proximo;
        aux->proximo->anterior = novo;
        aux->proximo = novo;
    }
    return R;
}
programas** programas::Excluir(programas **R, std::string nome) {
    programas *aux = R[0];
    while (aux != NULL && nome != aux->nome) {
        aux = aux->proximo;
    }
    if (aux != NULL) {
        if (aux == R[0]) {
            R[0]->proximo->anterior = NULL;
        } else if (aux == NULL) {
            R[1]->anterior->proximo = NULL;
        } else {
            aux->anterior->proximo = aux->proximo;
            aux->proximo->anterior = aux->anterior;
        }
    }
    delete aux;
    return R;
}
programas* programas::Pesquisar(programas* R, std::string nome) {
    programas *aux = R;
    while (aux != NULL && nome != aux->nome) {
        aux = aux->proximo;
    }
    return aux;
}
int programas::Bytes(programas* R) {
    programas *aux = R;
    int num = 0;
    num += aux->bytes;
    while (aux != NULL && nome != aux->nome) {
        aux = aux->proximo;
        num += aux->bytes;
    }
    return num;
}
void programas::Listar(programas *R) {
    programas *aux = R;
    while (aux != NULL) {
        std::cout << "Programa: " << aux->nome << " | tamanho: " << aux->bytes << std::endl;
        aux = aux->proximo;
    }
}










