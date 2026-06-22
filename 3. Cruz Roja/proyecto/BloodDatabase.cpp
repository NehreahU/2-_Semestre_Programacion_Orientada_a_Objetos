
/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: BloodDatabase.cpp
    Resumen: Implementación de la clase BloodDatabase.

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

// Incluir la clase
#include "BloodDatabase.h"

// Librerías para implementar los métodos de la clase
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <algorithm>

using namespace std;

// Método para mostrar los departamentos disponibles
void BloodDatabase::displayProvinces() {
    std::cout << "Elige el departamento:\n";
    std::cout << "1. Putumayo\n";
    std::cout << "2. Cauca\n";
    std::cout << "3. Valle del Cauca\n";
    std::cout << "4. Amazonas\n";
    std::cout << "5. Risaralda\n";
    std::cout << "6. Antioquia\n";
    std::cout << "7. Norte de Santander\n";
    std::cout << "8. Chocó\n";
    std::cout << "9. Arauca\n";
    std::cout << "10. Guainía\n";
}


// Método para mostrar los tipos de sangre disponibles
void BloodDatabase::displayBloodType(){
    std::cout << "1. A+\n";
    std::cout << "2. A-\n";
    std::cout << "3. B+\n";
    std::cout << "4. B-\n";
    std::cout << "5. AB+\n";
    std::cout << "6. AB-\n";
    std::cout << "7. O+\n";
    std::cout << "8. O-\n";
}


// Método para limpiar la consola
void BloodDatabase::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    //   system("clear");
#endif
}


// Método para esperar a que el usuario presione una tecla
void BloodDatabase::waitForKeyPress() {
    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.ignore();
    std::cin.get();
}


// Método para solicitar y validar la entrada del usuario 
int BloodDatabase::getValidatedInput(const std::string& prompt) {
    int value;
    std::string input;

    // Bucle que solicita la entrada hasta que sea válida
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        try {
            if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
                throw std::invalid_argument("La entrada contiene caracteres no numéricos");
            }
            value = std::stoi(input);
            break; // si la conversión es exitosa, salir del bucle
        } catch (const std::invalid_argument& e) {
            std::cout << "Entrada no válida: " << e.what() << ". Por favor ingrese un número válido." << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Entrada fuera de rango. Por favor ingrese un número válido." << std::endl;
        }
    }
    return value;
}


// Método para convertir la selección del tipo de sangre a string
std::string BloodDatabase::cambio(int ts) const{
      switch(ts){
        case 1:
            return "A+";
            break;
        case 2:
            return"A-";
            break;
        case 3:
            return "B+";
            break;
        case 4:
            return "B-";
            break;
        case 5:
            return"AB+";
            break;
        case 6:
            return "AB-";
            break;
        case 7:
            return "O+";
            break;
        case 8:
            return "O-";
            break;
        default:
            return "Desconocido";
    }
}

// Método para obtener los detalles de un donante y agregarlo a la base de datos
void BloodDatabase::getDonorDetails() {
    // Limpiar la consola y solicitar los detalles del donante
    clearConsole();
    std::cout << "Ingrese los detalles del donante\n";
    int ts;
    Donor newDonor;
    newDonor.setDonorId(getValidatedInput("Id: "));

    // Se solicita al usuario el nombre del donante
    std::cout << "Nombre: ";
    std::string name;
    std::getline(std::cin, name);
    newDonor.setName(name);

    // Se solicita al usuario la dirección del donante
    std::cout << "Dirección: ";
    std::string address;
    std::getline(std::cin, address);
    newDonor.setAddress(address);

    displayProvinces();
    newDonor.setDistrict(getValidatedInput("departamento (ingrese el número correspondiente): "));
    
    // Se solicita al usuario el tipo de sangre del donante
    std::cout << "Tipo de sangre: " << std::endl;
    displayBloodType();
    ts = getValidatedInput("Tipo de sangre (ingrese el número correspondiente): ");
    newDonor.setBloodType(cambio(ts));
    
    // Se solicita al usuario el número de teléfono del donante
    std::cout << "Número de telefono: " << std::endl;
    std::string num;
    std::getline(std::cin, num);
    newDonor.setNumber(num);

    donors.push_back(newDonor); // Se agrega el nuevo donante al vector de donantes
}


// Método para escribir los datos de un donante en el archivo
void BloodDatabase::writeDataToFile() {
    std::ofstream outfile(fileName, std::ios::app);

    // Verificar si el archivo se abrió correctamente
    if (!outfile) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    // Se obtiene el último donante agregado al vector y se escribe en el archivo
    Donor newDonor = donors.back();
    outfile << newDonor.getDonorId() << ",    " << newDonor.getName() << ",    " << newDonor.getAddress() << ",    " << newDonor.getDistrict() << ",    " << newDonor.getBloodType() << ",    " << newDonor.getNumber() << std::endl;

    outfile.close(); // Se cierra el archivo
}


// Método para buscar donantes según los filtros ingresados por el usuario y mostrarlos en pantalla
void BloodDatabase::searchAndDisplay() const {
    clearConsole();
    displayProvinces();
    int provinceName = getValidatedInput("Ingrese el número de la departamento: ");

    // Se solicita al usuario la dirección 
    std::cout << "Ingrese la dirección (dejar en blanco para omitir): ";
    std::string addressFilter;
    std::getline(std::cin, addressFilter);

    // Se solicita al usuario el tipo de sangre
    displayBloodType();
    int bloodTypeFilter = getValidatedInput("Ingrese el número del tipo sanguineo: ");
    std::string bloodTF;
    bloodTF = cambio(bloodTypeFilter);

    
    //std::cout << "Ingrese el tipo de sangre (dejar en blanco para omitir): ";
    //std::string bloodTypeFilter;
    //std::getline(std::cin, bloodTypeFilter);

    std::ifstream inFile(fileName);

    // Verificar si el archivo se abrió correctamente para lectura
    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::vector<Donor> donors;
    std::string line;
    bool found = false;

    // Bucle que lee cada línea del archivo
    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line); // Se convierte la línea en un objeto Donor utilizando el método parseLine
        bool match = d.getDistrict() == provinceName &&
            (addressFilter.empty() || d.getAddress().find(addressFilter) != std::string::npos) && (bloodTF.empty() || d.getBloodType() == bloodTF);

        if (match) {
            donors.push_back(d);
            found = true;
        }
    }
    
    // Se muestra un mensaje si no se encontraron donantes 
    if (!found) {
        std::cout << "No se encontraron personas del departamento " << provinceName << " o con el tipo de sangre " << bloodTypeFilter;
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'";
        }
        std::cout << "." << std::endl;
    // Se muestran los detalles de los donantes encontrados
    } else {
        std::cout << "Personas de la departamento " << provinceName;

        // Se muestra la dirección si se ingresó una 
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'";
        }
        // Se muestra el tipo de sangre si se ingresó uno
        if (!bloodTypeFilter == 0) {
            std::cout << " y tipo de sangre " << bloodTypeFilter << "\n";
        }
        std::cout << ":" << std::endl;

        // Bucle que muestra los detalles de cada donante
        for (const auto& d : donors) {
            std::cout << "Nombre: " << d.getName() << std::endl;
            std::cout << "Dirección: " << d.getAddress() << std::endl;
            std::cout << "departamento: " << d.getDistrict() << std::endl;
            std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
            std::cout << "Número de móvil: " << d.getNumber() << std::endl;
            std::cout << std::endl;
        }
    }

    inFile.close();
    waitForKeyPress();
}


// Método para eliminar un donante de la base de datos
void BloodDatabase::deleteDonor(const std::string& donorName) {
    std::ifstream inFile(fileName);
    std::ofstream tempFile("temp.txt");

    if (!inFile) {
        std::cerr << "Error al abrir el archivo " << fileName << std::endl;
        return;
    }

    if (!tempFile) {
        std::cerr << "Error al crear el archivo temporal" << std::endl;
        return;
    }

    std::string line; 
    bool found = false;

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        if (d.getName() == donorName) {
            found = true;
            std::cout << "Nombre: " << d.getName() << std::endl;
            std::cout << "Direccion: " << d.getAddress() << std::endl;
            std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
            std::cout << "Numero de móvil: " << d.getNumber() << std::endl;
            std::cout << std::endl;
            std::cout << "¿Esta seguro de que desea eliminar al donante? [s/n]: ";
            char sureChoice;
            std::cin >> sureChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar cualquier entrada extra

            if (sureChoice == 's' || sureChoice == 'S') {
                continue;
            }
        }

        tempFile << d.getDonorId() << ",    " << d.getName() << ",    " << d.getAddress() << ",    " << d.getDistrict() << ",    " << d.getBloodType() << ",    " << d.getNumber() << std::endl;
    }

    inFile.close();
    tempFile.close();

    // Se elimina el archivo original y se renombra el archivo temporal
    if (std::remove(fileName.c_str()) != 0) {
        std::cerr << "Error al eliminar el archivo original" << std::endl;
        return;
    }

    if (std::rename("temp.txt", fileName.c_str()) != 0) {
        std::cerr << "Error al renombrar el archivo temporal" << std::endl;
        return;
    }

    if (!found) {
        std::cout << "No se encontró ningún donante con el nombre " << donorName << std::endl;
    }
}


// Método para mostrar el historial de donantes registrados en la base de datos
void BloodDatabase::donorHistory() {
    // Limpiar la consola y abrir el archivo para lectura
    clearConsole();
    std::ifstream inFile(fileName);

    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::vector<Donor> donors;
    std::string line;

    // Se lee cada línea del archivo, se convierte en un objeto Donor y se agrega a un vector
    while (std::getline(inFile, line)) {
        // Se carga cada linea del archivo en un vector
        donors.push_back(Donor::parseLine(line));
    }
    //Se cierra el archivo
    inFile.close();

    // Ciclo for que itera por cada elemento donor del vector
    for (const auto& d : donors) {
        std::cout << "Nombre: " << d.getName() << std::endl;
        std::cout << "Dirección: " << d.getAddress() << std::endl;
        std::cout << "Departamento: " << d.getDistrict() << std::endl;
        std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl; //cambiar
        std::cout << "Número de móvil: " << d.getNumber() << std::endl;
        std::cout << std::endl;
    }
    waitForKeyPress();

}

