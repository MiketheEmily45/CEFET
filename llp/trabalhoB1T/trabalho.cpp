// Feito por Miguel Rodrigues Silva, Carlos Daniel Bernardo Silva e João Pedro Pereira Ribeiro

#include <iostream>

using namespace std;

class Pessoa {
    protected:
        string nome;
        string CPF;

    public:
        Pessoa() {
            nome = "Joaquim";
            CPF = "123.456.789-00";
        }

        Pessoa(string nome, string CPF) {
            this->nome = nome;
            this->CPF = CPF;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return nome;
        }

        void setCPF(string CPF) {
            this->CPF = CPF;
        }

        string getCPF() {
            return CPF;
        }
};

class Passageiro : public Pessoa {
    protected:
        string telefone;
        string email;

    public:

    Passageiro() {
        Pessoa();
        telefone = "123456789";
        email = "Joaquim@gmail.com";
    }

    Passageiro(string nome, string CPF, string telefone, string email) : Pessoa(nome, CPF) {
        this->telefone = telefone;
        this->email = email;
    }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }

    string getTelefone() {
        return telefone;
    }

    void setEmail(string email) {
        this->email = email;
    }

    string getEmail() {
        return email;
    }
};

class Motorista : public Pessoa {
    protected:
        int no_viagens;
        double nota;
    public:
        Motorista() {
            Pessoa();
            no_viagens = 0;
            nota = 0;
        }

        Motorista(string nome, string CPF, int no_viagens, double nota) : Pessoa(nome, CPF) {
            this->no_viagens = no_viagens;
            this->nota = nota;
        }

        void setNoViagens(int no_viagens) {
            this->no_viagens = no_viagens;
        }

        int getNoViagens() {
            return no_viagens;
        }

        void setNota(double nota) {
            this->nota = nota;
        }

        double getNota() {
            return nota;
        }

        void avaliar(double avaliacao) {
            if (avaliacao >= 0 && avaliacao <= 5) {
                this->nota = (this->nota + (avaliacao * 2.0)) / 3.0;
            } else {
                cerr << "Nota de avaliação inválida invalida!" << endl;
            }
        }
};

class Carro {
    protected:
        string modelo;
        string placa;
        string cor;

    public:
        Carro() {
            modelo = "Fusca";
            placa = "ABC-1234";
            cor = "Azul";
        }

        Carro(string modelo, string placa, string cor) {
            this->modelo = modelo;
            this->placa = placa;
            this->cor = cor;
        }

        void setModelo(string modelo) {
            this->modelo = modelo;
        }

        string getModelo() {
            return modelo;
        }

        void setPlaca(string placa) {
            this->placa = placa;
        }

        string getPlaca() {
            return placa;
        }

        void setAno(string cor) {
            this->cor = cor;
        }

        string getCor() {
            return cor;
        }

};

int main() {
    int no_viagens;
    double avaliacao, nota;
    string nomeM, CPFP, CPFM, telefone, email, modelo, placa, cor;
    string* idnome = new string;
    cout << "Informe os dados do passageiro:" << endl;
    cout << "Nome: ";
    cin >> *idnome;
    cout << "CPF: ";
    cin >> CPFP;
    cout << "Telefone: ";
    cin >> telefone;
    cout << "Email: ";
    cin >> email;
    Passageiro passageiro(*idnome, CPFP, telefone, email);
    cout << "Informe os dados do motorista:" << endl;
    cout << "Nome: ";
    cin >> *idnome;
    cout << "CPF: ";
    cin >> CPFM;
    cout << "Número de viagens: ";
    cin >> no_viagens;
    cout << "Nota: ";
    cin >> nota;
    Motorista motorista(*idnome, CPFM, no_viagens, nota);
    cout << "Informe os dados do carro:" << endl;
    cout << "Modelo: ";
    cin >> modelo;
    cout << "Placa: ";
    cin >> placa;
    cout << "Cor: ";
    cin >> cor;
    Carro carro(modelo, placa, cor);
    cout << "Informe a nota de avaliação do motorista: ";
    cin >> avaliacao;
    motorista.avaliar(avaliacao);
    cout << "Dados do passageiro:" << endl;
    cout << "Nome: " << passageiro.getNome() << endl;
    cout << "CPF: " << passageiro.getCPF() << endl;
    cout << "Telefone: " << passageiro.getTelefone() << endl;
    cout << "Email: " << passageiro.getEmail() << endl;
    cout << "Dados do motorista:" << endl;
    cout << "Nome: " << motorista.getNome() << endl;
    cout << "CPF: " << motorista.getCPF() << endl;
    cout << "Número de viagens: " << motorista.getNoViagens() << endl;
    cout << "Nota: " << nota << endl;
    cout << "Dados do carro:" << endl;
    cout << "Modelo: " << carro.getModelo() << endl;
    cout << "Placa: " << carro.getPlaca() << endl;
    cout << "Cor: " << carro.getCor() << endl;
    cout << "Nota de avaliação do motorista: " << avaliacao << endl;
    cout << "Nota atual do motorista: " << motorista.getNota() << endl;
    cout << "Lembre-se que caso 'gostou' do passageiro, pode falar novamente com ele com os contatos ;)" << endl;
    cout << "Obrigado por usar nosso sistema!" << endl;
    cout << "Feito por Miguel Rodrigues Silva, Carlos Daniel Bernardo Silva e João Pedro Pereira Ribeiro" << endl;
    delete idnome;
    return 0;
}