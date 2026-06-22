/*
Curso: Fundamentos de Programación Orientada a Objetos
Archivo: Punto4.cpp
Autores
Estudiante: Anyela Lineth Cabrera Ordoñez | Código: 202540031 | Correo: anyela.cabrera@correounivalle.edu.co
Estudiante: Carlos Anibal Ceron del Castillo | Código: 202537097 | Correo: carlos.ilich.ceron@correounivalle.edu.co
Estudiante: Javier Felipe Contreras Díaz | Código: 202535936 | Contreras.javier@correounivalle.edu.co
Fecha: 04/03/2025

@brief Un programa que solicita 2 nombres y los concatena para mostrar el resultado en pantalla
@details El programa usa la librería string para guardar las variables y concatenarlas con el operador +
*/

#include <iostream>

//Librería necesaria para el uso de variables de tipo string
#include <string>
using namespace std;

int main() {

    //Se definen las variables necesarias para almacenar los nombres y el resultado
    string name1,name2,result;

    //Se solicitan 2 nombres usando getline() para obtener lineas de texto completas, incluyendo espacios.
    cout << "Ingresa tu primer nombre: ";
    getline(cin, name1);
    cout << "Ingresa tu segundo nombre: ";
    getline(cin, name2);

    //Se concatenan ambas strings usando el operador +, se guarda el resultado en la variable result
    result = name1 + " " + name2;

    //Se muestra el resultado en pantalla
    cout << "Tu nombre completo es: " << result << endl;

    return 0;

}

