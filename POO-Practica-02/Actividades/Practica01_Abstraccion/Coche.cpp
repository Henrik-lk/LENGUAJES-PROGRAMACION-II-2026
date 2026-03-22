#include <iostream>
using namespace std;

class Coche {
private:
    string modelo;
    int anio;
    int velocidad;

public:
    Coche(string m, int a) {
        modelo = m;
        anio = a;
        velocidad = 0;
    }

    void acelerar(int incremento) {
        velocidad += incremento;
        cout << modelo << " aceleró a " << velocidad << " km/h" << endl;
    }

    void frenar(int decremento) {
        velocidad -= decremento;
        if (velocidad < 0) velocidad = 0;
        cout << modelo << " frenó a " << velocidad << " km/h" << endl;
    }
};

int main() {
    Coche coche1("Toyota", 2020);
    Coche coche2("Nissan", 2018);

    coche1.acelerar(30);
    coche1.frenar(10);

    coche2.acelerar(50);
    coche2.frenar(20);

    return 0;
}
