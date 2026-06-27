/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Model.cpp
    Resumen: Implementación de la clase Model encargada de la carga de archivos y objetos y el manejo del tablero.

    Descripción:
    Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
    El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así despejar el paradero.

    
    Autores:
    Estudiante Jhoan Esteban Penagos Lizcano
    Código: 2517537  
    Email: Jhoan.penagos@correounivalle.edu.co

    Estudiante Maria Camila Zuleta Peña
    Código: 2540542
    Email: mariacamilazuletapena@gmail.com
  
    Estudiante: Javier Felipe Contreras Díaz
    Código: 2535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/


#include "Vehiculo.h"
#include "Pasajero.h"
#include "Tablero.h"
#include "Model.h"

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Model::Model(){
}

void Model::cargarTxt(int nivel){
  vehiculos.clear();
  pasajeros.clear();
  std::string archivo = "nivel";
  archivo += std::to_string(nivel);
  archivo += ".txt";
  std::ifstream mapa(archivo);
  std::string auxLine;
  
  while(std::getline(mapa, auxLine)){
    char color;
    char tipo;
    char orientacion;
    int tamano;
    int posX;
    int posY;
    int filas;
    int columnas;
    std::string temp;
    std::stringstream linea(auxLine);
    std::getline(linea,temp,',');
    tipo = temp[0];
    if (tipo == 'D'){
      std::getline(linea,temp,',');
      filas = std::stoi(temp);
      std::getline(linea,temp,',');
      columnas = std::stoi(temp);
      Tablero auxTab(filas,columnas);
      tablero = auxTab;
    }
    else if (tipo == 'P'){
      std::getline(linea,temp,',');
      color = temp[0];
      Pasajero pasajero(color);
      pasajeros.push_back(pasajero);
    }
    else if (tipo== 'V'){ 
      std::getline(linea,temp,',');
      color = temp[0];
      std::getline(linea,temp,',');
      orientacion =temp[0];
      std::getline(linea,temp,',');
      tamano=std::stoi(temp); 
      std::getline(linea,temp,',');
      posX=std::stoi(temp);
      std::getline(linea,temp,',');
      posY = std::stoi(temp);
      Vehiculo vehiculo(tipo,color,orientacion,tamano,posX,posY);
      vehiculos.push_back(vehiculo);
    }
  }
  mapa.close();
}


void Model::cargarVehiculosEnTablero(){
  for (auto& v: vehiculos){
    tablero.setZonaCoches(&v);
  }
}

void Model::cargarPasajerosEnTablero(){
  for (auto& p: pasajeros){
    tablero.pushFilaPasajeros(&p);
  }
}
bool Model::verificarColision(int posX, int posY){
  bool colision = tablero.verificarColision(posX, posY);
  return colision;
}

bool Model::verificarDireccion(char direccion,  int posX, int posY){
  bool direccionCorrecta = tablero.verificarDireccion(direccion, posX, posY);
  return direccionCorrecta;
}

bool Model::moverVehiculo(int posX, int posY, int tam){
  return tablero.moverVehiculo(posX,posY, tam);
}

void Model::pushPasajerosBus(Pasajero* peaton, int i){
  tablero.pushPasajerosBus(peaton, i);
}


Tablero& Model::getTablero(){
  return tablero;
}

