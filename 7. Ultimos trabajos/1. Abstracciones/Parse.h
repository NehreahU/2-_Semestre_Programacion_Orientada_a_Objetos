#ifndef PARSE_H
#define PARSE_H
#include "Banco.h"
#include "Cliente.h"
#include "Cuenta.h"

class Parse{


public:
Parse();
bool cargarBanco(Banco& banco);
void cargarClientes(std::vector<Cliente>& clientes);
void cargarCuentas(std::vector<Cuenta>& cuentas);

void cargarTitulares(Banco& banco, std::vector<Cliente>& clientes, std::vector<Cuenta>& cuentas);

void guardar(Banco& banco, std::vector<Cliente>& clientes, std::vector<Cuenta>& cuentas);

};

#endif
