/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: main.cpp
    Resumen: Función principal para ejecutar el programa.

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando 
    funcionalidades para registrar, buscar y analizar la información de los donantes.

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

// Incluir las clases
#include "BloodDatabase.h"
#include "Donor.h"

// Librerías para implementar los métodos de la clase
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Función principal
int main() {
    std::string donorName;
    BloodDatabase database;
    int choice;

    // Bucle para mostrar el menú y manejar las opciones del usuario
    while (true) {
        BloodDatabase::clearConsole();

        std::cout <<
             " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
             " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
             " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
             " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
             " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
             " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n";

        std::cout << "1. Registrar donante\n";
        std::cout << "2. Buscar donante\n";
        std::cout << "3. Eliminar donante\n";
        std::cout << "4. Salir\n";
        std::cout << "5. Revisar historial de donantes\n";
        std::cout <<"\n";
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;
        std::cout <<"\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar cualquier entrada extra


        // Manejar la elección del usuario
        switch (choice) {
        case 1:
            database.getDonorDetails();
            database.writeDataToFile();
            break;
        case 2:
            database.searchAndDisplay();
            break;
        case 3:
            std::cout << "Ingrese el nombre del donante a eliminar: ";
            std::getline(std::cin, donorName);
            database.deleteDonor(donorName);
            BloodDatabase::waitForKeyPress();
            break;
        case 4:
            std::cout << "Gracias por usar el Sistema de la Cruz Roja" << std::endl;
            return 0;
        case 5:
            std::cout << "Historial de donaciones: \n";
            std::cout <<"\n";
            database.donorHistory();
        default:
            std::cout << "Opción no válida. Inténtalo de nuevo.\n";
            BloodDatabase::waitForKeyPress();
            break;
        }
    }
}
