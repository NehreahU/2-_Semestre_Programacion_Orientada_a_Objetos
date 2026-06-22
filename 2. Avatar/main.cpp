/*
	Proyecto: Avatar en el Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: main.cpp
    Resumen: Punto de entrada del sistema de exploración de laberinto.

    Descripción:
    Este archivo contiene la función principal del programa. Se encarga de orquestar la interacción entre las clases Tablero y Avatar, instanciando los objetos necesarios y ejecutando la secuencia lógica
    para la exploración del laberinto y la impresión de la solución.

    Flujo general del programa:
    1. Se instancia el tablero.
    2. Se crea el avatar pasando el tablero
    3. Se inicializa la ruta.
    4. Se exploran posibles caminos.
    5. Se ejecuta un movimiento del avatar.
    6. Se almacena la ruta.
    7. Se imprime la solución de un paso.

  -----------------------------------------------------------------------------
	Autor:
        Nombre: Victor Bucheli
	  	Correo: victor.bucheli@correounivalle.edu.co

	Contribuidores:
		Estudiante: Anyela Lineth Cabrera Ordoñez 
		Codigo: 202540031 
		Email: anyela.cabrera@correounivalle.edu.co
  
		Estudiante: Javier Felipe Contreras Díaz
		Codigo: 202535936
		Email: contreras.javier@correounivalle.edu.co
    
    Fecha: 11/03/2026
@license GNU General Public License v3.0 (GPL)

Este programa es software libre: puede redistribuirlo y/o modificarlo bajo los términos de la Licencia Pública General de GNU publicada por la Free Software Foundation, ya sea la versión 3 de la Licencia, o (a su elección) cualquier versión posterior.

Este programa se distribuye con la esperanza de que sea útil, pero SIN NINGUNA GARANTÍA; incluso sin la garantía implícita de COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR.
Véase la Licencia Pública General de GNU para más detalles.
Debería haber recibido una copia de la Licencia Pública General de GNU junto con este programa. Si no, consulte <https://www.gnu.org/licenses/>. */

// Se incluye la clase
#include "Avatar.h"
#include "Tablero.h"
#include <iostream>
using namespace std;

// Función principal
int main() 
{
    int nivel=0;
    while(nivel != 4){
      cout<<"Elija en nivel que desea seleccionar: \n1. Primer nivel \n2. Segundo nivel \n3. Tercer nivel \n4. Salir\n";
      // Instanciar el tablero y cargarlo desde un archivo
      cin >> nivel;
      if(nivel ==4){
        cout<<"El programa se cerrará\n";
      }
      else if(nivel >0 && nivel <4){
        Tablero mapa;
        mapa.cargarTablero(nivel);
        cout <<endl<< "Usted ha elegido el nivel: "<<nivel<<endl;

        
        // Instanciar el avatar
        Avatar jugador(mapa);
        cout << endl<<"Ubicacion inicial del Avatar: " << endl<< endl;
        jugador.guardarRuta(); 
        jugador.imprimirSolucion();
        mapa.mostrarTablero();
        cout<<endl<<endl;

        // Mientras el avatar no llegue al (9,9), se moverá el avatar hasta llegar al destino (9,9)
        while (!jugador.haLlegadoAlDestino(9, 9)) {
            jugador.mapearNuevosCaminos(); // Buscar nuevos caminos
            jugador.mostrarCaminosPosibles();
            jugador.moverAvatar();
            jugador.guardarRuta();

            cout << "Jugador se movio a (" << jugador.getPosX()+1<< "," << jugador.getPosY()+1 << "): " << endl<< endl; // Mostrar la nueva posición del jugador
            
            mapa.mostrarTablero(); // Mostrar el camino recorrido hasta ahora
            cout<<endl<<endl;
        }
            // Marcar el destino con un 7 en el tablero para visualizarlo
        if (jugador.haLlegadoAlDestino(9,9)) {
            mapa.setCelda(9, 9, 7);
        }
        cout << "Has llegado al destino!" << endl;
        cout << "Ruta final recorrida:" << endl;

        // Mostrar la solución final
        jugador.imprimirSolucion();
        cout<<endl<<endl;

        // Mostrar el tablero final con la ruta del avatar
        mapa.mostrarTablero();
        }
        else{
        cout<<"Error, elija una opción válida\n";
        }
      }
      return 0;
  }
