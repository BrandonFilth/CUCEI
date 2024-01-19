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
    Empleado() {
        nombre = " ";
        domicilio = " ";
        sueldo = 0;
        reportaA = " ";
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
    void agregarNombre(string name){
        this-> nombre = name;

    }
};

int main() {

    int opcion;
    int opcion2 = 0;
    Empleado jefePersonal;
    Empleado jefePlanta;
    string domicilio;
    float sueldo;
    string reporta;
    cout << "Selecciona un empleado a modificar:\n1)Jefe Planta\n2)Jefe Personal" << endl;
    cin >> opcion;

    if (opcion == 1) {
            do{


        cout << "Selecciona una accion:\n1)Cambiar Domicilio\n2)Cambiar sueldo\n3)Imprimir\n4)Cambiar quien reporta"
             << endl;
        cin >> opcion2;

        switch (opcion2) {
            case 1:
                jefePlanta.agregarNombre("Carlos Perez");
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
        switch (opcion2) {
            case 1:
                jefePersonal.agregarNombre("Juan castro");
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
