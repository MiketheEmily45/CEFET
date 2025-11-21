#include "Alunos.h"

Alunos** Alunos::Inserir(Alunos **R, int M, std::string N){
    Alunos *novo = new Alunos();
    novo->Matricula = M;
    novo->Nome = N;
    if(R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->elo = NULL;
    }else{
        Alunos *ant = NULL, *atual = R[0];
        while(atual != NULL && novo->Nome > atual->Nome){
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
Alunos* Alunos::Pesquisar(Alunos **R, std::string N){
    Alunos *aux = R[0];
    while(aux != NULL && aux->Nome != N)
        aux = aux->elo;
    return aux;
};
void Alunos::Exibir(Alunos *I){
    Alunos *aux = I;
    while(aux != NULL){
        std::cout << "Matrícula: " << aux->Matricula << " | Nome: " << aux->Nome << "\n";
        aux = aux->elo;
    }
};
Alunos** Alunos::Remover(Alunos **R, std::string N){
    Alunos *ant = NULL, *atual = R[0];
    while(atual->Nome != N){
        ant = atual;
        atual = atual->elo;
    }
    if(atual == R[0]){
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