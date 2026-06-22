/*
Curso: Fundamentos de Programación Orientada a Objetos
Archivo: Punto3.cpp
Autores
Estudiante: Anyela Lineth Cabrera Ordoñez | Código: 202540031 | Correo: anyela.cabrera@correounivalle.edu.co
Estudiante: Carlos Anibal Ceron del Castillo | Código: 202537097 | Correo: carlos.ilich.ceron@correounivalle.edu.co
Estudiante: Javier Felipe Contreras Díaz | Código: 202535936 | Correo: contreras.javier@correounivalle.edu.co
Fecha: 04/03/2025

@brief El programa que suma 2 enteros en C++.
@details El programa calcula la suma de dos números enteros ingresados por el usuario y muestra el resultado en pantalla. 
*/

#include <iostream>
using namespace std;
int main() {

    // Se declaran dos variables de tipo entero para almacenar los dos números 
    int numero1, numero2;

    // Se solicitan dos números y se almacenan en la variable número1 y número2
    cout <<"ingrese su primer numero:"<<endl;
    cin >> numero1;
    cout <<"ingrese su segundo numero:"<<endl;
    cin >> numero2;

    // Se muestra el resultado de la suma de los dos números ingresados por el usuario
    cout <<"la suma de los dos numeros es:"<< numero1 + numero2 << endl;
}
