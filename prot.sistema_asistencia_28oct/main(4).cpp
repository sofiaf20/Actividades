#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
struct registro{
   char apellido[30];
   char nombre[30];
   int asistencia;
}Asistencia[30];

int dia, mes, anio;

void fecha();
void datos();
void mostrar();
void cambiar();
void borrar();

void cargarRegistro();
void guardarRegistro();

int contador = 0;

int main(){

     int opcion;
     do{
     cargarRegistro();
     cout<<"-------------------------------------"<<endl;
     cout<<"Sistema de Asistencia"<<endl;
     cout<<"-------------------------------------"<<endl;
     cout<<"1.Fecha."<<endl;
     cout<<"2.Datos de alumno."<<endl;
     cout<<"3.Mostrar listado."<<endl;
     cout<<"4.Cambiar listado."<<endl;
     cout<<"5.Alumno a quitar."<<endl;
     cout<<"0.Finalizar asistencia."<<endl;
     cout<<"-------------------------------------"<<endl;
     cout<<"/Ingresar opcion: "; cin >> opcion;
     cout<<"-------------------------------------"<<endl;

     switch(opcion){
        case 1: fecha();
        cout<<endl;
        break;
        case 2: datos();
        cout<<endl;
        break;
        case 3: mostrar();
        cout<<endl;
        break;
        case 4: cambiar();
        cout<<endl;
        break;
        case 5: borrar();
        cout<<endl;
        break;
        case 0: cout<<"------------Sistema Finalizado--------------"<<endl;
        break;
        default: cout<<"Error valor no encontrado"<<endl;
        break;
    }
    }while(opcion != 0);
    guardarRegistro();

    return 0;
}
void cargarRegistro()
{
    ifstream archivo;
    archivo.open("Listado_Asistencia.txt", ios::in);
    string lista;

        if(archivo.is_open())
        {
            while(!archivo.eof())
            {
                archivo >> lista;
                if(Asistencia[contador].apellido != '\0'
                &&(Asistencia[contador].nombre != '\0' )
                &&(Asistencia[contador].asistencia != 0)
                &&(dia != 0)&&(mes != 0)&&(anio != 0))
                {
                    contador++;
                }
            }
        }
        archivo.close();
}
void guardarRegistro(){

     ofstream Guardar;
     Guardar.open("Listado_Asistencia.txt",ios::out);

     if(Guardar.is_open()){
                    Guardar <<"| Fecha: "<<dia<<"/"<<mes<<"/"<<anio<<"    Asistencia "<<endl;
                    Guardar <<"______________________________________________________"<<endl;
                    for(int i = 0; i < contador; i++)
                    {
                     Guardar <<"| "<<"["<<i<<"] "
                     << Asistencia[i].apellido <<" "<<Asistencia[i].nombre
                     << "    (" <<Asistencia[i].asistencia<<")"<< endl;
                     Guardar <<"______________________________________________________"<<endl;
                    }
                }
                    Guardar.close();
}
void fecha(){
   cout<<"Ingresar fecha: "; cin>>dia; cin>>mes; cin>>anio;
}
void datos(){

    if( contador < 30)
    {
     cout << "Apellido: "; cin >> Asistencia[contador].apellido;
     cout << "Nombre: "; cin >> Asistencia[contador].nombre;
     cout << "Ausente(0)/Presente(1): "; cin >> Asistencia[contador].asistencia;

     contador++;
     }else{
      cout << "¡Máximo de alumnos alcanzado (30)!" << endl;
    }
}
void mostrar(){
    cout <<"Fecha: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    for( int i = 0; i < contador; i++){
            cout <<"_________________________________________"<<endl;
            cout <<"id: "<<"["<<i<<"]"<<endl;
            cout <<"Apellido: " << Asistencia[i].apellido<< endl;
            cout <<"Nombre: " << Asistencia[i].nombre<< endl;
            cout <<"Asistencia: " << Asistencia[i].asistencia<< endl;
            cout <<"_________________________________________"<<endl;
    }
}
void cambiar(){

    int c, remplazar;

    cout<<"1.Fecha."<<endl;
    cout<<"2.Alumno."<<endl;
    cout<<"3.Asistencia."<<endl;
    cout<<endl;
    cout<<"Ingresar eleccion: "; cin >> c;

    switch(c){
    case 1: cout<<"Nueva fecha: ";cin>>dia; cin>>mes; cin>>anio;
    break;
    case 2:
        cout<< endl;
        cout <<"ID de alumno a cambiar: "; cin >> remplazar;

        for (int i = remplazar; i < contador; i++)
        {
        cout<<"Nuevo apellido: "; cin>> Asistencia[i].apellido;
        cout<<"Nuevo nombre: "; cin >> Asistencia[i].nombre;
            if(remplazar > 30){
            cout <<"El ID no existe"<< endl;
            }
        }
    break;
    case 3:
        cout<<endl;
        cout <<"ID de alumno para cambiar asistencia: "; cin >> remplazar;

        for (int i = remplazar; i < contador; i++)
        {
                cout<<"Nueva asistencia: "; cin>>Asistencia[i].asistencia;
                if(remplazar > 30){
                cout <<"El ID no existe"<< endl;
                }
        }
    break;
    default: cout<<"Error valor no encontrado"<<endl;
    break;
    }
}
void borrar(){
    int aBorrar;

    cout <<"ID de alumno a quitar? "; cin >> aBorrar;

     for (int i = aBorrar; i < contador; i++)
     {
         Asistencia[i] = Asistencia[i + 1];
         if(aBorrar > 30){
                cout <<"El ID no existe"<< endl;
         }
     }
     contador--;
     cout <<"El ID ["<<aBorrar<<"] fue quitado..." << endl;
     cout<< endl;
}
