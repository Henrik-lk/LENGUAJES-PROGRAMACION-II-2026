#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;
    vector<string> historial;

public:
    CuentaBancaria(string titularCuenta, double saldoInicial) {
        titular = titularCuenta;
        if (saldoInicial >= 0) {
            saldo = saldoInicial;
        } else {
            saldo = 0;
        }
        historial.push_back("Cuenta creada para: " + titular);
    }

    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            historial.push_back("Deposito de S/" + to_string((int)monto));
            cout << "Deposito realizado. Saldo actual: S/" << saldo << endl;
        } else {
            historial.push_back("Intento de deposito invalido");
            cout << "Monto invalido." << endl;
        }
    }

    void retirar(double monto) {
        if (monto <= 0) {
            historial.push_back("Intento de retiro invalido");
            cout << "Monto invalido." << endl;
        } else if (monto <= saldo) {
            saldo -= monto;
            historial.push_back("Retiro de S/" + to_string((int)monto));
            cout << "Retiro realizado. Saldo actual: S/" << saldo << endl;
        } else {
            historial.push_back("Retiro rechazado de S/" + to_string((int)monto) + " por saldo insuficiente");
            cout << "Retiro rechazado. Saldo insuficiente." << endl;
        }
    }

    void mostrarHistorial() {
        cout << "\n=== HISTORIAL DE MOVIMIENTOS ===" << endl;
        for (int i = 0; i < historial.size(); i++) {
            cout << historial[i] << endl;
        }
        cout << "Saldo final: S/" << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta("Henrik", 1000);

    cuenta.depositar(500);
    cuenta.retirar(200);
    cuenta.retirar(10000);

    cuenta.mostrarHistorial();

    return 0;
}
