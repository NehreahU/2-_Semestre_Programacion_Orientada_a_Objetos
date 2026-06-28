#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H
#include "Cuenta.h"

class CuentaAhorros: public Cuenta{

private:
double tasaInteres;

public:
CuentaAhorros(int auxIdTitular, const std::string& auxId, long auxSaldo, const std::string& auxTipo);
void setTasaInteres(double auxInteres);
double getTasaInteres();
void aplicarInteres();

};

#endif
