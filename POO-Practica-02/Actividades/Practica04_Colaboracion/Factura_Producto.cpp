#include <iostream>
#include <vector>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string n, double p, int c) {
        nombre = n;
        precio = p;
        cantidad = c;
    }

    string getNombre() { return nombre; }
    double getPrecio() { return precio; }
    int getCantidad() { return cantidad; }

    void reducirStock(int c) {
        cantidad -= c;
    }
};

class Factura {
private:
    vector<Producto> productos;

public:
    void agregarProducto(Producto &p, int cantidad) {
        if (p.getCantidad() >= cantidad) {
            productos.push_back(p);
            p.reducirStock(cantidad);
            cout << "Producto agregado: " << p.getNombre() << endl;
        } else {
            cout << "Stock insuficiente para " << p.getNombre() << endl;
        }
    }

    void mostrarFactura() {
        double total = 0;
        cout << "\nFactura:\n";
        for (auto p : productos) {
            cout << p.getNombre() << " - S/." << p.getPrecio() << endl;
            total += p.getPrecio();
        }
        cout << "Total: S/." << total << endl;
    }
};

int main() {
    Producto p1("Laptop", 2500, 5);
    Producto p2("Mouse", 50, 2);

    Factura f;
    f.agregarProducto(p1, 1);
    f.agregarProducto(p2, 3); // prueba stock insuficiente

    f.mostrarFactura();

    return 0;
}
