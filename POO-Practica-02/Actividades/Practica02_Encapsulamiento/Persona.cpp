#include <iostream>
using namespace std;

class Persona {
private:
    string dni;
    int edad;
    string genero;

public:
    string nombre; // público

    // SETTERS
    void setDNI(string d) {
        dni = d;
    }

    void setEdad(int e) {
        if (e > 0 && e < 120)
            edad = e;
        else
            cout << "Edad invalida" << endl;
    }

    void setGenero(string g) {
        if (g == "M" || g == "F")
            genero = g;
        else
            cout << "Genero invalido" << endl;
    }

    // GETTERS
    string getDNI() { return dni; }
    int getEdad() { return edad; }
    string getGenero() { return genero; }
};

int main() {
    Persona p1;
    p1.nombre = "Luis";
    p1.setDNI("12345678");
    p1.setEdad(20);
    p1.setGenero("M");

    cout << p1.nombre << " - DNI: " << p1.getDNI() << endl;
}
