/*
    Proyecto: IMC 
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto permite trabajar con:
    Uso de clases 
    Uso de bibliotecas
    Uso de APIs
    Reutilización de código
    Software modular y compatibles con otro software

    

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/
#include "Persona.h"
#include <sstream> // Para std::stringstream
#include <string>



Persona::Persona() {
double peso=0, altura=0;
 // Solicitar y validar la altura
    do {
        std::cout << "Ingrese su altura en metros (positivo): ";
        std::cin >> altura;
        if (altura <= 0) {
            std::cout << "Error: La altura debe ser un valor positivo." << std::endl;
        }
    } while (altura <= 0); // Repetir mientras la altura no sea válida




    do {
        std::cout << "Ingrese su peso en kilogramos (positivo): ";
        std::cin >> peso;
        if (peso <= 0) {
            std::cout << "Error: El peso debe ser un valor positivo." << std::endl;
        }
    } while (peso <= 0); // Repetir mientras el peso no sea válido
    
this->altura=altura;
this->peso=peso;

}

double Persona::getAltura() const {return altura;}

double Persona::getPeso()  const {return peso;}


