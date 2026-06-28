#include"CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(int auxIdTitular, const std::string& auxId, long auxSaldo, const std::string& auxTipo):Cuenta(auxIdTitular,auxId,auxSaldo, auxTipo){
  limiteSobregiro = 120000;
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
