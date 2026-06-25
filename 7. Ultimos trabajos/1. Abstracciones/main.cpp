#include "Controller.h"
#include "Modelo.h"
#include "View.h"
#include <iostream>


int main(){
  
  View vista;
  Modelo modelo;
  Controller control(vista, modelo);
  system("clear");
  control.iniciarSistema();
  
  int opcion;
  std::cout<<"Qué desea hacer: \n1.Crear Usuario \n2.Transferir saldo \n3. Añadir cuenta \n4. Añadir Cliente"<<std::endl;
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
      contro.añadirCliente();
  }
  std::cout<<"Qué desea hacer: \n1.Crear Usuario \n2.Transferir saldo \n3. Añadir cuenta \n4. Añadir Cliente"<<std::endl;
  std::cin>>opcion;
}

return 0;
}
