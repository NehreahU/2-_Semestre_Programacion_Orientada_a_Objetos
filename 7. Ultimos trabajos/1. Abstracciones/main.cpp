#include "Controller.h"
#include "Modelo.h"
#include "View.h"
#include <iostream>


int main(){
  
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
  View vista;
  Modelo modelo;
  Controller control(vista, modelo);

  control.iniciarSistema();
  
  int opcion;
  std::cout<<"Qué desea hacer: \n1.Crear Usuario \n2.Transferir saldo \n3. Añadir cuenta \n4. Añadir Cliente \n0. Ingrese cero para cerrar."<<std::endl;
  std::cin>>opcion;
  while(opcion != 0){
    switch(opcion){
      case 1:
        control.añadirUsuario();
        break;
      case 2:
        control.transferencia ();
        break;
      case 3:
        control.añadirCuenta();
        break;
      case 4:
        control.añadirCliente();
    }
    std::cout<<"Qué desea hacer: \n1.Crear Usuario \n2.Transferir saldo \n3. Añadir cuenta \n4. Añadir Cliente \n0. Ingrese cero para cerrar."<<std::endl;
    std::cin>>opcion;
  }
  control.limpiar();

return 0;
}
