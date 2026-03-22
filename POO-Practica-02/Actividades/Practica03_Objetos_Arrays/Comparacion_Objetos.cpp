#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;

public:
    string genero;

    Libro(string t, string a, string g) {
        titulo = t;
        autor = a;
        genero = g;
    }

    bool esIgualA(Libro otro) {
        return (this->titulo == otro.titulo && this->autor == otro.autor);
    }

    void mostrar() {
        cout << "Título: " << titulo << ", Autor: " << autor << endl;
    }
};

int main() {
    vector<Libro> libros;

    libros.push_back(Libro("1984", "George Orwell", "Novela"));
    libros.push_back(Libro("1984", "George Orwell", "Distopia"));
    libros.push_back(Libro("El Quijote", "Cervantes", "Clasico"));

    cout << "Comparando libro 0 y libro 1: ";
    if (libros[0].esIgualA(libros[1])) {
        cout << "Son iguales" << endl;
    } else {
        cout << "No son iguales" << endl;
    }

    cout << "Comparando libro 0 y libro 2: ";
    if (libros[0].esIgualA(libros[2])) {
        cout << "Son iguales" << endl;
    } else {
        cout << "No son iguales" << endl;
    }

    return 0;
}
