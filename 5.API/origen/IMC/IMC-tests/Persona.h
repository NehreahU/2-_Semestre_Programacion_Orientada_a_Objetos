/*
Información CRC:

Clase: Persona

Responsabilidades:
- tiene la informacion de una persona, para este caso Peso y altura pero podria tener otros campos por ejemplo porcentaje de grasa
- valida y almacena la informacion para calcular el IMC

Colaboradores:
- No tiene colaboradores directos con otras clases en esta implementación, 
  pero podría integrarse con clases que manejen bases de datos o interfaces 
  de usuario para expandir su funcionalidad.
*/
#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cmath>       // Biblioteca para funciones matemáticas
#include <curl/curl.h> // cURL (Client URL) es una herramienta de línea de comandos y una biblioteca que se utiliza para transferir datos desde o hacia un servidor utilizando una gran variedad de protocolos, como HTTP,
#include <string>


class Persona
{
private:
    double peso;   // Atributo para el peso en kilogramos
    double altura; // Atributo para la altura en metros
    
public:
    // Constructor para inicializar los atributos
    Persona();

    // Método para traer peso y altura
    double getPeso() const;
    double getAltura() const;


};
#endif // PERSONA_H
