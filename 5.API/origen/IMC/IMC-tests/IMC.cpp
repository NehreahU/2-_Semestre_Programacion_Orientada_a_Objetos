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
#include "IMC.h"
#include <sstream> // Para std::stringstream
#include <string>
#include <nlohmann/json.hpp> // Biblioteca JSON

IMC::IMC()  {}

double IMC::calcularIMC(double peso, double altura) const
{
    return peso / std::pow(altura, 2);
}

std::string IMC::evaluarIMC(const double &peso, const double &altura) const
{
    double imc = calcularIMC(peso, altura);
    std::string retorno="";
    std::cout << "Su Índice de Masa Corporal (IMC) es: " << imc << std::endl;

    if (imc < 18.5)
    {
       retorno= "Por debajo del peso normal.";
    }
    else if (imc >= 18.5 && imc <= 24.9)
    {
       retorno="Usted tiene un peso normal.";
    }
    else if (imc >= 25 && imc <= 29.9)
    {
        retorno="Usted tiene sobrepeso.";
    }
    else
    {
        retorno="Usted tiene obesidad.";
    }
    return retorno;
}