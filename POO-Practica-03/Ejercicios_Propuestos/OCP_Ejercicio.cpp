#include <iostream>
#include <memory>
#include <string>
using namespace std;

class INotificacion {
public:
    virtual void enviar(const string& mensaje) = 0;
    virtual ~INotificacion() = default;
};

class NotificacionEmail : public INotificacion {
public:
    void enviar(const string& mensaje) override {
        cout << "[EMAIL] " << mensaje << '\n';
    }
};

class NotificacionSMS : public INotificacion {
public:
    void enviar(const string& mensaje) override {
        cout << "[SMS] " << mensaje << '\n';
    }
};

class NotificacionPush : public INotificacion {
public:
    void enviar(const string& mensaje) override {
        cout << "[PUSH] " << mensaje << '\n';
    }
};

class GestorNotificaciones {
private:
    shared_ptr<INotificacion> estrategia;

public:
    explicit GestorNotificaciones(shared_ptr<INotificacion> estrategia)
        : estrategia(move(estrategia)) {}

    void notificar(const string& evento) {
        estrategia->enviar("Evento registrado: " + evento);
    }
};

int main() {
    auto email = make_shared<NotificacionEmail>();
    auto sms = make_shared<NotificacionSMS>();
    auto push = make_shared<NotificacionPush>();

    GestorNotificaciones gestor1(email);
    GestorNotificaciones gestor2(sms);
    GestorNotificaciones gestor3(push);

    gestor1.notificar("Nuevo proyecto creado");
    gestor2.notificar("Nuevo comentario agregado");
    gestor3.notificar("Archivo compartido exitosamente");

    return 0;
}
