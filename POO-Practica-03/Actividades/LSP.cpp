#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class TareaBase {
protected:
    string titulo;

public:
    explicit TareaBase(string titulo) : titulo(std::move(titulo)) {}
    virtual void mostrarDetalle() const {
        cout << "Tarea: " << titulo << '\n';
    }
    virtual bool puedeMarcarseComoCompletada() const {
        return true;
    }
    virtual ~TareaBase() = default;
};

class TareaSimple : public TareaBase {
public:
    explicit TareaSimple(string titulo) : TareaBase(std::move(titulo)) {}

    void mostrarDetalle() const override {
        cout << "Tarea simple: " << titulo << '\n';
    }
};

class TareaConSubtareas : public TareaBase {
private:
    int subtareasPendientes;

public:
    TareaConSubtareas(string titulo, int subtareasPendientes)
        : TareaBase(std::move(titulo)), subtareasPendientes(subtareasPendientes) {}

    void mostrarDetalle() const override {
        cout << "Tarea compuesta: " << titulo
             << " | Subtareas pendientes: " << subtareasPendientes << '\n';
    }

    bool puedeMarcarseComoCompletada() const override {
        return subtareasPendientes == 0;
    }
};

class TareaUrgente : public TareaBase {
private:
    int prioridad;

public:
    TareaUrgente(string titulo, int prioridad)
        : TareaBase(std::move(titulo)), prioridad(prioridad) {}

    void mostrarDetalle() const override {
        cout << "Tarea urgente: " << titulo
             << " | Prioridad: " << prioridad << '\n';
    }
};

void revisarTareas(const vector<shared_ptr<TareaBase>>& tareas) {
    for (const auto& tarea : tareas) {
        tarea->mostrarDetalle();
        cout << "¿Puede completarse? "
             << (tarea->puedeMarcarseComoCompletada() ? "Si" : "No") << "\n\n";
    }
}

int main() {
    vector<shared_ptr<TareaBase>> tareas;
    tareas.push_back(make_shared<TareaSimple>("Actualizar manual"));
    tareas.push_back(make_shared<TareaConSubtareas>("Desarrollar modulo de reportes", 2));
    tareas.push_back(make_shared<TareaUrgente>("Corregir error critico", 1));

    revisarTareas(tareas);
    return 0;
}
