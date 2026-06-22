/*
Curso: Fundamentos de Programación Orientada a Objetos
Archivo: Punto3.cpp
Autores
Estudiante: Anyela Lineth Cabrera Ordoñez | Código: 202540031 | Correo: anyela.cabrera@correounivalle.edu.co
Estudiante: Carlos Anibal Ceron del Castillo | Código: 202537097 | Correo: carlos.ilich.ceron@correounivalle.edu.co
Estudiante: Javier Felipe Contreras Díaz | Código: 202535936 | Correo: contreras.javier@correounivalle.edu.co
Fecha: 04/03/2025

@brief Cálculo de la raíz cuadrada de -1.
@details El programa calcula la raíz cuadrada de -1 utilizando librería complex y cmath.
@comentario: Se investigó en https://en.cppreference.com/w/cpp/numeric/complex/sqrt.html para entender cómo calcular la raíz cuadrada de un número negativo utilizando números complejos en C++.
*/

#include <iostream>

// Librería para manejar números complejos
#include <complex> 

//Libreria para usar la raíz cuadrada (sqrt)  
#include <cmath> 

using namespace std;
int main() {

    // Se define el valor directamente como -1 para calcular su raíz cuadrada
    double numero = -1; 
    
    // Se calcula la raíz cuadrada convirtiendo el -1 en un número complejo.
    complex<double> resultado_raiz = sqrt(complex<double>(numero, 0));
    
    // Se muestra el resultado extrayendo la parte imaginaria, con el método .imag() y añadiendo la 'i'
    cout << "La raiz cuadrada de -1 es: " << resultado_raiz.imag() << "i" << endl;
    
    return 0;
}
