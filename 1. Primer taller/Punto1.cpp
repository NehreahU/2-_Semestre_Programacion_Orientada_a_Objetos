/*
Curso: Fundamentos de Programación Orientada a Objetos
Archivo: Punto1.cpp
Autores
Estudiante: Anyela Lineth Cabrera Ordoñez | Código: 202540031 | Correo: anyela.cabrera@correounivalle.edu.co
Estudiante: Carlos Anibal Ceron del Castillo | Código: 202537097 | Correo: carlos.ilich.ceron@correounivalle.edu.co
Estudiante: Javier Felipe Contreras Díaz | Código: 202535936 | Correo: contreras.javier@correounivalle.edu.co
Fecha: 04/03/2025

@brief Implementación de la variable cédula como cadena de texto (string) y su uso en el programa.
@details El programa solicita al usuario ingresar su número de cédula y lo muestra en pantalla.
*/

#include <iostream>

// Librería para manejar cadenas de texto
#include <string> 
using namespace std;
int main() {

    // Se declara la variable cédula como una cadena de texto (string)
    string cedula;

    // Se solicita al usuario ingresar su número de cédula
    cout << "Ingrese su numero de cedula:";
    cin>>cedula;

    // Se muestra el número de cédula
    cout << "Su numero de cedula es: " << cedula << endl;
}
