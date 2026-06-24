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
        Cuenta& cuenta = modelo.crearCuenta(idTitular);  
        Cliente& cliente = modelo.crearCliente(idTitular);
        modelo.crearTitular(idTitular, cliente, cuenta);
      }
      else {
        std::cout<<"Ya hay un usuario con ese id de titularidad";
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
          case 2:
            modelo.retirarDinero(dinero, idTitular);
        }
      }
      else{
        std::cout<<"No se ha encontrado el titular";
      }        
}
