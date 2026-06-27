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
  throw std::runtime_error("Error: "+std::string(__FILE__)+" "+std::to_string(__LINE__));
}

std::vector<Titular>& Banco::getTitulares(){
    return titulares;
}


bool Banco::verificarTitular(int idTitular){
  for (auto& titular: titulares){
    if(titular.getIdTitular()== idTitular){
      return true;
    }
  }
  return false;
}



bool Banco::verificarCuenta(int idTitular, std::string idCuenta){
  for (auto& titular: titulares){
    if(titular.getIdTitular()== idTitular){
      std::vector<Cuenta*>& cuentas = titular.getCuentas();
      for(auto& cuenta: cuentas){
        if(cuenta->getNumeroCuenta() == idCuenta){
          return true;
        }
      }
    }
  }
  return false;
}



bool Banco::verificarCliente(int idTitular, std::string idCliente){
  for (auto& titular: titulares){
    if(titular.getIdTitular()== idTitular){
      std::vector<Cliente*>& clientes = titular.getClientes();
      for(auto& cliente: clientes){
        if(cliente->getIdentificacion() == idCliente){
          return true;
        }
      }
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
