/*
    Proyecto: Nutricion
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
#include <string>
#include <iomanip>
#include <sstream>



int main()
{
    //Ejemplo de receta: 1 cup rice, 10 oz chickpeas
    std::string receta;
   
    // Solicitar datos del usuario
    std::cout << "Ingrese la receta: ";
    getline(std::cin, receta);
    std::cout<<receta<<std::endl;



    
    
    // URL de la API con parámetros


    // Inicializa curl


    return 0;
}
