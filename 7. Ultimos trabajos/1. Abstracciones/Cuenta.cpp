#include "Cuenta.h"
#include <string>

Cuenta::Cuenta(int auxIdTitular,const std::string& auxId, long auxSaldo, const std::string& auxTipo):idTitular(auxIdTitular),id(auxId),saldo(auxSaldo), tipoCuenta(auxTipo){
}

int Cuenta::getIdTitular(){
  return idTitular;
}

std::string Cuenta::getNumeroCuenta(){
  return id;
}

long Cuenta::getSaldo(){
  return saldo;
}

std::string Cuenta::getTipoCuenta(){
  return tipoCuenta;
}

void Cuenta::setNumeroCuenta(std::string auxId){
  id = auxId;
}

void Cuenta::setSaldo(long auxSaldo){
  saldo = auxSaldo;
}

bool Cuenta::retirarDinero(long cantidad){
  if(cantidad<=saldo){
    saldo -= cantidad;
    return true;
  }
  else{
    return false;
  }
}

void Cuenta::consignarDinero(long cantidad){
  saldo += cantidad;
}

Cuenta::~Cuenta(){
}
