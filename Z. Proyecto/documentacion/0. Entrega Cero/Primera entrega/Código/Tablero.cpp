/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Tablero.cpp
    Resumen: Implementación de la clase Tablero encargada del mapa e interactúa con los objetos que se mueven en el.

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
#include <vector>


Tablero::Tablero(){
}
Tablero::Tablero(int auxFilas, int auxColumnas):filas(auxFilas),columnas(auxColumnas){
  zonaCoches = std::vector<std::vector<Vehiculo*>>(filas, std::vector<Vehiculo*>(columnas, nullptr));
  zonaRecogida = std::vector<Vehiculo*>(4, nullptr);
}


/*p
 < = Horizontal ya que se mueve a la izquierda, carga el vehículo hacia la derecha para que no estorbe en el for del método moverse.
 > = Horizontal ya que se mueve a la derecha, carga el vehículo hacia la izquierda para que no estorbe en el for del método moverse.
 ^ = Vertical ya que se mueve a la arriba, carga el vehículo hacia la abajo para que no estorbe en el for del método moverse.
 v = Vertical ya que se mueve a la abajo, carga el vehículo hacia la arriba para que no estorbe en el for del método moverse.
*/

void Tablero::setZonaCoches(Vehiculo* auxVehiculo){
  int posX = auxVehiculo->getPosX();
  int posY = auxVehiculo->getPosY();
  int tamano = auxVehiculo->getTamano();
  char orientacion = auxVehiculo->getOrientacion();
  
  if (orientacion == '<'){
    for (int i = 0; i<tamano; i++){
      zonaCoches[posX][posY+i] = auxVehiculo;
    }
  }
  else if(orientacion == '>'){
   for (int i = 0; i<tamano; i++){
      zonaCoches[posX][posY-i] = auxVehiculo;
    }
  }
  else if(orientacion == '^'){
   for (int i = 0; i<tamano; i++){
     zonaCoches[posX+i][posY] = auxVehiculo;
   }
  }
  else if(orientacion =='v'){
   for (int i = 0; i<tamano; i++){
     zonaCoches[posX-i][posY] = auxVehiculo;
   }
  } 
}

void Tablero::pushFilaPasajeros(Pasajero* auxPasajero){
  filaPasajeros.push_back(auxPasajero);
}



 
/*
< = Horizontal verificar espacio libre hacia la izquierda
> = Horizontal verificar espacio libre hacia la derecha
^ = Vertical verificar espacio libre hacia arriba
v = vertical verificar espacio libre hacia abajo
*/
 
bool Tablero::verificarColision(int posX,int posY){
 Vehiculo* auxVehiculo = zonaCoches[posX][posY];
 if (auxVehiculo == nullptr) {
  return false;
 }
 char orientacion = auxVehiculo->getOrientacion();
 bool colision = false;
 if (orientacion == '<'){
  for (int i = 1;posY-i >=0; i++){
    if (zonaCoches[posX][posY-i] == nullptr){
      colision = false;
    }
    else {
        return true;
    }
  }
 }
 else if(orientacion == '>'){
  for (int i = 1; posY+i <columnas; i++){ 
    if (zonaCoches[posX][posY+i] == nullptr){
      colision = false;
    }
    else {
        return true;
    }
  }
 }
  else if(orientacion == '^'){
    for (int i = 1; posX-i >= 0; i++){
      if (zonaCoches[posX-i][posY] == nullptr){
        colision = false;
      }
      else {
        return true;
      }
    }
  }
  else if(orientacion == 'v'){
    for (int i = 1; posX+i<filas; i++){
      if (zonaCoches[posX+i][posY] == nullptr){
        colision = false;
      }
      else {
        return true;
      }
    }
  }
 return colision;
}



bool Tablero::verificarDireccion(char direccion, int posX, int posY){
  Vehiculo* auxVehiculo = zonaCoches[posX][posY];
  if (auxVehiculo->getOrientacion() == direccion){ 
    return true;
  }
  return false;
}


 /*
 < = Horizontal se mueve hacia la izquierda
 > = Horizontal se mueve hacia la derecha
 ^ = Vertical se mueve hacia arriba
 v = vertical se mueve hacia abajo
 */


//mueve el vehículo en una dirección, en el controller está en ciclo, al final comprueba si está en las orillas el vehículo y si lo está, lo envía a zona de recogida
bool Tablero::moverVehiculo(int posX, int posY, int tam){
  Vehiculo* auxVehiculo = zonaCoches[posX][posY];
  char orientacion = auxVehiculo->getOrientacion();
  int tamano = auxVehiculo->getTamano()-1;
  int x = auxVehiculo->getPosX();
  int y = auxVehiculo->getPosY();
  if (!(x==0 || y == 0 ||x==filas-1 || y==columnas-1 )){
    if (orientacion == '<'){
          zonaCoches[x][y+tamano] = nullptr;
          zonaCoches[x][y-1] = auxVehiculo;
          auxVehiculo->setPos(x,y-1);
          return true;
    }
    else if(orientacion == '>'){
          zonaCoches[x][y-tamano] = nullptr;
          zonaCoches[x][y+1] = auxVehiculo;
          auxVehiculo->setPos(x,y+1);
          return true;
    }
    else if(orientacion == '^'){
        zonaCoches[x+tamano][y] = nullptr;
        zonaCoches[x-1][y] = auxVehiculo;
        auxVehiculo->setPos(x-1,y);
        return true;
    }
    else if(orientacion == 'v'){
        zonaCoches[x-tamano][y] = nullptr;
        zonaCoches[x+1][y] = auxVehiculo;
        auxVehiculo->setPos(x+1,y);
        return true;
    }
  }
  //Acá se elimina un puntero en el tablero x=tamaño posiciones en el tablero, cuando está en el borde, controller le resta 1 a tam y acá se elimina en su propia posición en el tablero
  else if ((x==0 || y == 0 ||x==filas-1 || y==columnas-1) && tam >= 0){
      if(orientacion == '^'){
        zonaCoches[x+tam][y]= nullptr;
      }
      else if(orientacion == 'v'){
        zonaCoches[x-tam][y] = nullptr;
      }
      else if(orientacion == '>'){
        zonaCoches[x][y-tam] = nullptr;
      }
      else if(orientacion == '<'){
        zonaCoches[x][y+tam] = nullptr;
      }
      if (tam == 0){
        if(zonaRecogida[0] == nullptr && zonaRecogida[1] == nullptr && zonaRecogida[2] == nullptr && zonaRecogida[3] == nullptr){
          zonaRecogida.clear();
        }
        for (int i = 0 ; i < 4; i++){
         if (!(zonaRecogida[i])){
          zonaRecogida[i] = auxVehiculo;
          int newPosY = zonaRecogida.size()-1;
          auxVehiculo->setPos(0,i);
          //Como ya se encontró un puntero vacío, y se ubicó al auxVehiculo, entonces se retorna false para que en el controller deje de moverse. 
          return false;
         }
        }
      }
      return true;
  }
  return false;
}


void Tablero::pushPasajerosBus(Pasajero* peaton, int i){
 Vehiculo* coche = zonaRecogida[i];
 coche->pushPasajerosBus(peaton);
 filaPasajeros.erase(filaPasajeros.begin()); 
}

    

  

std::vector<Pasajero*>& Tablero::getFilaPasajeros(){
  return filaPasajeros;
}

std::vector<Vehiculo*>& Tablero::getZonaRecogida(){
  return zonaRecogida;
}

std::vector<std::vector<Vehiculo*>>& Tablero::getZonaCoches(){
  return zonaCoches;
}

int Tablero::getFilas(){
  return filas;
}

int Tablero::getColumnas(){
  return columnas;
}





