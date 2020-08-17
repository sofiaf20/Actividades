#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Musica{
  string artista;
  string titulo;
  int duracion;
  int tamano;     
};
int main(int argc, char *argv[])
{
    Musica musica;
    
    cout << "Ingrese nombre de artista:" << endl;
    getline(cin,musica.artista);
    cout << "Ingrese tituto de cancion:" << endl;
    getline(cin,musica.titulo);
    cout << "Ingrese duracion en segundos:" << endl;
    cin >> musica.duracion;
    cout << "Ingrese tamano de fichero(KB):" << endl;
    cin >> musica.tamano;
    
    cout << endl;
    
    cout << "Datos ingresados:" << endl;
    cout << "Artista:" << musica.artista << endl;
    cout << "Titulo:" << musica.titulo << endl;
    cout << "Duracion(segundos):" << musica.duracion << endl;
    cout << "Tamano(KB):" << musica.tamano << endl;
    
    system("PAUSE");
    return 0;
}
