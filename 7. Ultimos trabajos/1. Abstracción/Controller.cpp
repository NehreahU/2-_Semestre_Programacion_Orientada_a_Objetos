#include "Controller.h"
#include "Banco.h"
#include "Cliente.h"
#include "Cuenta.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>


Controller::Controller(View& auxVista, Modelo& auxModelo): vista(auxVista),modelo(auxModelo){
}

void Controller::iniciarSistema(){
  if(modelo.cargarBanco()){
    std::cout<<"Exito cargando base de datos"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1600));
  }
  else{
    std::cout<<"No hay banco cargado, iniciando banco nuevo"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1600));
    modelo.crearBanco();
  }
}

void Controller::añadirUsuario(){
      int idTitular;
      std::cout<<"Ingrese el id del titular que desea ingresar. "<<std::endl;
      std::cin>>idTitular;
      std::cin.ignore(); 
      if(!(modelo.verificarTitular(idTitular))){
        modelo.crearTitular(idTitular);
        modelo.crearCuenta(idTitular);  
        modelo.crearCliente(idTitular);
      }
      else {
        std::cout<<"Ya hay un usuario con ese id de titularidad";
      }
}

void Controller::añadirCuenta(){
    int idTitular;
    std::cout<<"Ingrese el id del titular que desea ingresar. "<<std::endl;
    std::cin>>idTitular;
    std::cin.ignore(); 
    
    std::string idCuenta;
    std::cout<<"Ingrese el id de la cuenta que desea ingresar. "<<std::endl;
    std::getline(std::cin,idCuenta);   
  
    if(modelo.verificarTitular(idTitular)){
      if(!(modelo.verificarCuenta(idTitular, idCuenta))){
        modelo.crearCuenta(idTitular);
      }
      else{
        std::cout<<"Ya existe una cuenta con ese id"<<std::endl;
      }
    }
    else {
      std::cout<<"No hay ningún titular con ese ID"<<std::endl;
    }
}

void Controller::añadirCliente(){
    int idTitular;
    std::cout<<"Ingrese el id del titular que desea ingresar. "<<std::endl;
    std::cin>>idTitular;
    std::cin.ignore();
    
    std::string idCliente;
    std::cout<<"Ingrese el id del cliente que desea ingresar. "<<std::endl;
    std::getline(std::cin,idCliente);   
    
    
    
    if(modelo.verificarTitular(idTitular)){
      if(!(modelo.verificarCliente(idTitular, idCliente))){
        modelo.crearCliente(idTitular);
      }
      else{
        std::cout<<"Ya existe un cliente con ese id"<<std::endl;
      }
    }
    else {
      std::cout<<"No hay ningún titular con ese ID"<<std::endl;
    }
}


void Controller::transferencia(){
      int idTitular;
      std::string idCuenta;
      std::cout<<"Ingrese el id del titular que desea ingresar. "<<std::endl;
      std::cin>>idTitular;
      std::cin.ignore();
      
      std::cout<<"Ingrese el id de la cuenta que desea ingresar. "<<std::endl;
      std::getline(std::cin,idCuenta);
 
      
      if(modelo.verificarTitular(idTitular)){
        int opcion;
        std::cout<<"¿Qué desea hacer?: \n1.Consignar dinero \n2.Retirar dinero"<<std::endl;
        std::cin>>opcion;
        std::cin.ignore();
        
        int dinero;
        std::cout<<"¿De cuanto es el valor de la transferencia?: ";
        std::cin>>dinero;
        std::cin.ignore();  
        std::cout<<std::endl;
        
        switch(opcion){
          case 1:
            modelo.consignarDinero(dinero, idTitular, idCuenta);
            std::cout<<"Su saldo ahora es: "<<modelo.consultarSaldo(idTitular, idCuenta);
            break;
          case 2:
            modelo.retirarDinero(dinero, idTitular, idCuenta);
            std::cout<<"Su saldo ahora es: ";
            modelo.consultarSaldo(idTitular, idCuenta);
        }
      }
      else{
        std::cout<<"No se ha encontrado el titular";
      }        
}

void Controller::limpiar(){
  modelo.limpiar();
}
