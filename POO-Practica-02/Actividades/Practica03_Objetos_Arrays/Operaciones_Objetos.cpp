#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;

    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    void mostrar() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

void mostrarLista(vector<Persona> &lista) {
    for (auto &p : lista) {
        p.mostrar();
    }
}

void eliminarPersona(vector<Persona> &lista, string nombre) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].nombre == nombre) {
            lista.erase(lista.begin() + i);
            cout << "Persona eliminada\n";
            return;
        }
    }
    cout << "Persona no encontrada\n";
}

void actualizarEdad(vector<Persona> &lista, string nombre, int nuevaEdad) {
    for (auto &p : lista) {
        if (p.nombre == nombre) {
            p.edad = nuevaEdad;
            cout << "Edad actualizada\n";
            return;
        }
    }
    cout << "Persona no encontrada\n";
}

int main() {
    vector<Persona> lista;

    lista.push_back(Persona("Juan", 20));
    lista.push_back(Persona("Maria", 25));
    lista.push_back(Persona("Carlos", 30));

    cout << "Lista inicial:\n";
    mostrarLista(lista);

    actualizarEdad(lista, "Maria", 28);

    eliminarPersona(lista, "Juan");

    cout << "\nLista final:\n";
    mostrarLista(lista);

    return 0;
}
