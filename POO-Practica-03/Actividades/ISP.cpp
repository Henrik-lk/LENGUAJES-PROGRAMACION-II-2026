//Interfaces específicas
class IAsignacion {
public:
    virtual void asignarUsuario(string usuario) = 0;
};

class IProgreso {
public:
    virtual void actualizarProgreso(int porcentaje) = 0;
};

class IReporte {
public:
    virtual void generarReporte() = 0;
};
//Evitar métodos innecesarios
class TareaUsuario : public IAsignacion, public IProgreso {
public:
    void asignarUsuario(string usuario) override {
        cout << "Asignado a: " << usuario << endl;
    }

    void actualizarProgreso(int porcentaje) override {
        cout << "Progreso: " << porcentaje << "%" << endl;
    }
};
//Interfaces coherentes
class ReporteTareas : public IReporte {
public:
    void generarReporte() override {
        cout << "Generando reporte..." << endl;
    }
};
