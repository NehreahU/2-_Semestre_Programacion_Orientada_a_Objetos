#ifndef BANCO_H
#define BANCO_H
#include <string>
#include <vector>
#include "Titular.h"
#include <stdexcept>

class Banco{

private:
std::string nombre;
std::vector<Titular> titulares;

public:
Banco(std::string auxNombre); 

std::string getNombre();
Titular& getTitular(int idTitular);
std::vector<Titular>& getTitulares();

bool verificarTitular(int idTitular);
bool verificarCuenta(int idTitular, std::string idCuenta);
bool verificarCliente(int idTitular,std::string idCliente);

void addTitular(Titular titular);
void setTitulares(std::vector<Titular> auxTitulares);
void setNombre(std::string auxNombre);

};

#endif
