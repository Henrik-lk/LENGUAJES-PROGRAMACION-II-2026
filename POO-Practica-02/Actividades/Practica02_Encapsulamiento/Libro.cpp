#include <iostream>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string genero;

public:
    void setTitulo(string t) { titulo = t; }
    void setAutor(string a) { autor = a; }
    void setGenero(string g) { genero = g; }

    string getTitulo() { return titulo; }
    string getAutor() { return autor; }
    string getGenero() { return genero; }

    void mostrarInfoLibro() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Genero: " << genero << endl;
    }
};

int main() {
    Libro l1, l2;

    l1.setTitulo("C++ Basico");
    l1.setAutor("Juan");
    l1.setGenero("Educativo");

    l2.setTitulo("POO");
    l2.setAutor("Maria");
    l2.setGenero("Tecnico");

    l1.mostrarInfoLibro();
    cout << endl;
    l2.mostrarInfoLibro();
}
