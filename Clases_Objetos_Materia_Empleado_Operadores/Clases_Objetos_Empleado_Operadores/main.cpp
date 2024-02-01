#include <iostream>

using namespace std;

class Materia{
private:
    int clave;
    string nombre;
    string profesorTit;
    string libroTexto;

public:
    Materia(int claveN, string nombreN, string profesor, string libro){
        this->clave = claveN;
        this->nombre = nombreN;
        this->profesorTit = profesor;
        this->libroTexto = libro;
    }

    void imprime(){
        cout<<"Clave:"<<this->clave<<"\nNombre:"<<this->nombre<<"\nProfesor:"<<
        this->profesorTit<<"\nLibro:"<<this->libroTexto<<endl;
    }
    void cambiaClave(int claveN){
        this->clave = claveN;

    }
    void cambiaProfe(string profesorN){
        this->profesorTit = profesorN;
    }
     bool operator==(const Materia& other) const {
        return clave == other.clave;
    }

    bool operator!=(const Materia& mate) const {
        return !(*this == mate);
    }

    bool operator<(const Materia& mate) const {
        return clave < mate.clave;
    }

    bool operator>(const Materia& mate) const {
        return clave > mate.clave;
    }

    friend istream& operator>>(istream& input, Materia& materia) {
    	std::cout<<"Ingresa la Clave de la materia:";
        input >> materia.clave;
        std::cout<<"Ingresa el nombre de la materia:";
		input >> materia.nombre;
		std::cout<<"Ingresa el profesor de la materia:";
		input >> materia.profesorTit;
		std::cout<<"Ingresa el libro de texto de la materia:";
		input >> materia.libroTexto;
        return input;
    }

    friend ostream& operator<<(ostream& output, const Materia& materia) {
        output << "Clave: " << materia.clave << "\nNombre: " << materia.nombre
               << "\nProfesor: " << materia.profesorTit << "\nLibro: " << materia.libroTexto << endl;
        return output;
    }

    Materia operator+(const Materia& other) const {
        Materia combined(0, "", "", "");
        combined.nombre = this->nombre + " & " + other.nombre;
        return combined;
    }

};

void menu(Materia &materia){
    int opcion, clave;
    string nombre, profesor, libro;

    do{
    system("CLS");
    cout<<"1)Cambiar clave\n2)Cambiar profesor\n3)Imprimir detalles\n4)salir\nSelecciona una opcion:"<<endl;
    cin>>opcion;

    switch (opcion){
    case 1:
        cout<<"Ingresa la nueva clave:"<<endl;
        cin>>clave;
        materia.cambiaClave(clave);
        break;
    case 2:
        cout<<"Ingresa el nombre del profesor:"<<endl;
        cin.ignore();
        getline(cin, profesor);
        materia.cambiaProfe(profesor);
    case 3:
        materia.imprime();
        system("pause");
        break;

    default:
        cout<<"Opcion invalida"<<endl;
        system("pause");
        break;
    }
    }while(opcion !=4);
}

int main(){
    int opcion;
    Materia programacion(8812,"Programacion", "Jose Cardenas", "Fundamentos de programacion");
    Materia basesDatos(8815, "Bases de Datos", "Manuel Perez", "Las bases de datos");
     std::cin>>programacion;
    do{
            system("CLS");
    cout<<"Materias disponibles:\n1)Programacion\n2)Bases de datos\nSeleccione una materia a modificar:"<<endl;
    cin>>opcion;

    if(opcion ==1){
        menu(programacion);
    }
    else if (opcion == 2){
        menu(basesDatos);
    }
    else{
        cout<<"Opcion invalida"<<endl;
        system("pause");
    }
    }while(opcion != 3);
    return 0;

}
