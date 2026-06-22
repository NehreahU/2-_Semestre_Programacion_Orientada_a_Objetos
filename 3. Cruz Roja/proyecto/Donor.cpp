
/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Donor.cpp
    Resumen: Implementación de la clase Donor.

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando 
    funcionalidades para registrar, buscar y analizar la información de los donantes.

    El código se basó en el proyecto BloodDatabase, fue traducido al español 
    y adaptado a las necesidades del curso.
    
  	Autor:
        Nombre: Victor Bucheli
	  	Correo: victor.bucheli@correounivalle.edu.co
        Fecha: Octubre 2024

	Contribuidores:
        Estudiante Carlos Anibal Ceron del Castillo
        Codigo: 202537097
        Email: carlos.ilich.ceron@correounivalle.edu.co

		Estudiante: Anyela Lineth Cabrera Ordoñez 
		Codigo: 202540031 
		Email: anyela.cabrera@correounivalle.edu.co
  
		Estudiante: Javier Felipe Contreras Díaz
		Codigo: 202535936
		Email: contreras.javier@correounivalle.edu.co
	
	    Fecha: Marzo 2026
*/

// Incluir la clase
#include "Donor.h"

// Librerias
#include <sstream>
#include <iostream>
#include <algorithm>

// Método para mostrar la información de un donante
void Donor::donorDetails() const {
    std::cout << "Nombre del donante: " << name << std::endl;
    std::cout << "Distrito del donante: " << district << std::endl;
    std::cout << "Tipo de sangre del donante: " << bloodType << std::endl;
}

// Método para convertir una línea del archivo en un objeto Donor
Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;

    getline(ss, token, ','); if (!token.empty()){d.donorId = std::stoi(trim(token));}
    getline(ss, token, ','); if (!token.empty()){d.name = trim(token);}
    getline(ss, token, ','); if (!token.empty()){d.address = trim(token);}
    getline(ss, token, ','); if (!token.empty()){d.district = std::stoi(trim(token));}
    getline(ss, token, ','); if (!token.empty()){d.bloodType = trim(token);}
    getline(ss, token, ','); if (!token.empty()){d.number = trim(token);}

    return d;
}

// Método para eliminar espacios al inicio y al final de un string
std::string Donor::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
