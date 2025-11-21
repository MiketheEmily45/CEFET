#include <iostream>

class Cliente 
{
    public:
        std::string nome;
        std::string descricao;
        Cliente *proximo;
        Cliente* AdicionarCliente(Cliente*, std::string, std::string);
        void ListarClientes (Cliente*);
        Cliente* AtenderCliente(Cliente*);
        Cliente* EsvaziarClientes(Cliente*);
};