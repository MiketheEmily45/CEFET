class Fibo
{
    public:
    int num;
    Fibo* elo;
    Fibo* InserirPilha(Fibo*, int);
    Fibo* InserirFila(Fibo*, int);
    void PercorrerPilha(Fibo*);
    void PercorrerFila(Fibo*);
    Fibo* EsvaziarPilha(Fibo*);
    Fibo* EsvaziarFila(Fibo*);
};
