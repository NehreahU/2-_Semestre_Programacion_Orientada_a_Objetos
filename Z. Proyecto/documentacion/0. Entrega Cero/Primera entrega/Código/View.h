/*
    Clase: View
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: View.h
    Resumen: Implementación de la clase View encargada de impresión de datos en pantalla y el manejo del tablero en pantalla.
    
    Descripción:
        Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
        El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así     despejar el paradero.

    Información CRC:
    
    Clase: View

    Responsabilidades:
        -Encargarse de la interfaz de usuario en modo texto, transformando 
          las matrices numéricas y punteros del sistema en información en pantalla.
        -Mostrar en la consola los menús interactivos, las pantallas de selección 
          de nivel y los títulos decorativos del juego.

   Colaboradores:

      Tablero: Recibe una referencia del tablero como parámetro en su método mostrarMapa
              (Tablero& paradero) para poder leer la matriz de datos e imprimir en pantalla.

      Vehiculo: Accede a los Getters de los vehículos para imprimirlos en la interfaz de usuario.

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.


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


#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "Tablero.h"

class View{

private: 

public:

View();

void mostrarMenu();
void mostrarNivel(int nivel);
void mostrarMapa(Tablero& datosMapa);
};

#endif
