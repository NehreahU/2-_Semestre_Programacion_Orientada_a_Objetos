#ifndef TITULAR_H
#define TITULAR_H
#include "Cuenta.h"
#include "Cliente.h"
#include <string>
#include <vector>

class Titular{

private:
int idTitular;
std::string tipoTitular;
std::string fechaVinculacion;
std::vector<Cliente*> clientes;
std::vector<Cuenta*> cuentas;

public:
Titular(int auxID, std::string auxTipo,std::string auxFecha);
Titular(std::vector<Cliente*> auxClientes,std::vector<Cuenta*> auxCuentas,int auxID, std::string auxTipo,std::string auxFecha);
std::string getTipoTitular();
std::string getFechaVinculacion();
std::vector<Cliente*>& getClientes();
void addCliente(Cliente* cliente);
std::vector<Cuenta*>& getCuentas(); 
void addCuenta(Cuenta* cuenta);
int getIdTitular();
};

#endif
