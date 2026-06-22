#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H


//Librerías
#include <string>

class Medicamento {

private:
  std::string nombre, presentacion;
  int cantidad, ID;
  double costoCompra, precioVenta;

public:
  Medicamento (const std::string &auxNombre = "",const std::string &auxPresentacion = "", int auxCantidad = 0, double auxCostoCompra = 0, double auxPrecioVenta= 0, int auxID= 0);
//getters
  std::string getNombreMedicamento() const;
  std::string getPresentacionMedicamento() const;
  int getCantidadMedicamento() const;
  double getCostoCompraMedicamento() const;
  double getPrecioVentaMedicamento() const;
  int getIDMedicamento() const;
  void setCantidad(int auxCantidad);
};
#endif
