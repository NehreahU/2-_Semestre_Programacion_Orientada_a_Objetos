//Curso: Fundamentos de programación orientada a objetos.
//Archivo: Punto7.cpp
//Autores:
// -Javier Felipe Contreras Díaz | 2535936 | contreras.javier@correounivalle.edu.co
// -Anyela Lineth Cabrera Ordoñez | 202540031 | anyela.cabrera@correounivalle.edu.co
// -Carlos Anibal Ceron del Castillo | 202537097 | carlos.ilich.ceron@correounivalle.edu.co
//fecha: 04-03-2026

//@brief: Este programa solicita una palabra al usuario, y la codifica letra por letra, cada letra será un 0 o un 1 dependiendo si está entre a y m o entre n y z respectivamente.

//Librerías 
#include <iostream>
#include <vector> //para declarar vectores
#include <string>  // para usar palabras
#include <cctype> //para volver todo a minúsculas. 
using namespace std;


//Función de codificación construida para el ejercicio anterior y modificada para ya no solicitar letra, sino usar las letras de la palabra ingresada.
int codificacion (string palabra, int i){
    //declara variable letra, para ingresar la letra en minúscula en la posición i de la palabra ingresada. si i es 2 en la palabra sol, letra = o.
    char letra = tolower(palabra[i]);
    int  code = 0;
    
    if (letra >='a' && letra <='m'){
        code = 0;
    } else if (letra >'m' && letra <= 'z') { 
        code = 1;
    } else {
        cout<< "Ingrese una letra válida";
    }
    return code;
}

//Main que ordena el programa
int main(){
    //Declaro la variable y se solicita el ingreso de la palabra que se desea codificar
    string palabra = "";
    cout<< "Ingrese una palabra para codificarla: ";
    cin>> palabra;

    //vector que recogerá cada valor codificado para cada letra de la palabra ingresada, es decir, si ingresa sol, el vector tendrá 110
    vector<int> code(palabra.length());
    
    //bucle para que el vector code, adquiera los valores codificados de las letras de la palabra ingresada a través de la función codificacion.
    for (int i = 0; i < palabra.length(); i++){
        code[i]= codificacion(palabra, i);
    }
    
    cout<< "Su mensaje codificado es: ";
    
    //Imprime cada caracter del vector code, completando la impresión del mensaje codificado.
    for (int i = 0; i < code.size(); i++){
        cout<<code[i];
    }
    cout<< endl;
    
    return 0;
}


