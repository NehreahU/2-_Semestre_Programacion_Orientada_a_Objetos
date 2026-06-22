/*
    Proyecto: Report-BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando 
    funcionalidades para registrar, buscar y analizar la información de los donantes.

    Este proyecto genera reportes de una base de datos de donantes de sangre, proporcionando 
    informacion sobre las ubicaciones de los dontantes, el tipo de sangre y la edad.

    El código se basó en el proyecto BloodDatabase, fue traducido al español 
    y adaptado a las necesidades del curso.



    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024

    Contribuidores:
    Estudiante Carlos Anibal Ceron del Castillo
    Código: 202537097
    Email: carlos.ilich.ceron@correounivalle.edu.co

    Estudiante: Anyela Lineth Cabrera Ordoñez 
    Código: 202540031 
    Email: anyela.cabrera@correounivalle.edu.co
  
    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Mayo 2026
*/
#include "Donor.h"
#include <sstream>
#include <iostream>
#include <algorithm>

void Donor::donorDetails() const {
    std::cout << "Nombre del donante: " << name << std::endl;
      std::cout << "Edad del donante: " << age << std::endl;
    std::cout << "Distrito del donante: " << district << std::endl;
    std::cout << "Tipo de sangre del donante: " << bloodType << std::endl;
}

Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;
    getline(ss, token, ','); d.donorId = std::stoi(trim(token));
    getline(ss, token, ','); d.name = trim(token);
    getline(ss, token, ','); d.age = std::stoi(trim(token));
    getline(ss, token, ','); d.address = trim(token);
    getline(ss, token, ','); d.district = std::stoi(trim(token));
    getline(ss, token, ','); d.bloodType = std::stoi(trim(token));
    getline(ss, token, ','); d.number = trim(token);
   
    return d;
}

std::string Donor::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int Donor::getAge() const {
   return age;
}

int Donor::getBloodType() const {
   return bloodType;
}

int Donor::getDistrict() const {
   return district;
}
