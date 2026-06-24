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
  std::cout<<"Qué desea hacer: \n1.Añadir Usuario \n2.Transferir saldo"<<std::endl;
  std::cin>>opcion;
  
  switch(opcion){
    case 1:
      control.añadirUsuario();
      break;
    case 2:
      control.transferencia ();
  }


return 0;
}
