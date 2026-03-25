//Identificación de módulos
| Módulo      | Responsabilidad                 |
| ----------- | ------------------------------- |
| Usuario     | Gestionar datos del usuario     |
| Tarea       | Gestionar información de tareas |
| Asignación  | Asignar tareas a usuarios       |
| Progreso    | Controlar avance de tareas      |
| FechaLímite | Manejar fechas                  |
  //Clases con una sola responsabilidad
  #include <iostream>
#include <vector>
using namespace std;

// Clase Usuario
class Usuario {
private:
    string nombre;

public:
    Usuario(string nombre) {
        this->nombre = nombre;
    }

    void mostrarUsuario() {
        cout << "Usuario: " << nombre << endl;
    }
};

// Clase Tarea
class Tarea {
private:
    string titulo;

public:
    Tarea(string titulo) {
        this->titulo = titulo;
    }

    void mostrarTarea() {
        cout << "Tarea: " << titulo << endl;
    }
};

// Clase Asignacion
class Asignacion {
public:
    void asignar(Usuario u, Tarea t) {
        cout << "Asignando tarea a usuario..." << endl;
        u.mostrarUsuario();
        t.mostrarTarea();
    }
};

// Clase Progreso
class Progreso {
private:
    int porcentaje;

public:
    Progreso(int p) {
        porcentaje = p;
    }

    void mostrarProgreso() {
        cout << "Progreso: " << porcentaje << "%" << endl;
    }
};

// Clase FechaLimite
class FechaLimite {
private:
    string fecha;

public:
    FechaLimite(string fecha) {
        this->fecha = fecha;
    }

    void mostrarFecha() {
        cout << "Fecha límite: " << fecha << endl;
    }
};
//Cada módulo tiene un único propósito
int main() {
    Usuario u("Juan");
    Tarea t("Desarrollar sistema");

    Asignacion asignar;
    asignar.asignar(u, t);

    Progreso p(50);
    p.mostrarProgreso();

    FechaLimite f("30/03/2026");
    f.mostrarFecha();

    return 0;
}
