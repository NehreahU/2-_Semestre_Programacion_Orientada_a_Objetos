#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "View.h"
#include "Modelo.h"



class Controller{

private:

View& vista;
Modelo& modelo;

public:

Controller(View& auxVista, Modelo& auxModelo);

void iniciarSistema();

void añadirUsuario();

void añadirCuenta();

void añadirCliente();

void transferencia();

void limpiar();


};

#endif
