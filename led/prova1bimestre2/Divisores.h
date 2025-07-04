class Divisores
{
    public:
        int Num;
        Divisores* elo;
        Divisores* InserirPilha(Divisores*, int N);
        Divisores* InserirFila(Divisores*, int N);
        void PercorrerPilha(Divisores*);
        void PercorrerFila(Divisores*);
        Divisores* RemoverPilha(Divisores*);
        Divisores* RemoverFila(Divisores*);
        Divisores* RemoverPilhaCompleto(Divisores*);
        Divisores* RemoverFilaCompleto(Divisores*);
};
