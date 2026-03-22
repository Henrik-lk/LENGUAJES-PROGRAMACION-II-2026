#include <iostream>
using namespace std;

class Tienda {
private:
    string nombre;
    string direccion;
    string tipo;
    int stock;

public:
    Tienda(string n, string d, string t) {
        nombre = n;
        direccion = d;
        tipo = t;
        stock = 0;
    }

    void agregarProducto(int cantidad) {
        stock += cantidad;
        cout << "Stock actual: " << stock << endl;
    }

    void venderProducto(int cantidad) {
        if (cantidad <= stock) {
            stock -= cantidad;
            cout << "Venta realizada. Stock restante: " << stock << endl;
        } else {
            cout << "No hay suficiente stock." << endl;
        }
    }
};

int main() {
    Tienda tienda1("ModaX", "Av. Perú", "Ropa");
    Tienda tienda2("TechStore", "Av. Lima", "Electrónicos");

    tienda1.agregarProducto(50);
    tienda1.venderProducto(20);

    tienda2.agregarProducto(30);
    tienda2.venderProducto(40);

    return 0;
}
