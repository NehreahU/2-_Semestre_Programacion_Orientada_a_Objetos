#include "Controller.h"
#include "Banco.h"
#include "Cliente.h"
#include "Cuenta.h"
#include <string>
#include <iostream>


Controller::Controller(View& auxVista, Modelo& auxModelo): vista(auxVista),modelo(auxModelo){
}

void Controller::iniciarSistema(){
  if(modelo.cargarBanco()){
    std::cout<<"Exito cargando base de datos"<<std::endl;
  }
  else{
    std::cout<<"No hay banco cargado, iniciado"<<std::endl;
    modelo.crearBanco();
  }
}

void Controller::añadirUsuario(){
      int idTitular;
      std::cout<<"Ingrese el id del titular que desea ingresar. "<<std::endl;
      std::cin>>idTitular;
      
      if(!(modelo.verificarTitular(idTitular))){
        modelo.crearTitular(idTitular);
        modelo.crearCuenta(idTitular);  
        modelo.crearCliente(idTitular);
      }
      else {
        std::cout<<"Ya hay un usuario con ese id de titularidad";
      }
}

void añadirCuenta(){
    int idTitular;
    std::cout<<"Ingrese el id del titular que desea ingresar. "<<std::endl;
    std::cin>>idTitular;
    if(modelo.verificarTitular(idTitular)){
      contro.crearCuenta(idTitular);
    }
    else {
      std::cout"No hay ningún titular con ese ID"<<std::endl;
    }
}

void añadirCliente(){
    int idTitular;
    std::cout<<"Ingrese el id del titular que desea ingresar. "<<std::endl;
    std::cin>>idTitular;
    if(modelo.verificarTitular(idTitular)){
      contro.crearCliente(idTitular);
    }
    else {
      std::cout"No hay ningún titular con ese ID"<<std::endl;
    }
}


void Controller::transferencia(){
      int idTitular;
      std::cout<<"Ingrese el id del titular que desea ingresar. "<<std::endl;
      std::cin>>idTitular;
      
      if(modelo.verificarTitular(idTitular)){
        int opcion;
        std::cout<<"¿Qué desea hacer?: \n1.Consignar dinero \n2.Retirar dinero"<<std::endl;
        std::cin>>opcion;
        
        int dinero;
        std::cout<<"¿De cuanto es el valor de la transferencia?: ";
        std::cin>>dinero;
        std::cout<<std::endl;
        
        switch(opcion){
          case 1:
            modelo.consignarDinero(dinero, idTitular);
            modelo.consultadSaldo(idTitular);
          case 2:
            modelo.retirarDinero(dinero, idTitular);
            modelo.consultadSaldo(idTitular);
        }
      }
      else{
        std::cout<<"No se ha encontrado el titular";
      }        
}
