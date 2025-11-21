#include <iostream>

class Atendimento
{
    public:
        std::string acao;
        Atendimento *proximo;
        Atendimento* RegistrarAcao(Atendimento*, std::string);
        void MostrarAcoes (Atendimento*);
        Atendimento* DesfazerAcao(Atendimento*);
        Atendimento* EsvaziarAcoes(Atendimento*);
};