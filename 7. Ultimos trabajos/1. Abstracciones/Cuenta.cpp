#include "Cuenta.h"
#include <string>

Cuenta::Cuenta(int auxIdTitular, std::string auxId, long auxSaldo):idTitular(auxIdTitular),id(auxId),saldo(auxSaldo){
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
