#include <iostream>
#include "cliente.h"
#include "atendimento.h"

using namespace std;

int main()
{   
    int opcao;
    Cliente* Clientes = NULL, I;
    Atendimento* Atendimento = NULL, T;

    string nome, descricao, acao;
    cout << "Seja bem-vindo!\n1-Adicionar cliente à fila\n2-Atender próximo cliente\n3-Mostrar fila de espera\n4-Registrar ação do técnico\n5-Desfazer última ação\n6-Mostrar ações realizadas\n7-Sair" << endl;
    do {
        cout << "\nEscolha uma opção: ";
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "Nome do cliente: ";
                cin >> nome;
                cout << "Descrição do problema: ";
                cin >> descricao;
                I.AdicionarCliente(Clientes, nome, descricao);
                cout << "Cliente adicionado à fila de espera." << endl;
                break;
            case 2:
                I.AtenderCliente(Clientes);
                cout << "Próximo cliente atendido." << endl;
                break;
            case 3:
                I.ListarClientes(Clientes);
                break;
            case 4:
                cout << "Descrição da ação realizada: ";
                cin >> acao;
                T.RegistrarAcao(Atendimento, acao);
                cout << "Ação registrada." << endl;
                break;
            case 5:
                T.DesfazerAcao(Atendimento);
                cout << "Última ação desfeita." << endl;
                break;
            case 6:
                T.MostrarAcoes(Atendimento);
                break;
            case 7:
                cout << "Saindo do programa. Até mais!" << endl;
                I.EsvaziarClientes(Clientes);
                T.EsvaziarAcoes(Atendimento);
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 7);
    return 0;
}