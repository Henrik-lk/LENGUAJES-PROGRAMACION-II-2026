//Alto nivel no depende de bajo nivel
class INotificacion {
public:
    virtual void enviar(string mensaje) = 0;
};
//Uso de interfaces
class Email : public INotificacion {
public:
    void enviar(string mensaje) override {
        cout << "Email: " << mensaje << endl;
    }
};

class SMS : public INotificacion {
public:
    void enviar(string mensaje) override {
        cout << "SMS: " << mensaje << endl;
    }
};
//Bajo nivel no afecta alto nivel
class GestorTareas {
private:
    INotificacion* notificador;

public:
    GestorTareas(INotificacion* n) {
        this->notificador = n;
    }

    void completarTarea() {
        notificador->enviar("Tarea completada");
    }
};
//Uso en main
int main() {
    INotificacion* email = new Email();
    GestorTareas gestor(email);

    gestor.completarTarea();

    delete email;
}
