
/*
    Clase: Donor
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Donor.h
    Resumen: Declaración de la clase Donor.

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando 
    funcionalidades para registrar, buscar y analizar la información de los donantes.

    Información CRC:
    
    Clase: Donor

    Responsabilidades:
        - Almacenar y gestionar la información de un donante, 
          incluyendo detalles como nombre, tipo de sangre, 
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

#ifndef DONOR_H
#define DONOR_H

#include <string>

// Declaración de la clase Donor
class Donor {

// Atributos privados para almacenar la información del donante
private:
    int donorId, district;
    std::string name, address, bloodType, number;

    static std::string trim(const std::string& str);

// Métodos públicos para acceder y manipular la información del donante
public:
    void donorDetails() const;

    static Donor parseLine(const std::string& line);
    
    // Getters y setters para los atributos del donante
    int getDonorId() const { return donorId; }
    int getDistrict() const { return district; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getBloodType() const { return bloodType; }
    std::string getNumber() const { return number; }
  
    void setDonorId(int id) { donorId = id; }
    void setName(const std::string& newName) { name = newName; }
    void setAddress(const std::string& newAddress) { address = newAddress; }
    void setDistrict(int newDistrict) { district = newDistrict; }
    void setBloodType(const std::string& newBloodType) { bloodType = newBloodType; }
    void setNumber(const std::string& newNumber) { number = newNumber; }
};

#endif // DONOR_H
