#ifndef MODELO_H
#define MODELO_H
#include "Banco.h"
#include "Cliente.h"
#include "Cuenta.h"
#include <vector>


class Modelo {

private:
Banco banco;

public:
Modelo();
bool cargarBanco(); // cargarVectorCuentas(): void  //Carga un vector de cuentas de un json // cargarVectorClientes(): void //Carga un vector de clientes de un json
void crearBanco();
bool verificarTitular(int idTitular);
bool verificarCuenta(int idTitular, std::string idCuenta);
bool verificarCliente(int idTitular, std::string idCliente);
void crearTitular(int idTitular); //se crea un objeto titular con dos ojetos Cliente&  y Cuenta& allá en titular el recibe titular(cliente*, cuenta*)
void crearCuenta(int idTitular); //Se crea objeto cuenta y se envía al vector de cuentas.
void crearCliente(int idTitular); //Se crea un objeto cliente y se envía al vector cliente.
void consignarDinero(int dinero,int idProceso, std::string idCuenta);
void retirarDinero(int dinero,int idProceso, std::string idCuenta);
int consultarSaldo(int idProceso, std::string idCuenta);
void limpiar();
};

#endif
