#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    int stock;

public:
    Producto(string n, int s) {
        nombre = n;
        stock = s;
    }

    string getNombre() {
        return nombre;
    }

    int getStock() {
        return stock;
    }

    void vender(int cantidad) {
        if (cantidad <= stock) {
            stock -= cantidad;
            cout << "Pedido realizado correctamente." << endl;
        } else {
            cout << "No hay suficiente stock." << endl;
        }
    }
};

class Inventario {
private:
    vector<Producto> productos;

public:
    void agregarProducto(Producto p) {
        productos.push_back(p);
    }

    void mostrarProductos() {
        cout << "Productos en inventario:" << endl;
        for (int i = 0; i < productos.size(); i++) {
            cout << productos[i].getNombre() << " - Stock: " << productos[i].getStock() << endl;
        }
    }

    void realizarPedido(string nombreProducto, int cantidad) {
        for (int i = 0; i < productos.size(); i++) {
            if (productos[i].getNombre() == nombreProducto) {
                productos[i].vender(cantidad);
                return;
            }
        }
        cout << "Producto no encontrado." << endl;
    }
};

int main() {
    Inventario inventario;

    inventario.agregarProducto(Producto("Laptop", 5));
    inventario.agregarProducto(Producto("Mouse", 10));
    inventario.agregarProducto(Producto("Teclado", 3));

    inventario.mostrarProductos();

    cout << "-------------------" << endl;
    inventario.realizarPedido("Laptop", 2);
    inventario.realizarPedido("Teclado", 4);

    cout << "-------------------" << endl;
    inventario.mostrarProductos();

    return 0;
}
