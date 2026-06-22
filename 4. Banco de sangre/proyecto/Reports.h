/*
    Clase: Reports
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:

    Clase: Reports

    Responsabilidades:
        - Cargar una base de datos de donantes de sangre desde un vector de objetos de tipo `Donor` a un                 vector auxiliar para hacer reportes con la informacón de los donantes tal como tipo de sangre,                edad, distrito de residencia y otros datos relevantes.
        - Calcular el total de donantes según diferentes criterios (distrito, edad, tipo de sangre).
        - Calcular la edad promedio de los donantes en un distrito específico.
        - Calcular el número de donantes adultos por distrito y tipo de sangre.

    Colaboradores:
        - Colabora con la clase BloodDatabase, que gestiona una colección 
          de objetos Donor para administrar la base de datos de donantes 
          de sangre.

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
#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class Reports {
public:
Reports();
void loadDataBase(const std::vector<Donor>& adonor);
int donorTotal() const;        
int donorTotal(const int& district, const int& age, const int& bloodType) const;
int donorTotal(const int& district, const int& bloodType) const;  
double donorMeanAge(const int& district) const;
double donorMeanAge(const int& d1,const int& d2, const int& d3) const;

void generarReporteAnual() const;
int matriz[8][10];
int vector[8];
int total;

private:
    std::string date;
    std::vector<Donor> auxDonor;
};

#endif // DONOR_H
