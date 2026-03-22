#include <iostream>
using namespace std;

class Factura {
private:
    int numero;
    string fecha;
    double monto;

public:
    string cliente;

    void setNumero(int n) {
        if (n > 0)
            numero = n;
    }

    void setFecha(string f) {
        fecha = f;
    }

    void setMonto(double m) {
        if (m > 0)
            monto = m;
    }

    int getNumero() { return numero; }
    string getFecha() { return fecha; }
    double getMonto() { return monto; }

    void mostrarFactura() {
        cout << "Factura N°: " << numero << endl;
        cout << "Cliente: " << cliente << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Monto: " << monto << endl;
    }
};

int main() {
    Factura f1, f2;

    f1.cliente = "Carlos";
    f1.setNumero(1);
    f1.setFecha("21/03/2026");
    f1.setMonto(150.5);

    f2.cliente = "Lucia";
    f2.setNumero(2);
    f2.setFecha("22/03/2026");
    f2.setMonto(300);

    f1.mostrarFactura();
    cout << endl;
    f2.mostrarFactura();
}
