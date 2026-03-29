#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Usuario {
private:
    int id;
    string nombre;

public:
    Usuario(int id, string nombre) : id(id), nombre(move(nombre)) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
};

class Proyecto {
private:
    int id;
    string nombre;
    string descripcion;

public:
    Proyecto(int id, string nombre, string descripcion)
        : id(id), nombre(move(nombre)), descripcion(move(descripcion)) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getDescripcion() const { return descripcion; }

    void mostrar() const {
        cout << "Proyecto #" << id << " | " << nombre
             << " | " << descripcion << '\n';
    }
};

class Comentario {
private:
    int id;
    string contenido;
    string autor;

public:
    Comentario(int id, string contenido, string autor)
        : id(id), contenido(move(contenido)), autor(move(autor)) {}

    int getId() const { return id; }
    string getContenido() const { return contenido; }
    string getAutor() const { return autor; }

    void mostrar() const {
        cout << "Comentario #" << id << " | Autor: " << autor
             << " | " << contenido << '\n';
    }
};

class ArchivoCompartido {
private:
    int id;
    string nombreArchivo;
    string tipoArchivo;

public:
    ArchivoCompartido(int id, string nombreArchivo, string tipoArchivo)
        : id(id), nombreArchivo(move(nombreArchivo)), tipoArchivo(move(tipoArchivo)) {}

    int getId() const { return id; }
    string getNombreArchivo() const { return nombreArchivo; }
    string getTipoArchivo() const { return tipoArchivo; }

    void mostrar() const {
        cout << "Archivo #" << id << " | " << nombreArchivo
             << " | Tipo: " << tipoArchivo << '\n';
    }
};

class RepositorioProyectos {
private:
    vector<Proyecto> proyectos;

public:
    void guardar(const Proyecto& proyecto) {
        proyectos.push_back(proyecto);
    }

    void listar() const {
        cout << "\n--- PROYECTOS ---\n";
        for (const auto& p : proyectos) {
            p.mostrar();
        }
    }
};

class RepositorioComentarios {
private:
    vector<Comentario> comentarios;

public:
    void guardar(const Comentario& comentario) {
        comentarios.push_back(comentario);
    }

    void listar() const {
        cout << "\n--- COMENTARIOS ---\n";
        for (const auto& c : comentarios) {
            c.mostrar();
        }
    }
};

class RepositorioArchivos {
private:
    vector<ArchivoCompartido> archivos;

public:
    void guardar(const ArchivoCompartido& archivo) {
        archivos.push_back(archivo);
    }

    void listar() const {
        cout << "\n--- ARCHIVOS ---\n";
        for (const auto& a : archivos) {
            a.mostrar();
        }
    }
};

int main() {
    Usuario u1(1, "Ana");
    Usuario u2(2, "Luis");

    Proyecto p1(101, "Sistema Académico", "Gestión de matrícula y notas");
    Comentario c1(201, "Avanzar con el módulo de reportes", u1.getNombre());
    ArchivoCompartido a1(301, "diagrama_clases.pdf", "PDF");

    RepositorioProyectos repoProyectos;
    RepositorioComentarios repoComentarios;
    RepositorioArchivos repoArchivos;

    repoProyectos.guardar(p1);
    repoComentarios.guardar(c1);
    repoArchivos.guardar(a1);

    repoProyectos.listar();
    repoComentarios.listar();
    repoArchivos.listar();

    return 0;
}
