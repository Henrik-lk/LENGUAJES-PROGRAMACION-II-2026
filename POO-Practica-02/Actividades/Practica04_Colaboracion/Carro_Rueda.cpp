#include <iostream>
using namespace std;

class Rueda {
private:
    int tamano;

public:
    Rueda(int t) {
        tamano = t;
    }

    int getTamano() {
        return tamano;
    }
};

class Carro {
private:
    Rueda r1, r2, r3, r4;

public:
    Carro(int t) : r1(t), r2(t), r3(t), r4(t) {}

    void mover() {
        cout << "El carro se mueve con ruedas de tamaño "
             << r1.getTamano() << endl;
    }

    void cambiarRuedas(int nuevoTamano) {
        r1 = Rueda(nuevoTamano);
        r2 = Rueda(nuevoTamano);
        r3 = Rueda(nuevoTamano);
        r4 = Rueda(nuevoTamano);
        cout << "Ruedas cambiadas\n";
    }
};

int main() {
    Carro c(16);

    c.mover();
    c.cambiarRuedas(18);
    c.mover();

    return 0;
}
