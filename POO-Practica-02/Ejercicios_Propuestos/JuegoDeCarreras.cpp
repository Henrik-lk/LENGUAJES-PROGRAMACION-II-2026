#include <iostream>
using namespace std;
 
class Auto {
private:
    string nombre;
    double posicion;
    double velocidadMax;
public:
    Auto(string n, double vm) : nombre(n), posicion(0), velocidadMax(vm) {}
    string getNombre()   const { return nombre;   }
    double getPosicion() const { return posicion; }
 
    void avanzar(double distancia) {
        double avance = (rand() % (int)velocidadMax) + 10;
        posicion += avance;
        cout << nombre << " avanza " << avance << " m -> Pos: " << posicion << " m" << endl;
    }
};
 
class Carrera {
private:
    double distanciaTotal;
    int    dificultad;   // 1=facil 2=medio 3=dificil
public:
    Carrera(double dist, int dif) : distanciaTotal(dist), dificultad(dif) {}
 
    void simular(Auto& jugador, Auto& cpu) {
        srand((unsigned)time(nullptr));
        cout << "=== CARRERA INICIADA (" << distanciaTotal << " m) ===" << endl;
        int vuelta = 1;
        while (jugador.getPosicion() < distanciaTotal &&
               cpu.getPosicion()    < distanciaTotal) {
            cout << "-- Vuelta " << vuelta++ << " --" << endl;
            jugador.avanzar(distanciaTotal);
            cpu.avanzar(distanciaTotal * dificultad * 0.1);
        }
        determinarGanador(jugador, cpu);
    }
 
    void determinarGanador(const Auto& a, const Auto& b) const {
        cout << "=== RESULTADO ==" << endl;
        if (a.getPosicion() >= distanciaTotal)
            cout << a.getNombre() << " gana la carrera!" << endl;
        else
            cout << b.getNombre() << " (CPU) gana la carrera!" << endl;
    }
};
 
int main() {
    Auto jugador("Jugador", 80.0);
    Auto cpu("CPU",     70.0);
    Carrera carrera(500.0, 2);
    carrera.simular(jugador, cpu);
    return 0;
}
