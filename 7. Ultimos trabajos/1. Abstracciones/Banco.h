#ifndef BANCO_H
#define BANCO_H
#include <string>
#include <vector>
#include "Titular.h"

class Banco{

private:
std::string nombre;
std::vector<Titular> titulares;

public:
Banco(std::string auxNombre);

std::string getNombre();

bool verificarTitular(int idTitular);

void addTitular(Titular titular);
void setTitulares(std::vector<Titular> auxTitulares);
void setNombre(std::string auxNombre);

};

#endif
