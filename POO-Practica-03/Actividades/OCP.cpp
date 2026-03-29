#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Tarea {
private:
    string titulo;
public:
    explicit Tarea(string titulo) : titulo(std::move(titulo)) {}
    string getTitulo() const { return titulo; }
};

class INotificador {
public:
    virtual void enviar(const Tarea& tarea, const string& destinatario) = 0;
    virtual ~INotificador() = default;
};

class NotificadorEmail : public INotificador {
public:
    void enviar(const Tarea& tarea, const string& destinatario) override {
        cout << "[EMAIL] Tarea '" << tarea.getTitulo()
             << "' enviada a " << destinatario << '\n';
    }
};

class NotificadorSMS : public INotificador {
public:
    void enviar(const Tarea& tarea, const string& destinatario) override {
        cout << "[SMS] Tarea '" << tarea.getTitulo()
             << "' enviada a " << destinatario << '\n';
    }
};

class NotificadorPush : public INotificador {
public:
    void enviar(const Tarea& tarea, const string& destinatario) override {
        cout << "[PUSH] Tarea '" << tarea.getTitulo()
             << "' enviada a " << destinatario << '\n';
    }
};

class GestorEnvios {
private:
    shared_ptr<INotificador> notificador;

public:
    explicit GestorEnvios(shared_ptr<INotificador> notificador)
        : notificador(std::move(notificador)) {}

    void procesar(const Tarea& tarea, const string& destinatario) {
        notificador->enviar(tarea, destinatario);
    }
};

int main() {
    Tarea tarea("Preparar informe final");

    auto email = make_shared<NotificadorEmail>();
    auto sms = make_shared<NotificadorSMS>();
    auto push = make_shared<NotificadorPush>();

    GestorEnvios envio1(email);
    GestorEnvios envio2(sms);
    GestorEnvios envio3(push);

    envio1.procesar(tarea, "ana@correo.com");
    envio2.procesar(tarea, "999888777");
    envio3.procesar(tarea, "usuario_app");

    return 0;
}
