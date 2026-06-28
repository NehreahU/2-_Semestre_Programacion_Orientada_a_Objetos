#include "Modelo.h"
#include "Parse.h"
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"
#include <iostream>
#include <string>


Modelo::Modelo(): banco("NN"){
}

bool Modelo::cargarBanco(){
  Parse parse;
  if(parse.cargarBanco(banco)){
    parse.cargarClientes(banco);
    parse.cargarCuentas(banco);
    parse.cargarTitulares(banco);
    return true;
  }
  else {
   return false;
  }
}

void Modelo::crearBanco(){
  std::string nombre;
  std::cout<<"Ingrese el nombre de su Banco: ";
  std::getline(std::cin, nombre);
  banco.setNombre(nombre);
  std::vector<Titular> titulares;
  titulares.clear();
  banco.setTitulares(titulares);
  Parse parse;
  parse.guardar(banco);
}


bool Modelo::verificarTitular(int idTitular){
  if(banco.verificarTitular(idTitular)){
    return true;
  }
  else{
   return false;
  }
}

bool Modelo::verificarCuenta(int idTitular, std::string idCuenta){
  if(banco.verificarCuenta(idTitular, idCuenta)){
    return true;
  }
  else{
   return false;
  }
}



bool Modelo::verificarCliente(int idTitular, std::string idCliente){
  if(banco.verificarCliente(idTitular, idCliente)){
    return true;
  }
  else{
   return false;
  }
}



void Modelo::crearTitular(int idTitular){                          //se crea un objeto titular con dos objetos Cliente&  y Cuenta& allá en titular el recibe titular(cliente*, cuenta*)
  std::string tipoTitular;
  std::string fechaVinculacion;
  std::cout<<"Qué tipo de titularidad tiene"<<std::endl;
  std::getline(std::cin, tipoTitular);
  
  std::cout<<"Escriba la fecha de vinculación"<<std::endl;
  std::getline(std::cin, fechaVinculacion);
  
  Titular titular(idTitular, tipoTitular,fechaVinculacion);
  banco.addTitular(titular); 
  
  //Guardar
  Parse parse;
  parse.guardar(banco);
}



void Modelo::crearCuenta(int idTitular){ //Se crea objeto cuenta y se envía al vector de cuentas.
  std::string id;
  long saldo;
  int tipoCuenta;
  
  
  std::cout<<"Ingrese el ID de la cuenta"<<std::endl;
  std::getline(std::cin,id);
  
  std::cout<<"Ingrese el saldo con el que inicia la cuenta"<<std::endl;
  std::cin>>saldo;
  
  std::cout<<"Ingrese el tipo de cuenta: 1. Cuenta de ahorros. 2. Cuenta Corriente."<<std::endl;
  std::cin>>tipoCuenta;
  
  switch (tipoCuenta){
    case 1:{
      CuentaAhorros* cuentaPtr = new CuentaAhorros(idTitular, id, saldo, "CuentaAhorros");
      banco.getTitular(idTitular).addCuenta(cuentaPtr);
      break;
    }
    case 2:{
      CuentaCorriente* cuentaPtr = new CuentaCorriente(idTitular, id, saldo, "CuentaCorriente");
      banco.getTitular(idTitular).addCuenta(cuentaPtr);
      break;
    }
    default:{
      throw std::invalid_argument("Error: "+std::string(__FILE__)+" "+std::to_string(__LINE__));
    }
  }
  Parse parse;
  parse.guardar(banco);
}



void Modelo::crearCliente(int idTitular){ //Se crea un objeto cliente y se envía al vector cliente.
  std::string identificacion;
  std::string nombre;
  std::string telefono;
  std::cout<<"Ingrese la identificación del cliente"<<std::endl;
  std::getline(std::cin, identificacion);
  
  std::cout<<"Ingrese el nombre del cliente"<<std::endl;
  std::getline(std::cin, identificacion);
  
  std::cout<<"Ingrese el teléfono del cliente"<<std::endl;
  std::getline(std::cin, telefono);
  
  Cliente* clientePtr = new Cliente(idTitular, identificacion,nombre,telefono);
  banco.getTitular(idTitular).addCliente(clientePtr);
  Parse parse;
  parse.guardar(banco);

}





void Modelo::consignarDinero(int dinero, int idProceso, std::string idCuenta){
  std::vector<Titular> titulares = banco.getTitulares();
  for(auto& titular: titulares){
    if(titular.getIdTitular() == idProceso){
      std::vector<Cuenta*>& cuentas = titular.getCuentas();
      for (auto& cuenta: cuentas){
        if(cuenta->getIdTitular() == std::stoi(idCuenta)){
          cuenta->consignarDinero(dinero);
        }
      }
    }
  }//end primer for
}

void Modelo::retirarDinero(int dinero,int idProceso, std::string idCuenta){
  std::vector<Titular> titulares = banco.getTitulares();
  for(auto& titular: titulares){
    if(titular.getIdTitular() == idProceso){
      std::vector<Cuenta*>& cuentas = titular.getCuentas();
      for (auto& cuenta: cuentas){
        if(cuenta->getIdTitular() == std::stoi(idCuenta)){
          cuenta->retirarDinero(dinero);
        }
      }
    }
  }//end primer for
}

int Modelo::consultarSaldo(int idProceso, std::string idCuenta){
  std::vector<Titular> titulares = banco.getTitulares();
  for(auto& titular: titulares){
    if(titular.getIdTitular() == idProceso){
      std::vector<Cuenta*>& cuentas = titular.getCuentas();
      for (auto& cuenta: cuentas){
        if(cuenta->getIdTitular() == std::stoi(idCuenta)){
          return cuenta->getSaldo();
        }
      }
    }
  }//end primer for
  return 0;
}



void Modelo::limpiar(){
  
  std::vector<Titular>& titulares = banco.getTitulares();
  for(auto& titular: titulares){
    
    std::vector<Cliente*>& clientes = titular.getClientes();    
    for(auto* cliente: clientes){
      delete cliente;
    }
    clientes.clear();
    std::vector<Cuenta*>& cuentas = titular.getCuentas();
    for(auto* cuenta: cuentas){
      delete cuenta;
    }
    cuentas.clear();
  }
  titulares.clear();
}
