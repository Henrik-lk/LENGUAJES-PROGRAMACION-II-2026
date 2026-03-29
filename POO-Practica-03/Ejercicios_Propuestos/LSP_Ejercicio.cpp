#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class RecursoColaborativo {
protected:
    string nombre;

public:
    explicit RecursoColaborativo(string nombre) : nombre(move(nombre)) {}

    virtual void mostrarDetalle() const {
        cout << "Recurso: " << nombre << '\n';
    }

    virtual string obtenerTipo() const {
        return "Recurso general";
    }

    virtual ~RecursoColaborativo() = default;
};

class ProyectoRecurso : public RecursoColaborativo {
public:
    explicit ProyectoRecurso(string nombre) : RecursoColaborativo(move(nombre)) {}

    void mostrarDetalle() const override {
        cout << "Proyecto: " << nombre << '\n';
    }

    string obtenerTipo() const override {
        return "Proyecto";
    }
};

class ComentarioRecurso : public RecursoColaborativo {
public:
    explicit ComentarioRecurso(string nombre) : RecursoColaborativo(move(nombre)) {}

    void mostrarDetalle() const override {
        cout << "Comentario: " << nombre << '\n';
    }

    string obtenerTipo() const override {
        return "Comentario";
    }
};

class ArchivoRecurso : public RecursoColaborativo {
public:
    explicit ArchivoRecurso(string nombre) : RecursoColaborativo(move(nombre)) {}

    void mostrarDetalle() const override {
        cout << "Archivo: " << nombre << '\n';
    }

    string obtenerTipo() const override {
        return "Archivo";
    }
};

void procesarRecursos(const vector<shared_ptr<RecursoColaborativo>>& recursos) {
    for (const auto& r : recursos) {
        r->mostrarDetalle();
        cout << "Tipo detectado: " << r->obtenerTipo() << "\n\n";
    }
}

int main() {
    vector<shared_ptr<RecursoColaborativo>> recursos;
    recursos.push_back(make_shared<ProyectoRecurso>("Sistema de Ventas"));
    recursos.push_back(make_shared<ComentarioRecurso>("Corregir interfaz del panel"));
    recursos.push_back(make_shared<ArchivoRecurso>("manual_usuario.docx"));

    procesarRecursos(recursos);

    return 0;
}
