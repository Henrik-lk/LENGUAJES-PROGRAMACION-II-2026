#include <iostream>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    bool prestado;

public:
    Libro(string t, string a) {
        titulo = t;
        autor = a;
        prestado = false;
    }

    bool estaPrestado() {
        return prestado;
    }

    void prestar() {
        if (!prestado) {
            prestado = true;
            cout << "Libro prestado: " << titulo << endl;
        } else {
            cout << "El libro ya esta prestado.\n";
        }
    }

    void devolver() {
        prestado = false;
        cout << "Libro devuelto: " << titulo << endl;
    }
};

class Biblioteca {
public:
    void prestarLibro(Libro &libro) {
        libro.prestar();
    }
};

int main() {
    Libro libro1("C++", "Stroustrup");
    Biblioteca b;

    b.prestarLibro(libro1);
    b.prestarLibro(libro1); // prueba si ya esta prestado
    libro1.devolver();

    return 0;
}
