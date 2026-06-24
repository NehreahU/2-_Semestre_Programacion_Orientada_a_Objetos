#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

class Cliente{
private:
int idTitular;
std::string identificacion, nombre, telefono;

public:
Cliente(int auxIdTitular, std::string auxIdentificacion, std::string auxNombre, std::string auxTelefono);
int getIdTitular();
std::string getIdentificacion();
std::string getNombre();
std::string getTelefono();
void setIdentificacion(std::string codigo);
void setNombre(std::string auxNombre);
void setTelefono(std::string auxTelefono);
~Cliente();
};

#endif
