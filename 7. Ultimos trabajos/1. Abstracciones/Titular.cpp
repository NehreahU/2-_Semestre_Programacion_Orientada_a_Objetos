#include "Titular.h"


Titular::Titular(int auxID,std::string auxTipo,std::string auxFecha): idTitular(auxID), tipoTitular(auxTipo),fechaVinculacion(auxFecha){
}

Titular::Titular(std::vector<Cliente*> auxClientes,std::vector<Cuenta*> auxCuentas,int auxID,std::string auxTipo,std::string auxFecha): clientes(auxClientes),cuentas(auxCuentas),idTitular(auxID), tipoTitular(auxTipo),fechaVinculacion(auxFecha){
}

std::string Titular::getTipoTitular(){
  return tipoTitular;
}

std::string Titular::getFechaVinculacion(){
return fechaVinculacion;
}

std::vector<Cliente*>& Titular::getClientes(){
 return clientes;
}

void Titular::addCliente(Cliente* cliente){
  clientes.push_back(cliente);
}

std::vector<Cuenta*>& Titular::getCuentas(){
 return cuentas;
}

void Titular::addCuenta(Cuenta* cuenta){
  cuentas.push_back(cuenta);
}


int Titular::getIdTitular(){
  return idTitular;
}
