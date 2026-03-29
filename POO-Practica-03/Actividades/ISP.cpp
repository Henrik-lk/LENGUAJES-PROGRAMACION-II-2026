#include <iostream>
#include <string>
using namespace std;

class ICreacionTarea {
public:
    virtual void crearTarea(const string& titulo) = 0;
    virtual ~ICreacionTarea() = default;
};

class IAsignacionTarea {
public:
    virtual void asignarTarea(const string& titulo, const string& usuario) = 0;
    virtual ~IAsignacionTarea() = default;
};

class ISeguimientoTarea {
public:
    virtual void actualizarEstado(const string& titulo, const string& estado) = 0;
    virtual ~ISeguimientoTarea() = default;
};

class CreadorTareas : public ICreacionTarea {
public:
    void crearTarea(const string& titulo) override {
        cout << "Se creo la tarea: " << titulo << '\n';
    }
};

class AsignadorTareas : public IAsignacionTarea {
public:
    void asignarTarea(const string& titulo, const string& usuario) override {
        cout << "Se asigno la tarea '" << titulo << "' al usuario " << usuario << '\n';
    }
};

class MonitorTareas : public ISeguimientoTarea {
public:
    void actualizarEstado(const string& titulo, const string& estado) override {
        cout << "La tarea '" << titulo << "' ahora esta en estado: " << estado << '\n';
    }
};

class CoordinadorProyecto : public ICreacionTarea, public IAsignacionTarea {
public:
    void crearTarea(const string& titulo) override {
        cout << "[Coordinador] Nueva tarea creada: " << titulo << '\n';
    }

    void asignarTarea(const string& titulo, const string& usuario) override {
        cout << "[Coordinador] Tarea '" << titulo << "' asignada a " << usuario << '\n';
    }
};

int main() {
    CreadorTareas creador;
    AsignadorTareas asignador;
    MonitorTareas monitor;
    CoordinadorProyecto coordinador;

    creador.crearTarea("Diseñar base de datos");
    asignador.asignarTarea("Diseñar base de datos", "Carlos");
    monitor.actualizarEstado("Diseñar base de datos", "En proceso");

    coordinador.crearTarea("Documentar API");
    coordinador.asignarTarea("Documentar API", "Lucia");

    return 0;
}
