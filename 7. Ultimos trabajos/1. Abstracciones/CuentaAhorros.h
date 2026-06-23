#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H
#include "Cuenta.h"

class CuentaAhorros: public Cuenta{

private:
double tasaInteres;

public:
CuentaAhorros(std::string auxId, long auxSaldo, std::string auxTipo);
void setTasaInteres(double auxInteres);
void aplicarInteres();

};

#endif
