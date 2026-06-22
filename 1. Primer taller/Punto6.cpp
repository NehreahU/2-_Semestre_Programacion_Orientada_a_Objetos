//Curso: Fundamentos de programación orientada a objetos.
//Archivo: Punto6.cpp
//Autores:
// -Javier Felipe Contreras Díaz | 2535936 | contreras.javier@correounivalle.edu.co
// -Anyela Lineth Cabrera Ordoñez | 202540031 | anyela.cabrera@correounivalle.edu.co
// -Carlos Anibal Ceron del Castillo | 202537097 | carlos.ilich.ceron@correounivalle.edu.co
//fecha: 04-03-2026

//@brief: Este programa solicita que ingrese una letra del abecedario y según sea esté entre a y m o n y z asignará un valor de 0 o 1.


//librerías
#include <iostream> //Estandar
#include <cctype> //Convertir a minúsculas
using namespace std;


int codificacion (){
    //Declaración e ingreso de variables
    char letra;
    int  code = 0;
    cout<< "Por favor ingrese una letra: ";
    cin>> letra;
    letra = tolower(letra);
    
    //Algoritmo de condiciones, si está entre a y m pone 0 y si está entre n y z 1
    if (letra >='a' && letra <='m'){
        code = 0;
    } else if (letra >'m' && letra <= 'z') { 
        code = 1;
    } else {
        cout<< "Ingrese una letra válida";
    }
    return code;
}

int main(){
    // inicializa variable y toma el valor de la función de codificación
    int code = codificacion();
    
    //imprime la letra codificada de la variable previamente iniciada
    cout<< "Su letra codificacada es: "<< code<< endl;
    return 0;
}
