#include <iostream>
#include <vector>
using namespace std;

class Cliente {
private:
    string nombre;
    vector<string> carrito;

public:
    Cliente(string n) {
        nombre = n;
    }

    void agregarProducto(string producto) {
        carrito.push_back(producto);
        cout << nombre << " agrego " << producto << endl;
    }

    vector<string> getCarrito() {
        return carrito;
    }
};

class Tienda {
private:
    vector<string> stock;

public:
    void agregarStock(string producto) {
        stock.push_back(producto);
    }

    bool hayProducto(string producto) {
        for (string p : stock) {
            if (p == producto) return true;
        }
        return false;
    }

    void vender(Cliente &cliente) {
        for (string prod : cliente.getCarrito()) {
            if (hayProducto(prod)) {
                cout << "Venta realizada: " << prod << endl;
            } else {
                cout << "No hay stock de: " << prod << endl;
            }
        }
    }
};

int main() {
    Tienda t;
    t.agregarStock("Camisa");
    t.agregarStock("Pantalon");

    Cliente c("Juan");
    c.agregarProducto("Camisa");
    c.agregarProducto("Zapatos");

    t.vender(c);

    return 0;
}
