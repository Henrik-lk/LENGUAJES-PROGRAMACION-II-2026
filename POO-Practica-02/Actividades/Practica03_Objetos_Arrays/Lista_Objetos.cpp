#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Libro {
public:
    string titulo;
    string autor;

    Libro(string t, string a) {
        titulo = t;
        autor = a;
    }

    void mostrar() {
        cout << "Título: " << titulo << ", Autor: " << autor << endl;
    }
};

void agregarLibro(vector<Libro> &lista, string titulo, string autor) {
    lista.push_back(Libro(titulo, autor));
}

void mostrarLibros(vector<Libro> &lista) {
    for (auto &l : lista) {
        l.mostrar();
    }
}

void buscarLibro(vector<Libro> &lista, string titulo) {
    bool encontrado = false;

    for (auto &l : lista) {
        if (l.titulo == titulo) {
            cout << "Libro encontrado:\n";
            l.mostrar();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Libro no encontrado\n";
    }
}

int main() {
    vector<Libro> libros;

    agregarLibro(libros, "1984", "George Orwell");
    agregarLibro(libros, "El Quijote", "Cervantes");
    agregarLibro(libros, "Cien años de soledad", "García Márquez");

    cout << "Lista de libros:\n";
    mostrarLibros(libros);

    cout << "\nBuscando libro:\n";
    buscarLibro(libros, "1984");

    return 0;
}
