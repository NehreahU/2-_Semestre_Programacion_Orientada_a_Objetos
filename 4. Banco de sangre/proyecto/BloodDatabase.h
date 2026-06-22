/*
    Proyecto: Report-BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:

    Clase: BloodDatabase

    Responsabilidades:
        - Gestionar una base de datos de donantes de sangre, almacenando 
          un conjuto de objetos de tipo `Donor`.
        - Proveer métodos para agregar, eliminar y buscar donantes en la base de datos.
        - Facilitar el manejo de la información almacenada de forma eficiente y 
          adecuada para su consulta y modificación.

    Colaboradores:
        - Colabora directamente con la clase `Donor`, ya que administra una colección 
          de objetos `Donor`.
        - Colabora con la clase `Reports`, ya que entrega la información del vector de donantes para contruir           los reportes correspondientes

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.

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
#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class BloodDatabase {
private:
    const std::string fileName = "data.txt";
    std::vector<Donor> donors;

    static void displayProvinces();
    static void displayBloodType();
public:
    static void clearConsole();
    static void waitForKeyPress();
    static int getValidatedInput(const std::string& prompt);

    void getDonorDetails();
    void writeDataToFile();
    void searchAndDisplay() const;
    void deleteDonor(const std::string& donorName);
    std::vector<Donor> getDonors();
};

#endif // BLOODDATABASE_H
