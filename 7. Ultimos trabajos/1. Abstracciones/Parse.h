#ifndef PARSE_H
#define PARSE_H
#include "Banco.h"
#include "Cliente.h"
#include "Cuenta.h"

class Parse{


public:
Parse();
bool cargarBanco(Banco& banco);
void cargarClientes(Banco& banco);
void cargarCuentas(Banco& banco);

void cargarTitulares(Banco& banco);

void guardar(Banco& banco);

};

#endif
