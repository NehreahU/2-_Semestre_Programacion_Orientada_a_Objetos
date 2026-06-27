/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Main.cpp
    Resumen: Implementación del main, que maneja el flujo del programa a través del controller.

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


int main() {

  View vista;
  Model modelo;
  Controller control(modelo, vista);
    while(control.iniciarJuego()){
      for(int i =0; i = 30; i++){
      control.movimientosVehiculos();
      control.pushPasajerosBus();
      control.pushPasajerosBus();
      control.pushPasajerosBus();
      control.pushPasajerosBus();
      control.mostrarMapa();

      }
    }

  return 0;
}

