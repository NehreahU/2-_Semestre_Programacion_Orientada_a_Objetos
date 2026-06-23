/*
    Proyecto: IMC -Refactoring
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

#include <iostream>
#include <curl/curl.h>
#include <cmath> // Biblioteca para funciones matemáticas
#include "Persona.h"
#include "IMC.h"


int main()
{
   
    // Crear un objeto de la clase Persona
    Persona persona;
    // Crear un objeto de la clase IMC
    IMC calculadora;

    // Evaluar el IMC utilizando los objetos
    std::cout << "Se evalua el IMC con la función con la implementación con POW:" << std::endl;
    calculadora.evaluarIMC(persona.getPeso(),persona.getAltura());
    std::cout << "Se evalua el IMC con la API:" << std::endl;
    std::cout <<calculadora.calcularIMCAPI(persona.getPeso(),persona.getAltura())<<std::endl;

    return 0;
}
