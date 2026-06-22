/*
    Proyecto: Avatar en el Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Tablero.cpp
    Resumen: Implementación de la clase Tablero.

	  Descripción:
	  Implementa la descripción de la clase Tablero, que representa el entorno del juego. El Tablero es responsable de cargar la configuración del laberinto desde un archivo, mostrarlo en pantalla y proporcionar acceso a las celdas para que el Avatar pueda moverse.

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

// Incluir la clase
#include "Tablero.h"
#include <vector>
// Libreria para el manejo de archivos planos
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constructor
Tablero::Tablero()
{
  laberinto.resize(0); //Se inicializa el laberinto en vacío
  nivel = ""; //Se inicializa el nivel en vacío
}

string cambioNivel(int auxNivel){
  switch(auxNivel){
    case 1:
      return "tablero1.txt";
      break;
    case 2:
      return "tablero2.txt";
      break;
    case 3:
      return "tablero3.txt";
      break;
    default:
      return "Desconocido";
    }
  }

// Leer el tablero desde un archivo plano
void Tablero::cargarTablero(int auxNivel)
{
  nivel=cambioNivel(auxNivel);
  ifstream flujoDatos(nivel); // Abrir el archivo plano
  string linea;  // Capturar la información linea a linea del archivo plano
  string aux;
  // Recorrer el archivo plano
  while(getline(flujoDatos, linea))
  {
    vector <int> auxVector; // Vector temporal para cargar el laberinto
    for(int j=0; j<19; j = j+2)
    {
      aux = linea.substr(j, 1);
      auxVector.push_back(stoi(aux));// Cargar el laberinto (atributo) y transformar el dato char a int
    }
    laberinto.push_back(auxVector);// Cargar el laberinto (atributo)
  }
}

//Cambiar celda
void Tablero::setCelda(int x, int y, int valor)
{
  laberinto[x][y] = valor; // Cambia el 1 por el valor dado
}

// Mostrar el tablero en pantalla
void Tablero::mostrarTablero() const {
  vector <int> celdas = {1,2,3,4,5,6,7,8,9,10};
  cout << "x/y"<<"|";
          
  for (int i=0;i<10;i++){
    cout << celdas[i] << " "; 
  }
  cout << endl;
  cout << "___|_____________________";
  cout << endl;
  for(int x=0; x<10; x++){
    if (!(celdas[x]==10)){
    cout << celdas[x]<<"  ";
    }
    else{
      cout << celdas[x]<<" ";
    }
    cout <<"|";
    for(int y=0; y<10; y++){
      cout << laberinto[x][y] << " ";
    }
    cout << endl;
  }
}

// Obtener celda
int Tablero::getCelda(int x, int y) const
{
  return laberinto[x][y]; // Retorna "0" o "1" del tablero
}

