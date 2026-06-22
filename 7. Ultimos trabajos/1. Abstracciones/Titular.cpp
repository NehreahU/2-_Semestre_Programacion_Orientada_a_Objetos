#include "Titular.h"


Titular(Cliente* auxCliente,Cuenta* auxCuenta,std::string auxTipo,std::string auxFecha):
                                                                                            cliente(auxCliente),
                                                                                            cuenta(auxCuenta),
                                                                                            tipoTitular(auxTipo),
                                                                                            fechaVinculacion(auxFecha){

}

std::string Titular::getTipoTitular(){
  return tipoTitular;
}

std::string Titular::getFechaVinculacion(){
return fechaVinculacion;
}

Cliente* Titular::getCliente(){
 return cliente;
}

Cuenta* Titular::getCuenta(){
 return cuentaM
}
