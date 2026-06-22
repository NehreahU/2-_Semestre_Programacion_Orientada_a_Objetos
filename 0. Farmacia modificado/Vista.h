#ifndef VISTA_H
#define VISTA_H
#include "MMedicamentos.h"

class Vista {

public:

Vista();
void mostrarTituloConNieve();
void imprimirAgregar();
void imprimirEliminar();
void imprimirBuscar();
void imprimirInventario();
void imprimirCantidad();
void mostrarInventario(const Inventario& auxCatalogo) const;
void imprimirMedicamento(const Inventario& auxCatalogo, int ID);


};


#endif
