/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Controller.cpp
    Resumen: Implementación de la clase Controller, que maneja el view y el model.

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


#include "Controller.h"
#include "Model.h"
#include "View.h"
#include <iostream>
#include "Tablero.h"
#include <thread>
#include <chrono>
#include <string>

Controller::Controller(Model& auxModelo, View& auxVista): vista(auxVista), model(auxModelo){
}



//Inicia el juego e imprime el mapa
          bool Controller::iniciarJuego(){
            
            //Muestra un titulo de menú.
           vista.mostrarMenu();
            //elegir el nivel 
           std::cout<<"¿Ingrese el número del nivel desea cursar?: \n1.Nivel uno \n2.Nivel dos \n3.Nivel tres. \n0. Ingrese cero para cerrar."<<std::endl<<std::endl;
           while(!(std::cin>>nivel) || nivel < 0 || nivel >3){
           std::cout<<"¿Ingrese un número válido del nivel desea cursar?: \n1.Nivel uno \n2.Nivel dos \n3.Nivel tres \n0. Ingrese cero para cerrar."<<std::endl<<std::endl;
           std::cin.clear();
           std::cin.ignore();
           }

            if(nivel == 0){
              return false;
            }
           
            //cargar el archivo según el nivel
            model.cargarTxt(nivel);
            model.cargarVehiculosEnTablero();
            model.cargarPasajerosEnTablero();
           
            //mostrar mapa
            vista.mostrarNivel(nivel);
            vista.mostrarMapa(model.getTablero());
            return true;
}
          

    void Controller::mostrarMapa(){
     
     //mostrar mapa
     vista.mostrarNivel(nivel);
     vista.mostrarMapa(model.getTablero());
    }



void Controller::movimientosVehiculos(){
  int posX1;
  int posY1;
  std::string dir;
  std::cout<<"Qué vehículo desea mover, ingrese las filas [↓↑] de enter e ingrese las columnas [←→] y de enter"<<std::endl;
  std::cin>>posX1>>posY1;
  //le resta uno a cada pos, ya que c++ lee desde 0.
  posX1-=1;
  posY1-=1;
  //creo un puntero llamado vehículo que apunta a un objeto Vehículo que está en el vector Zona Coches. 
  Vehiculo* vehiculo = model.getTablero().getZonaCoches()[posX1][posY1]; 
  int posX = vehiculo->getPosX();
  int posY = vehiculo->getPosY();
  
  //Mientras el puntero vehículo sea falso hace un bucle para pedir la posición nuevamente y restarle uno a cada uno nuevamente.
  while( !(vehiculo)){
    std::cout<<"Error. Posición no válida"<<std::endl;
    std::cout<<"Qué vehículo desea mover, ingrese las filas [↓↑] de enter e ingrese las columnas [←→] y de enter"<<std::endl;
    std::cin>>posX1>>posY1;
    posX1-=1;
    posY1-=1;
    vehiculo = model.getTablero().getZonaCoches()[posX][posY];
    posX = vehiculo->getPosX();
    posY = vehiculo->getPosY();
  }
 
 
 std::cout<<"¿Ingrese el número de la dirección en la que se desea mover: "<<std::endl;  
 std::cout<<R"(
               1. Arriba
 3. Izquierda           4.Derecha
              2. Abajo)";
             
  std::cout<<std::endl;
  
 //mientras dir que es la dirección sea falso, y además dir no sea 1, 2, 3 o 4, se hace un while
 while(!(std::cin>>dir) || !(dir == "1" || dir == "2" || dir == "3" || dir == "4")){
   std::cout<<"¿Ingrese el número de la dirección en la que se desea mover: "<<std::endl;
   std::cout<<R"(
                1. Arriba
   3. Izquierda           4.Derecha
               2. Abajo)";
 std::cout<<std::endl;
 std::cin.clear();
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 }
  
  //convierte dir en un char llamado direccion
  char direccion;
  direccion = dir[0];
  switch(direccion){
    case '1': {
      dir = "^";
    }
    break;
    case '2': {
      dir = "v";
    }
    break;
    case '3': {
      dir = "<";
    }
    break;
    case '4': {
      dir = ">";
    }
    break;
  }
  //al finalizar dirección cambia de ser un char numerico a un char de direccion <,^,>,v
  direccion = dir[0];

  //verifica colisión y dirección antes de seguir con el movimiento.
  if (!(model.verificarColision(posX,posY))){
    if(model.verificarDireccion(direccion,posX,posY)){
        //Ya que sabemos que no hay colisión y que la dirección es correcta, invocamos al puntero Carro.
        Vehiculo* carro = model.getTablero().getZonaCoches()[posX][posY]; 
        int tam = carro->getTamano();
        //mientras se pueda mover y se mueva el vehículo hará
        while(model.moverVehiculo(posX,posY,tam)){         
            posX = carro->getPosX();
            posY = carro->getPosY();
            //antes de seguir, vemos si el vehículo está en un borde, de ser así se le reduce el tamaño para que el próximo while tam elimine su propia posicion en el tablero de punteros        
            if (carro->getPosX() == 0 ||carro->getPosY() == 0 || carro->getPosX()== model.getTablero().getFilas()-1 ||carro->getPosY()== model.getTablero().getColumnas()-1){
            tam -= 1;
          }
          
          vista.mostrarNivel(nivel);
          vista.mostrarMapa(model.getTablero());
          std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
      }
    }
  }

void Controller::pushPasajerosBus(){
  for(int i = 0; i <4; i++){
    std::vector<Vehiculo*>& zonaRecogida =  model.getTablero().getZonaRecogida();
    Vehiculo* carro = zonaRecogida[i];
    if(carro){
          char colorCarro = carro->getColor();
          std::vector<Pasajero*>& filaPasajeros = model.getTablero().getFilaPasajeros();
          Pasajero* peaton = filaPasajeros[0];
          int capacidad = carro->getTamano()*2;
          int estCap = carro->getSizeSillas();
        if(peaton){
          char colorPeaton = peaton->getColor(); 
          if (estCap == capacidad ){
            zonaRecogida[i]== nullptr; 
            vista.mostrarNivel(nivel);
            vista.mostrarMapa(model.getTablero());
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
          }
          while((estCap < capacidad) && (colorCarro == colorPeaton) ){
              vista.mostrarNivel(nivel);
              vista.mostrarMapa(model.getTablero());
              std::this_thread::sleep_for(std::chrono::milliseconds(400));
              model.pushPasajerosBus(peaton,i);
              estCap = carro->getSizeSillas();
              if(!(filaPasajeros.empty())){
                peaton = filaPasajeros[0];
                colorPeaton = peaton->getColor();
                if(colorPeaton != colorCarro){
                  i=0;
                }
              }
              else if(filaPasajeros.empty()){
                colorPeaton = 'N';
              }
          }
          
        }
      }
    }
}



