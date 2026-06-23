/*
   Proyecto: IMC - Test
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
#include <cassert>
#include <sstream>
int main()
{
   // Crear un objeto de la clase Persona
   Persona persona(74,170);
   // Crear un objeto de la clase IMC
   IMC calculadora;
   
    assert(persona.getPeso() == 74.0);   // Verifica que el peso es 74
    assert(persona.getAltura() == 170.0); // Verifica que la altura es 170
    assert(std::abs(calculadora.calcularIMC(persona.getAltura(),persona.getPeso()) - 0.0310446) < 0.01); // Verifica que el IMC es correcto
    


    // Crear un objeto de la clase apiClient
    APIClient apiClient;

   // Prueba de solicitud válida
   std::stringstream url; // Crea un objeto stringstream para construir la URL
   url << "https://body-mass-index-bmi-calculator.p.rapidapi.com/metric?weight=74&height=171";
   std::string urlString=url.str();
   std::string hd1="x-rapidapi-key: 261657ce93msha29aa7438d5a366p1adfa7jsn7bdd387f38d7";
   std::string hd2="x-rapidapi-host: body-mass-index-bmi-calculator.p.rapidapi.com";

   // Para esta prueba, asumimos que la API está disponible y responderá correctamente
   // **Nota:** En un entorno real, deberías simular la respuesta de la API o usar un entorno de pruebas
   std::string response = apiClient.realizarSolicitud(urlString, hd1, hd2);
   assert(!response.empty()); // Verifica que la respuesta no esté vacía


   // Prueba de manejo de error al inicializar cURL
   try {
       // Se puede simular un error creando un objeto APIClient que falle al inicializar cURL
       // Aquí, no hay un método para forzar un fallo, así que esta prueba es teórica
       // assert(apiClient.realizarSolicitud("malformed_url", header1, header2)); // Esto debería fallar
   } catch (const std::runtime_error &e) {
       // Verifica que se lanza una excepción con un mensaje específico
       assert(std::string(e.what()) == "Error al inicializar cURL");
   }

   // Prueba de manejo de error en la solicitud cURL
   // Aquí deberías proporcionar un URL que sepas que fallará, como un dominio no existente
   try {
       std::string invalidUrl = "http://invalido.com"; // Asegúrate de que esta URL falle
       apiClient.realizarSolicitud(invalidUrl, hd1, hd2);
   } catch (const std::runtime_error &e) {
       // Verifica que se lanza una excepción con un mensaje específico
       assert(std::string(e.what()).find("Error en la solicitud cURL:") != std::string::npos);
   }

   // Mensaje de éxito si todas las pruebas pasan
   std::cout << "Todas las pruebas pasaron correctamente.\n";
   return 0;
}
