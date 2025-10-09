class losec
{
    public:
        int num;
        int qtd;
        losec *elo;
        void Exibir(losec**);
        losec** Inserir(losec**, int, int);
        losec** Excluir(losec**, int);
        losec* Pesquisar(losec**, int);
};
