#include"CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(std::string auxID, long auxSaldo, long auxSobregiro):Cuenta(auxId,auxSaldo), limiteSobregiro(auxSobregiro){
}


void CuentaCorriente::setLimiteSobregiro(long limite){
  limiteSobregiro = limite;
}

long CuentaCorriente::getLimiteSobregiro(){
  return limiteSobregiro;
}

bool CuentaCorriente::retirarDinero(long cantidad){
  if(cantidad <= saldo+limiteSobregiro){
    cantidad -=cantidad;
    return true;
  }
  else{
  return false;
  }
}
