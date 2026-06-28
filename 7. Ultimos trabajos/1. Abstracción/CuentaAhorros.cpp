#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros(int auxIdTitular, const std::string& auxId, long auxSaldo, const std::string& auxTipo):Cuenta(auxIdTitular,auxId, auxSaldo, auxTipo){
  tasaInteres = 2.5;
}

void CuentaAhorros::setTasaInteres(double auxInteres){
 tasaInteres = auxInteres; 
}

double CuentaAhorros::getTasaInteres(){
  return tasaInteres;
}


void CuentaAhorros::aplicarInteres(){
  saldo += saldo*tasaInteres;
}

