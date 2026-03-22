#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
 
struct Producto { string nombre; double precio; int cantidad; };
 
class Inventario {
private:
    vector<Producto> disponibles;
    vector<Producto> agotados;
public:
    void agregarProducto(const Producto& p) {
        if (p.cantidad > 0) disponibles.push_back(p);
        else                agotados.push_back(p);
        cout << "Producto agregado: " << p.nombre << endl;
    }
 
    bool realizarPedido(const string& nombre, int qty, double& totalOut) {
        for (auto& p : disponibles) {
            if (p.nombre == nombre) {
                if (p.cantidad < qty) { cout << "Stock insuficiente." << endl; return false; }
                p.cantidad -= qty;
                totalOut = p.precio * qty;
                if (p.cantidad == 0) {
                    agotados.push_back(p);
                    disponibles.erase(disponibles.begin() +
                        (&p - &disponibles[0]));
                }
                return true;
            }
        }
        cout << "Producto no encontrado." << endl; return false;
    }
 
    void generarFactura(const string& cliente, const string& prod, int qty) {
        double total = 0;
        if (realizarPedido(prod, qty, total)) {
            cout << "--- Factura ---" << endl;
            cout << "Cliente : " << cliente << endl;
            cout << "Producto: " << prod << " x" << qty << endl;
            cout << "Total   : S/" << fixed << setprecision(2) << total << endl;
        }
    }
 
    void mostrarEstado() const {
        cout << "== Disponibles ==" << endl;
        for (const auto& p : disponibles)
            cout << "  " << p.nombre << " | S/" << p.precio << " | Stock: " << p.cantidad << endl;
        cout << "== Agotados ==" << endl;
        for (const auto& p : agotados)
            cout << "  " << p.nombre << endl;
    }
};
 
int main() {
    Inventario inv;
    inv.agregarProducto({"Laptop HP",  2500.0, 5});
    inv.agregarProducto({"Monitor 24",  650.0, 3});
    inv.agregarProducto({"Teclado",      80.0, 0});
    inv.mostrarEstado();
    inv.generarFactura("Pedro Flores", "Laptop HP", 2);
    inv.generarFactura("Maria Quispe", "Monitor 24", 5); // falla
    inv.mostrarEstado();
    return 0;
}
