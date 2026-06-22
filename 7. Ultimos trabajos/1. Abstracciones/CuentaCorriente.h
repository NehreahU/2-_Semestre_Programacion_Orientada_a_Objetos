#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "Cuenta.h"

class CuentaCorriente: public Cuenta{

private: 
long limiteSobregiro;

public:
CuentaCorriente(std::string auxID, long auxSaldo, long auxSobregiro);
void setLimiteSobregiro(long limite);
long getLimiteSobregiro();
bool retirarDinero(long cantidad) override;


};

#endif
