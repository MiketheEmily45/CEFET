#include <iostream>
#include <cmath>
using namespace std;

class localizacao {
    protected:
        double latitude;
        double longitude;
    public:
        localizacao() {
            latitude = 0.0;
            longitude = 0.0;
        }
        double getLAT() {
            return latitude;
        }
        void setLAT(double latitude){
            if (latitude > 90 || latitude < -90) {
                cerr << "Erro: Valor inválido" << endl;
            } else {
                this->latitude = latitude;
            }
        }
        double getLON() {
            return longitude;
        }
        void setLON(double longitude){
            if (longitude > 180 || longitude < -180) {
                cerr << "Erro: Valor inválido" << endl;
            } else {
                this->longitude = longitude;
            }
        }
        localizacao(double latitude, double longitude){
            setLAT(latitude);
            setLON(longitude);
        }
};

class coordenadageografica : public localizacao {
    protected:
        double elevacao;
    public:
        coordenadageografica() : localizacao() {
            elevacao = 0;
        }
        double getELE(){
            return elevacao;
        }
        void setELE(double elevacao){
            this-> elevacao = elevacao;
        }
        coordenadageografica(double latitude, double longitude, double elevacao): localizacao(latitude, longitude){
            setELE(elevacao);
        }
    
};

int main() {
    double x, y, z;
    cout << "entre a longitude:" << endl;
    cin >> x;
    cout << "entre a latitude:" << endl;
    cin >> y;
    cout << "entre a elevação (em km):" << endl;
    cin >> z;
    coordenadageografica local(y, x, z);
    if (local.getLAT() > 0.0){
        cout << "está localizado no norte" << endl;
    } else if (local.getLAT() < 0.0){
        cout << "está localizado no sul" << endl;
    }else{
        cout << "está localizado no equador" << endl;
    }
    
    if (local.getLON() > 0.0){
        cout << "está localizado no leste" << endl;
    } else if (local.getLON() < 0.0){
        cout << "está localizado no oeste" << endl;
    }else{
        cout << "está localizado no greenwich" << endl;
    }

    if(local.getELE() < 0.0){
        cout << "está localizado abaixo do nível do mar" << endl;
    }else if (local.getELE() == 0) {
        cout << "está localizado no nível do mar" << endl;
    }else if (local.getELE() > 0.0 && local.getELE() <= 12.0){
        cout << "está localizado na troposfera" << endl;
    }else if (local.getELE() > 12.0 && local.getELE() <= 50.0){
        cout << "está localizado na estratosfera" << endl;
    }else if (local.getELE() > 50.0 && local.getELE() <= 80.0){
        cout << "está localizado na mesosfera" << endl;
    }else if (local.getELE() > 80.0 && local.getELE() <= 500.0){
        cout << "está localizado na termosfera" << endl;
    }else if (local.getELE() > 500.0 && local.getELE() <= 800.0){
        cout << "está localizado na exosfera" << endl;
    }else {
        cout << "está localizado no espaço sideral" << endl;
    }
    return 0;
}