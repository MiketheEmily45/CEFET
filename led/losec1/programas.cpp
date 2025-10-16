#include <windows.h>
#include "programas.h"

programas** programas::Inserir(programas** R, std::string nome, int tempo) {
    programas *novo = new programas();
    novo->nome = nome;
    novo->tempo = tempo;

    // lista vazia
    if (R[0] == NULL) {
        novo->elo = novo;
        R[0] = R[1] = novo;
        return R;
    }

    programas *ant = R[1];
    programas *atual = R[0];

    // procura o ponto de inserção:
    // ordenar por qtd (decrescente) e, em caso de empate, por num (crescente)
    do {
        if (nome > atual->nome) {
            break;
        }
        ant = atual;
        atual = atual->elo;
    } while (atual != R[0]);

    // insere entre ant e atual
    ant->elo = novo;
    novo->elo = atual;

    // ajusta head/tail conforme necessário
    bool insertedBeforeHead = (atual == R[0] && nome > atual->nome);
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

programas** programas::Excluir(programas** R, std::string nome) {
    programas *ant = R[0];
    programas *atual = R[0];
    if (R[0] == NULL) return R; // lista vazia
    bool found = false;

    do {
        if (atual->nome == nome) { found = true; break; }
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

programas** programas::Executar(programas** R) {
    programas *aux = R[0];
    programas L;
    while(aux != R[1]){
        std::cout << aux->nome << std::endl;
        Sleep(1000000);
        aux->tempo -= 1;
        if (tempo == 0) {
            R = L.Excluir(R, aux->nome);
        }
        aux = R[0];
    }
    return R;
}

void programas::Listar(programas** R) {
    if (R[0] == NULL) return;
    programas *aux = R[0];
    do {
        std::cout << aux->nome << " Tempo de execução: " << aux->tempo << " segundos" << std::endl;
        aux = aux->elo;
    } while (aux != R[0]);
}
