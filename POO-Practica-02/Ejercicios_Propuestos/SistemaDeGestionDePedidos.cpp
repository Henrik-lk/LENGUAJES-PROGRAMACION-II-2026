#include <iostream>
#include <string>
using namespace std;

class Avion {
private:
    string modelo;
    int combustible;

public:
    Avion(string m, int c) {
        modelo = m;
        combustible = c;
    }

    int getCombustible() {
        return combustible;
    }

    string getModelo() {
        return modelo;
    }

    bool tieneCombustible(int necesario) {
        return combustible >= necesario;
    }
};

class Mision {
private:
    string destino;
    int combustibleNecesario;

public:
    Mision(string d, int c) {
        destino = d;
        combustibleNecesario = c;
    }

    void iniciarMision(Avion avion) {
        cout << "Avion: " << avion.getModelo() << endl;
        cout << "Destino: " << destino << endl;
        cout << "Combustible disponible: " << avion.getCombustible() << endl;
        cout << "Combustible necesario: " << combustibleNecesario << endl;

        if (avion.tieneCombustible(combustibleNecesario)) {
            cout << "La misión puede realizarse." << endl;
        } else {
            cout << "No hay combustible suficiente." << endl;
        }
    }
};

int main() {
    Avion avion1("Boeing 747", 500);
    Mision mision1("Lima", 300);

    mision1.iniciarMision(avion1);

    return 0;
}
