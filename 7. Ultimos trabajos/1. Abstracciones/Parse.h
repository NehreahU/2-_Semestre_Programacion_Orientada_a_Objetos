#ifndef PARSE_H
#define PARSE_H
#include "Banco.h"
#include "Cliente.h"
#include "Cuenta.h"

class Parse{

Parse();
bool setNombreBanco(Banco& banco);
bool cargarClientes(std::vector<Cliente>& clientes);
bool cargarCuentas(std::vector<Cuenta>& cuentas);

void cargarTitulares(Banco& banco);

};

#endif
