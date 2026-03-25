//Definir interfaces (abstracción)
class ITarea {
public:
    virtual void mostrarDetalle() = 0;
};
//Extender sin modificar (herencia)
class TareaBasica : public ITarea {
public:
    void mostrarDetalle() override {
        cout << "Tarea básica" << endl;
    }
};

class TareaUrgente : public ITarea {
public:
    void mostrarDetalle() override {
        cout << "Tarea urgente con alta prioridad" << endl;
    }
};

class TareaConRecordatorio : public ITarea {
public:
    void mostrarDetalle() override {
        cout << "Tarea con recordatorio automático" << endl;
    }
};
//Cambios no afectan otras clases
class SistemaTareas {
public:
    void mostrar(ITarea* tarea) {
        tarea->mostrarDetalle();
    }
};
//Uso en main
int main() {
    SistemaTareas sistema;

    ITarea* t1 = new TareaBasica();
    ITarea* t2 = new TareaUrgente();
    ITarea* t3 = new TareaConRecordatorio();

    sistema.mostrar(t1);
    sistema.mostrar(t2);
    sistema.mostrar(t3);

    delete t1;
    delete t2;
    delete t3;

    return 0;
}
