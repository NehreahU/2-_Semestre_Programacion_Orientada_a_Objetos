#include "Banco.h"


Banco::Banco(std::string auxNombre): nombre(auxNombre){
}

std::string Banco::getNombre(){
  return nombre;
}

Titular& Banco::getTitular(int idTitular){
  for (auto& titular: titulares){
    if(titular.getIdTitular()== idTitular){
      return titular; 
    }
  }
}

bool Banco::verificarTitular(int idTitular){
  for (auto& titular: titulares){
    if(titular.getIdTitular()== idTitular){
      return true;
    }
  }
  return false;
}

void Banco::addTitular(Titular titular){
  titulares.push_back(titular);
}

void Banco::setTitulares(std::vector<Titular> auxTitulares){
  titulares = auxTitulares;
}





void Banco::setNombre(std::string auxNombre){
  nombre = auxNombre;
}
