#include <iostream>
using namespace std;

class Animal {
private:
    string nombre;
    int edad;
    string tipo;

public:
    Animal(string n, int e, string t) {
        nombre = n;
        edad = e;
        tipo = t;
    }

    void alimentar() {
        cout << nombre << " esta comiendo." << endl;
    }

    void hacerSonido() {
        cout << nombre << " hace un sonido." << endl;
    }
};

int main() {
    Animal perro("Max", 3, "Perro");
    Animal gato("Luna", 2, "Gato");
    Animal caballo("Spirit", 5, "Caballo");

    perro.alimentar();
    perro.hacerSonido();

    gato.alimentar();
    gato.hacerSonido();

    caballo.alimentar();
    caballo.hacerSonido();

    return 0;
}
