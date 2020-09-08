/*
Vamos a hacer un ejemplo completo que use arreglos (�arrays�), y estructuras 
(�struct�) y que adem�s manipule strings.
La idea va a ser la siguiente: Crearemos un programa que pueda almacenar datos de
hasta 1000 archivos (archivos de computadora). Para cada archivo, debe guardar los 
siguientes datos: Nombre del archivo (max 40 letras), Tama�o (en KB, n�mero de 0 
a 2.000.000.000). El programa mostrar� un men� que permita al usuario las 
siguientes operaciones:
1- A�adir datos de un nuevo archivo
2- Mostrar los nombres de todos los archivos almacenados
3- Mostrar archivos que sean de m�s de un cierto tama�o (por ejemplo, 2000 KB).
4- Ver todos los datos de un cierto archivo (a partir de su nombre)
5- Salir de la aplicaci�n (como todav�a no sabemos almacenar los datos, �stos se 
perder�n).
No deber�a resultar dif�cil. Vamos a ver directamente una de las formas en que se
podr�a plantear y luego comentaremos alguna de las mejoras que se podr�a 
(incluso se deber�a) hacer.
Una opci�n que podemos a tomar para resolver este problema es la de contar el 
n�mero de archivos que tenemos almacenados, y as� podremos a�adir de uno en uno. 
Si tenemos 0 archivos, deberemos almacenar la siguiente (la primera) en la 
posici�n 0; si tenemos dos archivos, ser�n la 0 y la 1, luego a�adiremos en la 
posici�n 2; en general, si tenemos �n� archivos, a�adiremos cada nueva ficha en la 
posici�n �n�. Por otra parte, para revisar todas las archivos, recorreremos desde 
la posici�n 0 hasta la n-1, haciendo algo como
for (i=0; i<=n-1; i++) { //... m�s �rdenes ... }
O algo como:
for (i=0; i<n; i++) { //... m�s �rdenes ... }
El resto del programa no es dif�cil: sabemos leer y comparar textos y n�meros. 
S�lo haremos dos consideraciones:
-No se comportar� correctamente si los textos (nombre del archivo, por ejemplo) 
contienen espacios, porque a�n no sabemos leer textos con espacios.
-Hemos limitado el n�mero de archivos a 1000, as� que, si nos piden a�adir, 
deber�amos asegurarnos antes de que todav�a tenemos hueco disponible.
Con todo esto, nuestro fuente quedar�a as�:
*/

// Array con muchos structs y men� para manejarla
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
 
struct FileData
{
    string name;// Nombre del archivo
    long size;// El tama�o en bytes
};
 
int numberOfFiles=0;// N�mero de archivos que ya tenemos
int i ;// Para bucles
int option;// La option del menu que elija el usuario
 
string tempText;// Para pedir datos al usuario
int tempNumber;
 
int main(int argc, char *argv[])
{
    //FileData* files = new FileData[1000];
    FileData files[1000];
    ofstream Guardar; // variable de fichero
    ifstream Mostrar;
    
    string archivo; 
    
    Guardar.open("DATOS.txt",ios::out); // crea un fichero
 
    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opci�n:" << endl;
        cout << "1.- A�adir datos de un nuevo archivo" << endl;
        cout << "2.- Mostrar los nombres de todos los archivos" << endl;
        cout << "3.- Mostrar archivos que sean de mas de un cierto tama�o" << endl;
        cout << "4.- Ver datos de un archivo" << endl;
        cout << "5.- Salir" << endl;
 
        cin >> option;
 
        // Hacemos una cosa u otra seg�n la opci�n escogida
        switch(option)
        {
            case 1: // A�adir un dato nuevo
              
                if(numberOfFiles < 1000)   // Si queda hueco
                {
                    cout << "Introduce el nombre del archivo: ";
                    cin >> files[numberOfFiles].name;
                    cout << "Introduce el tama�o en KB: ";
                    cin >> files[numberOfFiles].size;
                    numberOfFiles++;  // Y tenemos una ficha m�s
                    
                    //guarda los datos ingresados
                }
                else{   // Si no hay hueco para m�s archivos, avisamos
                    cout << "�M�ximo de archivos alcanzado (1000)!" << endl;
                    Guardar.close(); 
                }
                
                for( i = 0; i < numberOfFiles; i++)
                {
                   Guardar << files[i].name << " " << files[i].size << endl;
                }
                
                break;
 
            case 2: // Mostrar todos
            
             Mostrar.open("DATOS.txt",ios::in); // muestra fichero
            
             if(Mostrar.fail())
             {
                 cout <<"No se pudo abrir el archivo";
                 exit(1);
             } 
              while(!Mostrar.eof()){
                      getline(Mostrar, archivo);
                      cout << archivo << endl;
              }
              Mostrar.close();    
                break;
 
            case 3: // Mostrar seg�n el tama�o
                cout << "�A partir de que tama�o quieres que te muestre? ";
                cin >> tempNumber;
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].size >= tempNumber)
                        cout << "Nombre: " << files[i].name
                            << "; Tama�o: " << files[i].size
                            << " Kb" << endl;
                break;
 
            case 4: // Ver todos los datos (pocos) de un archivo
                cout << "�De qu� archivo quieres ver todos los datos?";
                cin >> tempText;
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].name == tempText)
                        cout << "Nombre: " << files[i].name
                            << "; Tama�o: " << files[i].size
                            << " Kb" << endl;
                break;
 
            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;
 
            default: // Otra opci�n: no v�lida
                cout << "�Opci�n desconocida!" << endl;
                break;
        }
    } while (option != 5);// Si la opci�n es 5, terminamos
    
    system("PAUSE");
    return 0;
}
