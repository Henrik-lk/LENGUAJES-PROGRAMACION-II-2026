#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
using namespace std;

enum class EstadoTarea {
    Pendiente,
    EnProceso,
    Completada
};

class Usuario {
private:
    int id;
    string nombre;
    string correo;

public:
    Usuario(int id, string nombre, string correo)
        : id(id), nombre(std::move(nombre)), correo(std::move(correo)) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getCorreo() const { return correo; }
};

class Tarea {
private:
    int id;
    string titulo;
    string descripcion;
    string fechaLimite;
    EstadoTarea estado;
    int usuarioAsignadoId;

public:
    Tarea(int id, string titulo, string descripcion, string fechaLimite)
        : id(id), titulo(std::move(titulo)), descripcion(std::move(descripcion)),
          fechaLimite(std::move(fechaLimite)), estado(EstadoTarea::Pendiente),
          usuarioAsignadoId(-1) {}

    int getId() const { return id; }
    string getTitulo() const { return titulo; }
    string getDescripcion() const { return descripcion; }
    string getFechaLimite() const { return fechaLimite; }
    EstadoTarea getEstado() const { return estado; }
    int getUsuarioAsignadoId() const { return usuarioAsignadoId; }

    void asignarAUsuario(int idUsuario) {
        usuarioAsignadoId = idUsuario;
    }

    void cambiarEstado(EstadoTarea nuevoEstado) {
        estado = nuevoEstado;
    }

    string estadoComoTexto() const {
        switch (estado) {
            case EstadoTarea::Pendiente: return "Pendiente";
            case EstadoTarea::EnProceso: return "En proceso";
            case EstadoTarea::Completada: return "Completada";
        }
        return "Desconocido";
    }

    void mostrarResumen() const {
        cout << "Tarea #" << id
             << " | Titulo: " << titulo
             << " | Fecha limite: " << fechaLimite
             << " | Estado: " << estadoComoTexto()
             << " | Usuario asignado: " << usuarioAsignadoId
             << '\n';
    }
};

class RepositorioTareas {
private:
    vector<shared_ptr<Tarea>> tareas;

public:
    void agregar(const shared_ptr<Tarea>& tarea) {
        tareas.push_back(tarea);
    }

    shared_ptr<Tarea> buscarPorId(int id) {
        for (auto& tarea : tareas) {
            if (tarea->getId() == id) return tarea;
        }
        return nullptr;
    }

    void listar() const {
        cout << "\n--- LISTA DE TAREAS ---\n";
        for (const auto& tarea : tareas) {
            tarea->mostrarResumen();
        }
    }
};

class AsignadorTareas {
public:
    void asignar(const shared_ptr<Tarea>& tarea, const Usuario& usuario) {
        if (tarea) {
            tarea->asignarAUsuario(usuario.getId());
        }
    }
};

class SeguimientoProgreso {
public:
    void actualizarEstado(const shared_ptr<Tarea>& tarea, EstadoTarea nuevoEstado) {
        if (tarea) {
            tarea->cambiarEstado(nuevoEstado);
        }
    }
};

class ServicioNotificacion {
public:
    void notificarAsignacion(const Usuario& usuario, const Tarea& tarea) {
        cout << "[NOTIFICACION] Se asigno la tarea '" << tarea.getTitulo()
             << "' a " << usuario.getNombre()
             << " (" << usuario.getCorreo() << ")\n";
    }
};

int main() {
    Usuario u1(1, "Ana Torres", "ana@correo.com");
    Usuario u2(2, "Luis Perez", "luis@correo.com");

    auto tarea1 = make_shared<Tarea>(101, "Diseñar interfaz", "Crear prototipo del modulo", "2026-04-05");
    auto tarea2 = make_shared<Tarea>(102, "Implementar backend", "Desarrollar logica de negocio", "2026-04-10");

    RepositorioTareas repositorio;
    AsignadorTareas asignador;
    SeguimientoProgreso seguimiento;
    ServicioNotificacion notificador;

    repositorio.agregar(tarea1);
    repositorio.agregar(tarea2);

    asignador.asignar(tarea1, u1);
    notificador.notificarAsignacion(u1, *tarea1);

    asignador.asignar(tarea2, u2);
    notificador.notificarAsignacion(u2, *tarea2);

    seguimiento.actualizarEstado(tarea1, EstadoTarea::EnProceso);
    seguimiento.actualizarEstado(tarea2, EstadoTarea::Pendiente);

    repositorio.listar();

    return 0;
}
