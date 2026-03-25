//Subclases intercambiables
class Tarea {
public:
    virtual void mostrarDetalle() {
        cout << "Tarea general" << endl;
    }
    virtual ~Tarea() {}
};

class TareaSimple : public Tarea {
public:
    void mostrarDetalle() override {
        cout << "Tarea simple" << endl;
    }
};

class TareaUrgente : public Tarea {
public:
    void mostrarDetalle() override {
        cout << "Tarea urgente" << endl;
    }
};
//No añadir comportamientos incorrectos
class TareaInvalida : public Tarea {
public:
    void eliminarSistema() { } 
};
//Cumplimiento de contratos
int main() {
    Tarea* t1 = new TareaSimple();
    Tarea* t2 = new TareaUrgente();

    t1->mostrarDetalle();
    t2->mostrarDetalle();

    delete t1;
    delete t2;
}
