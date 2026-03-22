#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    int edad;

public:
    string nombre;

    Persona(string n, int e) {
        nombre = n;
        setEdad(e);
    }

    int getEdad() {
        return edad;
    }

    void setEdad(int e) {
        if (e >= 0 && e <= 120) {
            edad = e;
        } else {
            cout << "Edad inválida\n";
        }
    }
};

class CuentaBancaria {
private:
    double saldo;

public:
    string titular;

    CuentaBancaria(string t, double s) {
        titular = t;
        setSaldo(s);
    }

    double getSaldo() {
        return saldo;
    }

    void setSaldo(double s) {
        if (s >= 0) {
            saldo = s;
        } else {
            cout << "Saldo inválido\n";
        }
    }
};

int main() {
    Persona p1("Juan", 20);
    Persona p2("Maria", 25);

    CuentaBancaria c1("Juan", 1000);
    CuentaBancaria c2("Maria", 500);

    p1.setEdad(30);
    c1.setSaldo(1500);

    cout << "Persona 1: " << p1.nombre << ", Edad: " << p1.getEdad() << endl;
    cout << "Persona 2: " << p2.nombre << ", Edad: " << p2.getEdad() << endl;

    cout << "Cuenta 1: " << c1.titular << ", Saldo: " << c1.getSaldo() << endl;
    cout << "Cuenta 2: " << c2.titular << ", Saldo: " << c2.getSaldo() << endl;

    return 0;
}
