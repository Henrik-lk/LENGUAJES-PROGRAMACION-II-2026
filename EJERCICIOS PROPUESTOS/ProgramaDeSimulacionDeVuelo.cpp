#include <iostream>
#include <string>
using namespace std;
 
class Avion {
private:
    string matricula;
    double combustibleMax;
    double combustibleActual;
    int    capacidadTripulacion;
public:
    Avion(string m, double cMax, int cap)
        : matricula(m), combustibleMax(cMax), combustibleActual(cMax), capacidadTripulacion(cap) {}
 
    string getMatricula()    const { return matricula;           }
    double getCombustible()  const { return combustibleActual;   }
    int    getCapacidad()    const { return capacidadTripulacion;}
 
    bool tieneCombustibleParaVolar(double distancia) const {
        double consumo = distancia * 0.12; // 0.12 L por km
        return combustibleActual >= consumo;
    }
 
    void consumirCombustible(double distancia) {
        combustibleActual -= distancia * 0.12;
    }
 
    void mostrarInfo() const {
        cout << "Avion: " << matricula << " | Combustible: " << combustibleActual
             << " L / " << combustibleMax << " L" << endl;
    }
};
 
class Mision {
private:
    string destino;
    double distanciaKm;
    int    tripulacionNecesaria;
    double duracionHoras;
public:
    Mision(string d, double dist, int trip, double dur)
        : destino(d), distanciaKm(dist), tripulacionNecesaria(trip), duracionHoras(dur) {}
 
    bool simular(Avion& avion) {
        cout << "=== MISION: " << destino << " ===" << endl;
        cout << "Distancia : " << distanciaKm << " km" << endl;
        cout << "Duracion  : " << duracionHoras << " h" << endl;
        cout << "Tripulacion requerida: " << tripulacionNecesaria << endl;
 
        if (avion.getCapacidad() < tripulacionNecesaria) {
            cout << "Mision FALLIDA: tripulacion insuficiente." << endl;
            return false;
        }
        if (!avion.tieneCombustibleParaVolar(distanciaKm)) {
            cout << "Mision FALLIDA: combustible insuficiente." << endl;
            return false;
        }
        avion.consumirCombustible(distanciaKm);
        cout << "Mision COMPLETADA con exito!" << endl;
        avion.mostrarInfo();
        return true;
    }
};
 
int main() {
    Avion boeing("OB-1234", 5000.0, 6);
    boeing.mostrarInfo();
 
    Mision m1("Lima -> Cusco",  1100.0, 4, 1.5);
    Mision m2("Lima -> Miami", 40000.0, 6, 9.0); // combustible insuficiente
 
    m1.simular(boeing);
    cout << endl;
    m2.simular(boeing);
    return 0;
}
