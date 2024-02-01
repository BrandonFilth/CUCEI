#include <iostream>

using namespace std;

class Empleado {
private:
    int claveEmpleado;
    string nombre;
    string domicilio;
    float sueldo;
    string reportaA;
public:
    Empleado(int claveEmpleado, string nombre, string domicilio, float sueldo, string reportaA) {
        this->claveEmpleado = claveEmpleado;
        this->nombre = nombre;
        this->domicilio = domicilio;
        this->sueldo = sueldo;
        this->reportaA = reportaA;
    }
    void imprime() {
        cout << "Domicilio:" << this->domicilio << "\nNombre:" << this->nombre << "\nSueldo:" << this->sueldo
             << "\nReporta a:" << this->reportaA << endl;
    }
    void cambiaDomicilio(string domic) {
        this->domicilio = domic;
    }
    void cambiaReportaA(string reporta) {
        this->reportaA = reporta;
    }
    void actualizarSueldo(float suel) {
        this->sueldo = suel;
    }

    bool operator ==(const Empleado& emp) const {
        return claveEmpleado == emp.claveEmpleado;
    }

    bool operator !=(const Empleado& emp) const {
        return !(*this == emp);
    }

    bool operator <(const Empleado& emp) const {
        return claveEmpleado < emp.claveEmpleado;
    }

    bool operator >(const Empleado& emp) const {
        return claveEmpleado > emp.claveEmpleado;
    }

    friend istream& operator >>(istream& input, Empleado& emp) {
        input >> emp.claveEmpleado >> emp.nombre >> emp.domicilio >> emp.sueldo >> emp.reportaA;
        return input;
    }

    friend ostream& operator <<(ostream& output, const Empleado& emp) {
        output << "Clave Empleado: " << emp.claveEmpleado << "\nNombre: " << emp.nombre
               << "\nDomicilio: " << emp.domicilio << "\nSueldo: " << emp.sueldo
               << "\nReporta a: " << emp.reportaA << endl;
        return output;
    }

    Empleado operator + (const Empleado& other) const {
        
        Empleado combined(0, "", "", sueldo + other.sueldo, "");
        return combined;
    }

};

int main() {

    int opcion;
    int opcion2 = 0;
    Empleado jefePersonal(1256,"Juan Perez","El pedregal #28", 3560.0, "Pablo Ramirez");
    Empleado jefePlanta(1257, "Pedro Gutierrez", "Republica de argentina #16", 4250.0, "Pablo Ramirez");
    string domicilio;
    float sueldo;
    string reporta;
    do{

    cout<< "Selecciona un empleado a modificar:\n1)Jefe Planta\n2)Jefe Personal" << endl;
    cin >> opcion;
    }while(opcion !=1 && opcion != 2);

    if (opcion == 1) {
            do{


        cout << "Selecciona una accion:\n1)Cambiar Domicilio\n2)Cambiar sueldo\n3)Imprimir\n4)Cambiar quien reporta"
             << endl;
        cin >> opcion2;

        switch (opcion2) {
            case 1:
                cin.ignore();
                cout << "Ingresa el domicilio:" << endl;
                getline(cin, domicilio);
                jefePlanta.cambiaDomicilio(domicilio);
                break;
            case 2:

                cout << "Ingresa el sueldo:" << endl;
                cin >> sueldo;
                jefePlanta.actualizarSueldo(sueldo);
                break;
            case 3:
                jefePlanta.imprime();
                break;
            case 4:
                cin.ignore();
                cout << "Ingresa el nombre de quien reporta:" << endl;
                getline(cin, reporta);
                jefePlanta.cambiaReportaA(reporta);
                break;
            default:
                cout<<""<<endl;

        }
    }while(opcion !=5);

    }

    else if (opcion == 2) {
        cout << "Selecciona una accion:\n1)Cambiar Domicilio\n2)Cambiar sueldo\n3)Imprimir\n4)Cambiar quien reporta"
             << endl;
        cin >> opcion2;
         do{
            system("cls");
        switch (opcion2) {
            case 1:
                cin.ignore();
                cout << "Ingresa el domicilio:" << endl;
                getline(cin, domicilio);
                jefePersonal.cambiaDomicilio(domicilio);
                break;
            case 2:
                cout << "Ingresa el sueldo:" << endl;
                cin >> sueldo;
                jefePersonal.actualizarSueldo(sueldo);
                break;
            case 3:
                jefePersonal.imprime();
                break;
            case 4:
                cin.ignore();
                cout << "Ingresa el nombre de quien reporta:" << endl;
                getline(cin, reporta);
                jefePersonal.cambiaReportaA(reporta);
                break;
        }
         }while(opcion !=5);
    }

    return 0;
}
