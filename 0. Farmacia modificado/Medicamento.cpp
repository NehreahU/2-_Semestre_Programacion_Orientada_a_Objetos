#include "Medicamento.h"
#include <iostream>
#include <string>


Medicamento::Medicamento (const std::string &auxNombre,const std::string &auxPresentacion, int auxCantidad, double auxCostoCompra, double auxPrecioVenta, int auxID): nombre(auxNombre), presentacion(auxPresentacion), cantidad(auxCantidad), costoCompra(auxCostoCompra), precioVenta(auxPrecioVenta), ID(auxID) {
}
int Medicamento::getIDMedicamento() const{
  return ID;
}
std::string Medicamento::getNombreMedicamento() const{
  return nombre;
}
std::string Medicamento::getPresentacionMedicamento() const{
  return presentacion;
}
int Medicamento::getCantidadMedicamento() const{
  return cantidad;
}
double Medicamento::getCostoCompraMedicamento() const{
  return costoCompra;
}
double Medicamento::getPrecioVentaMedicamento() const{
  return precioVenta;
}
  
void Medicamento::setCantidad(int auxCantidad){
  cantidad = auxCantidad;
}


