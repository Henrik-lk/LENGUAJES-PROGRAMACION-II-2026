#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    string nombre;
    int velocidad;

public:
    Auto(string n, int v) {
        nombre = n;
        velocidad = v;
    }

    int avanzar() {
        return velocidad;
    }

    string getNombre() {
        return nombre;
    }
};

class Carrera {
private:
    int distanciaTotal;
    Auto jugador;
    Auto computadora;

public:
    Carrera(int distancia, Auto j, Auto c) : jugador(j), computadora(c) {
        distanciaTotal = distancia;
    }

    void iniciarCarrera() {
        int avanceJugador = 0;
        int avanceCPU = 0;

        while (avanceJugador < distanciaTotal && avanceCPU < distanciaTotal) {
            avanceJugador += jugador.avanzar();
            avanceCPU += computadora.avanzar();

            cout << jugador.getNombre() << " lleva: " << avanceJugador << " metros" << endl;
            cout << computadora.getNombre() << " lleva: " << avanceCPU << " metros" << endl;
            cout << "-------------------------" << endl;
        }

        if (avanceJugador >= distanciaTotal && avanceCPU >= distanciaTotal) {
            cout << "Empate." << endl;
        } else if (avanceJugador >= distanciaTotal) {
            cout << "Ganó " << jugador.getNombre() << endl;
        } else {
            cout << "Ganó " << computadora.getNombre() << endl;
        }
    }
};

int main() {
    Auto jugador("Auto Rojo", 20);
    Auto cpu("Auto Azul", 18);

    Carrera carrera(100, jugador, cpu);
    carrera.iniciarCarrera();

    return 0;
}
