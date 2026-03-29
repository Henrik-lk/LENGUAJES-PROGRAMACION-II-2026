#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Tarea {
private:
    int id;
    string titulo;

public:
    Tarea(int id, string titulo) : id(id), titulo(std::move(titulo)) {}

    int getId() const { return id; }
    string getTitulo() const { return titulo; }
};

class IRepositorioTareas {
public:
    virtual void guardar(const Tarea& tarea) = 0;
    virtual void listar() const = 0;
    virtual ~IRepositorioTareas() = default;
};

class RepositorioMemoria : public IRepositorioTareas {
private:
    vector<Tarea> tareas;

public:
    void guardar(const Tarea& tarea) override {
        tareas.push_back(tarea);
    }

    void listar() const override {
        cout << "--- Repositorio en memoria ---\n";
        for (const auto& t : tareas) {
            cout << t.getId() << " - " << t.getTitulo() << '\n';
        }
    }
};

class RepositorioArchivoSimulado : public IRepositorioTareas {
private:
    vector<Tarea> respaldo;

public:
    void guardar(const Tarea& tarea) override {
        respaldo.push_back(tarea);
    }

    void listar() const override {
        cout << "--- Repositorio archivo simulado ---\n";
        for (const auto& t : respaldo) {
            cout << t.getId() << " - " << t.getTitulo() << '\n';
        }
    }
};

class GestorAplicacion {
private:
    shared_ptr<IRepositorioTareas> repositorio;

public:
    explicit GestorAplicacion(shared_ptr<IRepositorioTareas> repositorio)
        : repositorio(std::move(repositorio)) {}

    void registrarTarea(int id, const string& titulo) {
        Tarea tarea(id, titulo);
        repositorio->guardar(tarea);
    }

    void mostrarTareas() const {
        repositorio->listar();
    }
};

int main() {
    auto repoMemoria = make_shared<RepositorioMemoria>();
    GestorAplicacion app1(repoMemoria);
    app1.registrarTarea(1, "Modelar clases");
    app1.registrarTarea(2, "Aplicar SOLID");
    app1.mostrarTareas();

    cout << '\n';

    auto repoArchivo = make_shared<RepositorioArchivoSimulado>();
    GestorAplicacion app2(repoArchivo);
    app2.registrarTarea(3, "Generar informe");
    app2.registrarTarea(4, "Subir proyecto a GitHub");
    app2.mostrarTareas();

    return 0;
}
