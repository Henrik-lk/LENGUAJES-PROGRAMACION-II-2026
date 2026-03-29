#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class IRepositorioComentarios {
public:
    virtual void guardarComentario(const string& comentario) = 0;
    virtual void listarComentarios() const = 0;
    virtual ~IRepositorioComentarios() = default;
};

class RepositorioComentariosMemoria : public IRepositorioComentarios {
private:
    vector<string> comentarios;

public:
    void guardarComentario(const string& comentario) override {
        comentarios.push_back(comentario);
    }

    void listarComentarios() const override {
        cout << "\n--- Comentarios en memoria ---\n";
        for (const auto& c : comentarios) {
            cout << c << '\n';
        }
    }
};

class RepositorioComentariosArchivoSimulado : public IRepositorioComentarios {
private:
    vector<string> comentarios;

public:
    void guardarComentario(const string& comentario) override {
        comentarios.push_back("[ARCHIVO] " + comentario);
    }

    void listarComentarios() const override {
        cout << "\n--- Comentarios en archivo simulado ---\n";
        for (const auto& c : comentarios) {
            cout << c << '\n';
        }
    }
};

class GestorColaboracion {
private:
    shared_ptr<IRepositorioComentarios> repositorio;

public:
    explicit GestorColaboracion(shared_ptr<IRepositorioComentarios> repositorio)
        : repositorio(move(repositorio)) {}

    void registrarComentario(const string& comentario) {
        repositorio->guardarComentario(comentario);
    }

    void mostrarComentarios() const {
        repositorio->listarComentarios();
    }
};

int main() {
    auto repoMemoria = make_shared<RepositorioComentariosMemoria>();
    GestorColaboracion gestor1(repoMemoria);

    gestor1.registrarComentario("Se creó el proyecto principal.");
    gestor1.registrarComentario("Se debe mejorar la documentación.");
    gestor1.mostrarComentarios();

    auto repoArchivo = make_shared<RepositorioComentariosArchivoSimulado>();
    GestorColaboracion gestor2(repoArchivo);

    gestor2.registrarComentario("Archivo adjunto para revisión.");
    gestor2.registrarComentario("Comentario guardado en otro medio.");
    gestor2.mostrarComentarios();

    return 0;
}
