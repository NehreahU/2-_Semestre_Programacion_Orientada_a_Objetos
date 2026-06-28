#include "Cliente.h"

Cliente::Cliente(int auxIdTitular, std::string auxIdentificacion,std::string auxNombre,std::string auxTelefono): idTitular(auxIdTitular), identificacion(auxIdentificacion), nombre(auxNombre), telefono(auxTelefono){
}

int Cliente::getIdTitular(){
  return idTitular;
}

std::string Cliente::getIdentificacion(){
 return identificacion;
}

std::string Cliente::getNombre(){
 return nombre;
}

std::string Cliente::getTelefono(){
 return telefono;
}

void Cliente::setIdentificacion(std::string codigo){
  identificacion = codigo;
}

void Cliente::setNombre(std::string auxNombre){
 nombre = auxNombre;
}

void Cliente::setTelefono(std::string auxTelefono){
 telefono = auxTelefono;
}

Cliente::~Cliente(){
}
