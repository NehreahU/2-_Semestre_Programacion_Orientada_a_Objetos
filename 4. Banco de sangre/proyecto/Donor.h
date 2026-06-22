/*
    Clase: Donor
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:

    Clase: Donor

    Responsabilidades:
        - Almacenar y gestionar la información de un donante, 
          incluyendo detalles como nombre, tipo de sangre, edad,
          distrito de residencia y otros datos relevantes.
        - Proveer métodos para obtener y manipular dicha información, 
          como  obtener datos del donante.
        - Ofrecer funcionalidades para procesar y mostrar la información 
          de los donantes en formato adecuado.

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
#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {
public:
    int donorId, district, bloodType, age;
    std::string name, address, number;

    void donorDetails() const;
    int getAge() const;
    int getBloodType() const;
    int getDistrict() const;

    static Donor parseLine(const std::string& line);

private:
    static std::string trim(const std::string& str);
};

#endif // DONOR_H
