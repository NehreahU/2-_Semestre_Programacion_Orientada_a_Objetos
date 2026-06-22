#include "CuentaAhorros.h"

CuentaAhorros(std::string auxId, long auxSaldo, double auxInteres ):cuenta(auxId, auxSaldo), tasaInteres(auxInteres){
}
void aplicarInteres(){
  saldo += saldo*tasaInteres;
}

