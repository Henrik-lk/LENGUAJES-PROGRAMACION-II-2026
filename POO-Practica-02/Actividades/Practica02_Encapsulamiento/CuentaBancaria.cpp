#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    double saldo;

public:
    string titular;

    CuentaBancaria() {
        saldo = 0;
    }

    void depositar(double monto) {
        if (monto > 0)
            saldo += monto;
    }

    void retirar(double monto) {
        if (monto <= saldo)
            saldo -= monto;
        else
            cout << "Saldo insuficiente" << endl;
    }

    double getSaldo() {
        return saldo;
    }
};

int main() {
    CuentaBancaria c1;
    c1.titular = "Ana";

    c1.depositar(100);
    c1.retirar(50);
    c1.retirar(100); // inválido

    cout << "Saldo: " << c1.getSaldo() << endl;
}
