#include <iostream>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    string grado;
    float nota;

public:
    Estudiante(string n, int e, string g) {
        nombre = n;
        edad = e;
        grado = g;
        nota = 0;
    }

    void tomarExamen() {
        cout << nombre << " está tomando el examen." << endl;
    }

    void recibirCalificacion(float n) {
        nota = n;
        cout << nombre << " recibió la nota " << nota << endl;
    }
};

int main() {
    Estudiante est1("Ana", 19, "3er ciclo");
    Estudiante est2("Luis", 20, "4to ciclo");

    est1.tomarExamen();
    est1.recibirCalificacion(15);

    est2.tomarExamen();
    est2.recibirCalificacion(18);

    return 0;
}
