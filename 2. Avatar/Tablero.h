/*
	  Proyecto: Avatar en el Laberinto
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Tablero.cpp
    Resumen: Implementación de la clase Tablero.

	  Descripción: Implementa la abstracción del entorno de juego representado como un laberinto bidimensional. La clase Tablero es responsable de gestionar la estructura interna del mapa, permitir su carga desde archivo, visualizarlo en pantalla y ofrecer acceso controlado a sus celdas.

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


    Estándar CRC (Clase - Responsabilidad - Colaboración):

    Clase:
      Tablero

    Responsabilidades:
      - Representar el laberinto como una matriz bidimensional.
      - Cargar la configuración del tablero desde un archivo externo (.txt).
      - Mostrar gráficamente el tablero en consola.
      - Proporcionar acceso controlado a las celdas del laberinto.
      - Gestionar y almacenar el nivel actual del juego.

    Colaboradores:
        - Avatar:
         * Consulta el estado de las celdas del tablero.
         * Utiliza la información del laberinto para validar movimientos.

@license GNU General Public License v3.0 (GPL)

Este programa es software libre: puede redistribuirlo y/o modificarlo bajo los términos de la Licencia Pública General de GNU publicada por la Free Software Foundation, ya sea la versión 3 de la Licencia, o (a su elección) cualquier versión posterior.

Este programa se distribuye con la esperanza de que sea útil, pero SIN NINGUNA GARANTÍA; incluso sin la garantía implícita de COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR.
Véase la Licencia Pública General de GNU para más detalles.
Debería haber recibido una copia de la Licencia Pública General de GNU junto con este programa. Si no, consulte <https://www.gnu.org/licenses/>. */


// Candado: Evita la doble declaración
#ifndef _TABLERO_H_
#define _TABLERO_H_
#include <vector>
#include <string>
using namespace std;

// Nombre clase
class Tablero
{
  // Atributos
  private: 
    vector <vector <int> > laberinto;//un vector de vectores de 1 o 0 donde hay camino o precipicio
    string nivel; //Almacena el nivel del juego
    

  // Métodos
  public:
 
    Tablero();   // Método constructor
    void setCelda(int x, int y, int valor);// Cambiar el valor de una celda (x,y) del tablero
    void cargarTablero(int nombreDelArchivo);// Permite cargar el tablero desde un archivo .txt
    void mostrarTablero() const;// Muestra el tablero en pantalla
    int getCelda(int x, int y) const;// Retorna "0" o "1" del tablero
    int getNivel() const;    // Retorna el nivel del juego
};

// Cierro el candado
#endif
