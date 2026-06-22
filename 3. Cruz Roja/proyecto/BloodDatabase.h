
/*
    Clase: BloodDatabase
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: BloodDatabase.h
    Resumen: Declaración de la clase BloodDatabase.

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando 
    funcionalidades para registrar, buscar y analizar la información de los donantes.

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

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.

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
#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

// Librerias 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"


// Declaración de la clase BloodDatabase
class BloodDatabase {

// Atributos privados para gestionar la base de datos de donantes
private:
    const std::string fileName = "data.txt";
    std::vector<Donor> donors;

    static void displayProvinces();
    static void displayBloodType();

// Métodos públicos para interactuar con la base de datos de donantes
public:
    static void clearConsole();
    static void waitForKeyPress();
    static int getValidatedInput(const std::string& prompt);

    std::string cambio(int ts)const;
    void getDonorDetails();
    void writeDataToFile();
    void searchAndDisplay() const;
    void deleteDonor(const std::string& donorName);
    void donorHistory();
};

#endif // BLOODDATABASE_H
