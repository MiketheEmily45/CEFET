#include <iostream>
#include "Alunos.h"
#include "Notas.h"

using namespace std;

void Menu(){
    system("clear");
    cout << "1 - Cadastrar aluno\n";
    cout << "2 - Cadastrar nota\n";
    cout << "3 - Listagem de alunos\n";
    cout << "4 - Listagem de notas de um aluno\n";
    cout << "5 - Excluir aluno\n";
    cout << "6 - Excluir nota\n";
    cout << "0 - Finalizar programa\n";
    cout << "Escolha sua opção: ";
}

int main(){

    Alunos **Aluno, A, *respAluno;
    Aluno = new Alunos*[2];
    Aluno[0] = Aluno[1] = NULL;
    Notas **Nota, N, *respNota;
    Nota = new Notas*[2];
    Nota[0] = Nota[1] = NULL;
    string nome;
    int matr = 1, op;
    float nota;
    do{
        Menu();
        cin >> op;
        switch (op)
        {
        case 0:
            cout << "Finalizando ... ";
            break;
        case 1:
            cout << "Informe o nome do aluno: ";
            cin.ignore();
            getline(cin, nome);
            Aluno = A.Inserir(Aluno, matr, nome);
            cout << "Aluno inserido com sucesso!\n";
            matr++;
            break;
        case 2:
            cout << "Informe o nome do aluno para registrar a nota: ";
            cin.ignore();
            getline(cin, nome);
            respAluno = A.Pesquisar(Aluno, nome);
            if(respAluno == NULL)
                cout << "Primeiro cadastre o aluno!\n";
            else{
                cout << "Informe a nota desse aluno: ";
                cin >> nota;
                Nota = N.Inserir(Nota, respAluno->Matricula, nota);
                cout << "Nota registrada com sucesso!\n";
            }
            break;
        case 3:
            if(Aluno[0] == NULL)
                cout << "Não há alunos cadastrados!\n";
            else{
                cout << "Listagem de alunos\n";
                A.Exibir(Aluno[0]);
            }
            break;
        case 4:
            cout << "Informe o nome do aluno para exibir as nota: ";
            cin.ignore();
            getline(cin, nome);
            respAluno = A.Pesquisar(Aluno, nome);
            if(respAluno == NULL)
                cout << "Aluno não cadastrado!\n";
            else{
                respNota = N.Pesquisar(Nota, respAluno->Matricula);
                if(respNota != NULL){
                    cout << "Notas do aluno " << respAluno->Nome << ": ";
                    N.Exibir(Nota, respAluno->Matricula);
                }
                else
                    cout << "Não há notas registradas para este aluno!\n";
            }
            break;
        case 5:
            cout << "Informe o nome do aluno para excluir: ";
            cin.ignore();
            getline(cin, nome);
            respAluno = A.Pesquisar(Aluno, nome);
            if(respAluno == NULL)
                cout << "Aluno não cadastrado!\n";
            else{
                respNota = N.Pesquisar(Nota, respAluno->Matricula);
                if(respNota != NULL)
                    cout << "Aluno possui notas registradas. Primeiro delete as notas!\n";
                else{
                    Aluno = A.Remover(Aluno, nome);
                    cout << "Registro de aluno removido!\n";
                }
            }
            break;
        case 6:
            cout << "Informe o nome do aluno para excluir uma nota: ";
            cin.ignore();
            getline(cin, nome);
            respAluno = A.Pesquisar(Aluno, nome);
            if(respAluno == NULL)
                cout << "Aluno não cadastrado!\n";
            else{
                respNota = N.Pesquisar(Nota, respAluno->Matricula);
                if(respNota == NULL)
                    cout << "Este aluno não possui notas registradas!\n";
                else{
                    Nota = N.Excluir(Nota, respAluno->Matricula);
                    cout << "Nota do aluno deletada com sucesso!\n";
                }
            }
            break;        
        default:
            cout << "Opçãqo inválida!\n";
        }

        cout << "\nTECLE ENTER PARA CONTINUAR! ";
        cin.ignore().get();
    }while(op != 0);
   
    return 0;
}