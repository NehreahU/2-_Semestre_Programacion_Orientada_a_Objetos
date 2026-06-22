/*
	Proyecto: Avatar en el Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Avatar.cpp
    Resumen: Implementación de la clase Avatar.

	Descripción:
	Implementa la descripción de la clase Avatar, que representa a un personaje dentro de un laberinto. El Avatar es responsable de moverse por el tablero, identificar posibles caminos, almacenar la ruta recorrida y verificar si ha llegado al destino.

	Autor:
        Nombre: Victor Bucheli
	  	Correo: victor.bucheli@correounivalle.edu.co

	Contribuidores:
		Estudiante: Anyela Lineth Cabrera Ordoñez 
		Código: 202540031 
		Email: anyela.cabrera@correounivalle.edu.co
  
		Estudiante: Javier Felipe Contreras Díaz
		Código: 202535936
		Email: contreras.javier@correounivalle.edu.co
		
	Fecha: 11/03/2026
  
@license GNU General Public License v3.0 (GPL)

Este programa es software libre: puede redistribuirlo y/o modificarlo bajo los términos de la Licencia Pública General de GNU publicada por la Free Software Foundation, ya sea la versión 3 de la Licencia, o (a su elección) cualquier versión posterior.

Este programa se distribuye con la esperanza de que sea útil, pero SIN NINGUNA GARANTÍA; incluso sin la garantía implícita de COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR.
Véase la Licencia Pública General de GNU para más detalles.
Debería haber recibido una copia de la Licencia Pública General de GNU junto con este programa. Si no, consulte <https://www.gnu.org/licenses/>. */


// incluir la clase
#include "Avatar.h"
#include "Tablero.h"
#include <iostream>
#include <string>
#include <vector>
// Librerías para generar el aleatorio
#include <stack> // Librería para el manejo de pilas
#include <stdlib.h> // Librería para el manejo de números aleatorios
#include <time.h> // Librería para el manejo de tiempo
#include <random> // Librería para el manejo de números aleatorios
using namespace std;

// Constructor
Avatar::Avatar(Tablero &auxmapa):mapa(auxmapa) {
	//Se inicializa el avatar en la posición 1 en la fila y 1 en la columna
	static random_device rd; //  Se obtiene un número aleatorio 
	static mt19937 gen(rd()); // Se inicializa el generador de números aleatorios
	posX = uniform_int_distribution<int>(0, 9)(gen); // Se genera un número aleatorio entre 0 y 9 para la posición en X
	posY = uniform_int_distribution<int>(0, 9)(gen); // Se genera un número aleatorio entre 0 y 9 para la posición en Y
	ruta.resize(0);//Se inicializa el vector de rutas
        while (mapa.getCelda(posX, posY) != 1){
	    posX = uniform_int_distribution<int>(0, 9)(gen); // Se genera un número aleatorio entre 0 y 9 para la posición en X
	    posY = uniform_int_distribution<int>(0, 9)(gen); // Se genera un número aleatorio entre 0 y 9 para la posición en Y
	    ruta.resize(0);//Se inicializa el vector de rutas
	}
	mapa.setCelda(posX, posY, 7);
}



// Buscar nuevos caminos a partir de la posición actual
void Avatar::mapearNuevosCaminos() {
	guardarPosibleCamino(posX, posY + 1); // Adelante
	guardarPosibleCamino(posX, posY - 1); // Atrás
	guardarPosibleCamino(posX - 1, posY); // Arriba
	guardarPosibleCamino(posX + 1, posY); // Abajo
	mapa.setCelda(posX, posY, 7);
}

// Guardar posibles caminos
void Avatar::guardarPosibleCamino(int posiblex, int posibley) {
	// Verifica que la posición esté dentro de los límites del tablero y que sea un camino (valor 1)
	if ((posiblex >= 0 && posiblex <= 9) && (posibley >= 0 && posibley <= 9)) {
		if (mapa.getCelda(posiblex, posibley) == 1) {
			posiblesCaminosX.push(posiblex);
			posiblesCaminosY.push(posibley);
		}
    
	}
}

// Mover el Avatar
void Avatar::moverAvatar() {
	// Verifica si hay caminos posibles en la pila y se mueve a la primera posición disponible
	if(!posiblesCaminosX.empty()) {
		posX = posiblesCaminosX.top();
		posiblesCaminosX.pop();
		posY = posiblesCaminosY.top();
		posiblesCaminosY.pop();
		mapa.setCelda(posX, posY, 7);
	}
}

// Verificar si el Avatar ha llegado al destino
bool Avatar::haLlegadoAlDestino(int xFinal, int yFinal) const
{
    if (posX == xFinal && posY == yFinal) {
        return true;
    }
    return false;
}

// Mostrar los caminos posibles
void Avatar::mostrarCaminosPosibles() 
{
	stack<int> auxX;
	stack<int> auxY;
	int auxTam = posiblesCaminosX.size();
	auxX = posiblesCaminosX;
	auxY = posiblesCaminosY;
        
        cout << "Los caminos disponibles actualmente son: "<<posiblesCaminosX.size() << endl;
	for (int i = 0; i < auxTam; i++) {
		cout << "posible camino en x: " << auxX.top()+1 << "  ";
		auxX.pop();
		cout << "posible camino en y: " << auxY.top()+1 << endl;
		auxY.pop();
	}
}

// Obtener la posición en X 
int Avatar::getPosX() 
{
	return posX;
}
// Obtener la posición en Y
int Avatar::getPosY() 
{
	return posY;
}

// Guardar la ruta que lleva el Avatar
void Avatar::guardarRuta() 
{
	ruta.push_back({posX,posY});//Guarda la posición de x y y en el vector ruta(x,y)
}

// Imprimir la solución
void Avatar::imprimirSolucion() 
{
	for (int i = 0; i < ruta.size(); i++) {
	    cout << "[x:" << ruta[i][0]+1 << " y:" << ruta[i][1]+1 <<"]"<< endl;
	}
}
