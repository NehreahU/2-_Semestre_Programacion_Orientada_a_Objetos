#include "CuentaAhorros.h"

CuentaAhorros(std::string auxId, long auxSaldo, std::string auxTipo):cuenta(auxId, auxSaldo, auxTipo){
  tasaInteres = 2.5;
}

void setTasaInteres(double auxInteres){
 tasaInteres = auxInteres; 
}


void aplicarInteres(){
  saldo += saldo*tasaInteres;
}

