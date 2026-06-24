#ifndef PARSE_H
#define PARSE_H
#include "Banco.h"
#include "Cliente.h"
#include "Cuenta.h"

class Parse{


public:
Parse();
bool setNombreBanco(Banco& banco);
void cargarClientes(std::vector<Cliente>& clientes);
void cargarCuentas(std::vector<Cuenta>& cuentas);

void cargarTitulares(Banco& banco);

};

#endif
