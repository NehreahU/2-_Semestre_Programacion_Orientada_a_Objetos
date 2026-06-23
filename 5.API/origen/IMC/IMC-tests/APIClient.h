/*
Información CRC:

Clase: IMC

Responsabilidades:
- Calcular el Índice de Masa Corporal (IMC) utilizando el peso y la altura de una persona.
- Calcular el Índice de Masa Corporal (IMC) utilizando dos métodos: una función y una API
- Evaluar el estado físico de la persona con base en su IMC.

Colaboradores:
- Tiene colaboradores directos: Persona 
  
*/

#ifndef IMC_H
#define IMC_H

#include <iostream>
#include <cmath>       // Biblioteca para funciones matemáticas
#include <curl/curl.h> // cURL (Client URL) es una herramienta de línea de comandos y una biblioteca que se utiliza para transferir datos desde o hacia un servidor utilizando una gran variedad de protocolos, como HTTP,
#include <string>
#include "APIClient.h"

class IMC
{
private:
    APIClient apiCliente;       // Instancia del cliente API

public:
    // Constructor para inicializar los atributos
    IMC();

    // Método para calcular el IMC
    double calcularIMCAPI(double peso, double altura) const;

    // Método para obtener una evaluación del IMC
    std::string  evaluarIMC(const double &peso, const double &altura) const;
};
#endif // IMC_H
