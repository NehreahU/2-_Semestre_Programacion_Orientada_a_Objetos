#ifndef CUENTA_H
#define CUENTA_H
#include <string>

class Cuenta {

private:
int idTitular;
std::string id;
long saldo;
std::string tipoCuenta;

public:
Cuenta(int idTitular, std::string auxId, long auxSaldo, std::string auxTipo);
int getIdTitular();
std::string getNumeroCuenta();
long getSaldo();
void setNumeroCuenta(std::string auxId);
void setSaldo(long auxSaldo);
virtual bool retirarDinero(long cantidad);
void consignarDinero(long cantidad);
~Cuenta();

};

#endif
