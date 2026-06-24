#include "Titular.h"


Titular::Titular(Cliente* auxCliente,Cuenta* auxCuenta,int auxID,std::string auxTipo,std::string auxFecha): cliente(auxCliente),cuenta(auxCuenta),idTitular(auxID), tipoTitular(auxTipo),fechaVinculacion(auxFecha){

}

std::string Titular::getTipoTitular(){
  return tipoTitular;
}

std::string Titular::getFechaVinculacion(){
return fechaVinculacion;
}

Cliente* Titular::getCliente(){
 return cliente;
}

Cuenta* Titular::getCuenta(){
 return cuenta;
}

int Titular::getIdTitular(){
  return idTitular;
}
