#ifndef BANCO_H
#define BANCO_H
#include <string>
#include <vector>
#include "Titular.h"

class{

private:
std::string nombre;
std::vector<Titular> titulares;

public:
Banco(std::string auxNombre);
std::string getNombre();
void addTitular(Titular titular);
void setTitulares(std::vector<Titular> auxTitulares);
void imprimirDatos();
void calcularPromedio();
void setNombre(std::string auxNombre);

};

#endif
