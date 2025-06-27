#include <iostream>

using namespace std;

int main()
{
    int monica, filhoc, filhom, filhov;

    cout << "Insira a idade da Dona Mônica" << endl;
    cin >> monica;

    if(monica < 40 || monica > 110) {
        cerr << "Idade inválida para Dona Mônica";
        return 0;
    }

    cout << "Insira a idade do filho do meio" << endl;
    cin >> filhom;
    if(filhom < 2 || filhom >= (monica - 25)) {
        cerr << "Idade inválida para filho do meio";
        return 0;
    }

    cout << "Insira a idade do filho caçula" << endl;
    cin >> filhoc;
    if(filhoc < 1 || filhoc >= (filhom - 1)) {
        cerr << "Idade inválida para filho mais novo";
        return 0;
    }

    filhov = monica - (filhom + filhoc);

    cout << "Idade da Dona Mônica: " << monica << endl;
    cout << "Idade do filho mais velho: " << filhov << endl;

    return 0;
}
