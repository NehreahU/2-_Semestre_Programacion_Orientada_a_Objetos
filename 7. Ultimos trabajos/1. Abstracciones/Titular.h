#ifndef TITULAR_H
#define TITULAR_H
#include "Cuenta.h"
#include "Cliente.h"
#include <string>

class Titular{

private:
idTitular : int
std::string tipoTitular;
std::string fechaVinculacion;
Cliente*: cliente;
Cuenta* cuenta;

public:
Titular(Cliente* auxCliente,Cuenta* auxCuenta,std::string auxTipo,std::string auxFecha);
std::string getTipoTitular();
std::string getFechaVinculacion();
Cliente* getCliente();
Cuenta* getCuenta(); 

};

#endif
