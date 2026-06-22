/*
Curso: Fundamentos de Programación Orientada a Objetos
Archivo: Punto5.cpp
Autores
Estudiante: Anyela Lineth Cabrera Ordoñez | Código: 202540031 | Correo: anyela.cabrera@correounivalle.edu.co
Estudiante: Carlos Anibal Ceron del Castillo | Código: 202537097 | Correo: carlos.ilich.ceron@correounivalle.edu.co
Estudiante: Javier Felipe Contreras Díaz| Código: 202535936 | Contreras.javier@correounivalle.edu.co
Fecha: 04/03/2025

@brief Un programa que solicita 2 números enteros y da como resultado una división, arroja un error en dado caso el denominador sea igual a 0
*/

#include <iostream>
using namespace std;

int main(){

    // Se solicitan 2 valores enteros al usuario
    int numerador, denominador;
    cout << "Ingrese el numerador: ";
    cin >> numerador;
    cout << "Ingrese el denominador: ";
    cin >> denominador;

    //Se revisa que el denominador sea diferente de 0
    if (denominador == 0){
        cout << "Error: No es posible dividir entre 0." << endl;
    } else {
        //Se cambia el tipo de variable del numerador y denominador para que el resultado sea incluya decimales
        cout << "El resultado es: " << (double)numerador / (double)denominador << endl;
    }
    
    return 0;
}
