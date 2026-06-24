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
    parse.cargarClientes(clientes);
    parse.cargarCuentas(cuentas);
    parse.cargarTitulares(banco,clientes, cuentas);
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
}


bool Modelo::verificarTitular(int idTitular){
  if(banco.verificarTitular(idTitular)){
    return true;
  }
  else{
   return false;
  }
}


Cuenta& Modelo::crearCuenta(int idTitular){ //Se crea objeto cuenta y se envía al vector de cuentas.
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
      CuentaAhorros cuenta(idTitular, id, saldo, "CuentaAhorros");
      cuentas.push_back(cuenta);
      return cuentas.back();
      break;
    }
    case 2:{
      CuentaCorriente cuenta(idTitular, id, saldo, "CuentaCorriente");
      cuentas.push_back(cuenta);
      return cuentas.back();
    }
    default:{
      throw std::invalid_argument("Error");
    }
  }
}



Cliente& Modelo::crearCliente(int idTitular){ //Se crea un objeto cliente y se envía al vector cliente.
  std::string identificacion;
  std::string nombre;
  std::string telefono;
  
  std::cout<<"Ingrese la identificación del cliente"<<std::endl;
  std::getline(std::cin, identificacion);
  
  std::cout<<"Ingrese el nombre del cliente"<<std::endl;
  std::getline(std::cin, identificacion);
  
  std::cout<<"Ingrese el teléfono del cliente"<<std::endl;
  std::getline(std::cin, telefono);
  
  Cliente cliente(idTitular, identificacion,nombre,telefono);
  clientes.push_back(cliente);
  return clientes.back();

}


void Modelo::crearTitular(int idTitular, Cliente& cliente, Cuenta& cuenta){                          //se crea un objeto titular con dos ojetos Cliente&  y Cuenta& allá en titular el recibe titular(cliente*, cuenta*)
  std::string tipoTitular;
  std::string fechaVinculacion;
  
  std::cout<<"Qué tipo de titularidad tiene"<<std::endl;
  std::getline(std::cin, tipoTitular);
  
  std::cout<<"Escriba la fecha de vinculación"<<std::endl;
  std::getline(std::cin, fechaVinculacion);
  for(auto& cu: cuentas){
      if(cu.getIdTitular() == idTitular){
        for(auto& cli: clientes){
          if(cli.getIdTitular() == idTitular){
              Titular titular(&cli, &cu, idTitular, tipoTitular,fechaVinculacion);
              banco.addTitular(titular); 
          }
        }
      }
   }
}




void Modelo::consignarDinero(int dinero, int idProceso){
  for (auto& cuenta: cuentas){
    if(cuenta.getIdTitular() == idProceso){
      cuenta.consignarDinero(dinero);
    }
  }
}

void Modelo::retirarDinero(int dinero,int idProceso){
  for(auto& cuenta: cuentas){
    if(cuenta.getIdTitular() == idProceso){
      cuenta.retirarDinero(dinero);
    }
  }
}


int Modelo::consultarSaldo(int idProceso){
  for(auto& cuenta: cuentas){
    if(cuenta.getIdTitular() == idProceso){
      return cuenta.getSaldo();
    }
  }
  return 0;
}
