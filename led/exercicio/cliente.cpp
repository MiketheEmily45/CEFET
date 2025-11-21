#include <iostream>
#include "cliente.h"

Cliente* Cliente::AdicionarCliente(Cliente* T, std::string nome, std::string descricao){
    Cliente* aux = new Cliente () ;
    aux->nome = nome;
    aux->descricao = descricao;
    aux->proximo = NULL;
    if(T != NULL){
        T->proximo = aux;
    }
    T = aux;
    return T;
};

void Cliente::ListarClientes (Cliente* T){
    Cliente* aux = T;
    if(aux == NULL){
        std::cout << "\nNenhum cliente cadastrado !\n ";
    } else {
        std::cout << "\nClientes Cadastrados\n";
        while(aux != NULL){
            std::cout << "Nome: " << aux->nome << " - Descricao: " << aux->descricao << std::endl;
            aux = aux->proximo;
        }
    }
};

Cliente* Cliente::AtenderCliente(Cliente* T){
    Cliente* aux = T;
    T = T->proximo;
    delete (aux);
    return T;
};

Cliente* Cliente::EsvaziarClientes(Cliente* T){
    Cliente* aux = T;
    while(aux != NULL){
        T = T->proximo;
        delete (aux);
        aux = T;
    }
    return T;
};