#include <iostream>
#include <string>
using namespace std;

class IGestorProyectos {
public:
    virtual void crearProyecto(const string& nombre) = 0;
    virtual void listarProyectos() const = 0;
    virtual ~IGestorProyectos() = default;
};

class IGestorComentarios {
public:
    virtual void agregarComentario(const string& comentario) = 0;
    virtual ~IGestorComentarios() = default;
};

class IGestorArchivos {
public:
    virtual void compartirArchivo(const string& archivo) = 0;
    virtual ~IGestorArchivos() = default;
};

class ModuloProyectos : public IGestorProyectos {
public:
    void crearProyecto(const string& nombre) override {
        cout << "Proyecto creado: " << nombre << '\n';
    }

    void listarProyectos() const override {
        cout << "Listando proyectos...\n";
    }
};

class ModuloComentarios : public IGestorComentarios {
public:
    void agregarComentario(const string& comentario) override {
        cout << "Comentario agregado: " << comentario << '\n';
    }
};

class ModuloArchivos : public IGestorArchivos {
public:
    void compartirArchivo(const string& archivo) override {
        cout << "Archivo compartido: " << archivo << '\n';
    }
};

class ModuloColaboracion : public IGestorComentarios, public IGestorArchivos {
public:
    void agregarComentario(const string& comentario) override {
        cout << "[Colaboración] Comentario: " << comentario << '\n';
    }

    void compartirArchivo(const string& archivo) override {
        cout << "[Colaboración] Archivo compartido: " << archivo << '\n';
    }
};

int main() {
    ModuloProyectos proyectos;
    ModuloComentarios comentarios;
    ModuloArchivos archivos;
    ModuloColaboracion colaboracion;

    proyectos.crearProyecto("Plataforma Web");
    proyectos.listarProyectos();

    comentarios.agregarComentario("Falta validar los permisos.");
    archivos.compartirArchivo("mockup.png");

    colaboracion.agregarComentario("Subí la última versión.");
    colaboracion.compartirArchivo("reporte_final.pdf");

    return 0;
}
