/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: View.cpp
    Resumen: Implementación de la clase View encargada de impresión de datos en pantalla y el manejo del tablero en pantalla.

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
#include <string>
#include "Tablero.h"
#include "View.h"
#include <iostream>
#include <vector>

View::View(){
}

void View::mostrarMenu(){
   #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
  std::cout<<R"(
                                                                      █   █ █████ █   █ █   █   
                                                                      ██ ██░█░░░░░██  █░█░  █░  
                                                                      █░█ █░████░░█░█ █░█░░ █░░ 
                                                                      █░░░█░█░░░░ █░░██░█░░ █░░ 
                                                                      █░░ █░█████░█░░ █░░███ ░░ 
                                                                       ░░  ░░░░░░░ ░░  ░░ ░░░ ░ 
                                                                        ░   ░ ░░░░░ ░   ░  ░░░  )"<<std::endl<<std::endl<<std::endl;
                                                                        
}



void View::mostrarNivel(int nivel){
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
  switch(nivel){
    case 1:{
      std::cout<<R"(
                                                                    █   █ ███ █   █ █████ █          █     
                                                                    ██  █░ █░░█░  █░█░░░░░█░        ██░    
                                                                    █░█ █░░█░░█░░ █░████░░█░░        █░░   
                                                                    █░░██░░█░░ █░█ ░█░░░░ █░░        █░░   
                                                                    █░░ █░███░  █ ░ █████░█████     ███░   
                                                                     ░░  ░░░░░   ░ ░ ░░░░░ ░░░░░     ░░░   
                                                                      ░   ░ ░░░   ░   ░░░░░ ░░░░░     ░░░  )";}
    break;
    case 2:{
      std::cout<<R"(
                                                                    █   █ ███ █   █ █████ █         ███    
                                                                    ██  █░ █░░█░  █░█░░░░░█░       █ ░░█   
                                                                    █░█ █░░█░░█░░ █░████░░█░░       ░ █░░  
                                                                    █░░██░░█░░ █░█ ░█░░░░ █░░        █ ░ ░ 
                                                                    █░░ █░███░  █ ░ █████░█████    █████░  
                                                                     ░░  ░░░░░   ░ ░ ░░░░░ ░░░░░    ░░░░░  
                                                                      ░   ░ ░░░   ░   ░░░░░ ░░░░░    ░░░░░ )";}
    break;
    case 3:{
      std::cout<<R"(
                                                                    █   █ ███ █   █ █████ █        ████    
                                                                    ██  █░ █░░█░  █░█░░░░░█░        ░░░█   
                                                                    █░█ █░░█░░█░░ █░████░░█░░       ███░░  
                                                                    █░░██░░█░░ █░█ ░█░░░░ █░░        ░░█ ░ 
                                                                    █░░ █░███░  █ ░ █████░█████    ████░░  
                                                                     ░░  ░░░░░   ░ ░ ░░░░░ ░░░░░    ░░░░ ░ 
                                                                      ░   ░ ░░░   ░   ░░░░░ ░░░░░    ░░░░  )";}
    break;
  }
  std::cout<<std::endl;
}


void View::mostrarMapa(Tablero& datosMapa){
  int filas = datosMapa.getFilas();
  int columnas = datosMapa.getColumnas();
  std::vector<Pasajero*>& filaPasajeros = datosMapa.getFilaPasajeros();
  std::vector<Vehiculo*>& zonaRecogida = datosMapa.getZonaRecogida();
  std::vector<std::vector<Vehiculo*>>& zonaCoches = datosMapa.getZonaCoches();
  
  Pasajero* auxPasajero;
  int tamanoFila = filaPasajeros.size()-1;
  std::cout<<"             ";
  for(int i = 3; i <=tamanoFila; i++){
    std::cout<<"@    ";
  }
    std::cout<<std::endl<<"           ";
    for(int i = 3; i <=tamanoFila; i++){
    auxPasajero = filaPasajeros[i];
    char color = auxPasajero->getColor();
    std::cout<<"/("<<color<<")\\";
    }
    std::cout<<std::endl<<"            ";
    for(int i = 3; i <=tamanoFila; i++){
      std::cout<<"IL   ";
    }
  std::cout<<std::endl;
  for(int i = 2; i >= 0; i--){
    auxPasajero = filaPasajeros[i];
    char color = auxPasajero->getColor();
    std::cout<<"            ";
    std::cout<<"@"<<std::endl;
    std::cout<<"          ";    
    std::cout<<"/("<<color<<")\\"<<std::endl;
    std::cout<<"           ";  
    std::cout<<"IL"<<std::endl;
  }
  
  Vehiculo* auxRecogida;
  for(int j = 0; j <= 2; j++){
    std::cout<<"           ";
    for (int i = 0; i < 4; i++){
      auxRecogida = zonaRecogida[i];

      if(auxRecogida == nullptr){
        std::cout<<"[  ]";
      }
      else{
          int tamCoche = auxRecogida->getTamano();
          if(j < tamCoche){
          char orientacion = auxRecogida->getOrientacion();
          char color = auxRecogida->getColor();
          std::string coche;
          coche = orientacion;
          coche += color;
          std::cout<<"["<<coche<<"]";
          }
          else {
           std::cout<<"[  ]";
          }
          }
      }
    std::cout<<std::endl;
  }
  
  std::cout<<std::endl;
  std::cout<<"                          ===1===2===3===4===5===6===7===8===9===10==="<<std::endl;  
  std::cout<<"                          ============================================"<<std::endl;
  Vehiculo* auxVehiculo;
  std::vector <int> vectorFilas = {1,2,3,4,5,6,7,8,9,10};
  for (int i = 0 ; i < filas; i++){
    if (i > 8) {
      std::cout<<"                        "<<vectorFilas[i]<<"||";
    }
    else if(i <= 8) {
      std::cout<<"                         "<<vectorFilas[i]<<"||";
    }
    for (int j = 0; j < columnas; j++){
      if(zonaCoches[i][j] == nullptr){
        std::cout<<"[  ]";
      }
      else{
        auxVehiculo = zonaCoches[i][j];
        char orientacion = auxVehiculo->getOrientacion();
        char color = auxVehiculo->getColor();
        std::string coche;
        coche = orientacion;
        coche += color;
        std::cout<<"["<<coche<<"]";
      }
    }
    std::cout<<"||"<<vectorFilas[i];
    std::cout<<std::endl;
  }
  std::cout<<"                          ============================================"<<std::endl; 
  std::cout<<"                          ===1===2===3===4===5===6===7===8===9===10==="<<std::endl;  
  std::cout<<std::endl<<std::endl<<std::endl;
}







