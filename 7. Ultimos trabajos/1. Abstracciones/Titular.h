#ifndef TITULAR_H
#define TITULAR_H
#include "Cuenta.h"
#include "Cliente.h"
#include <string>

class Titular{

private:
int idTitular;
std::string tipoTitular;
std::string fechaVinculacion;
Cliente* cliente;
Cuenta* cuenta;

public:
Titular(Cliente* auxCliente,Cuenta* auxCuenta,int auxID, std::string auxTipo,std::string auxFecha);
std::string getTipoTitular();
std::string getFechaVinculacion();
Cliente* getCliente();
Cuenta* getCuenta(); 
int getIdTitular();
};

#endif
