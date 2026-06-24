#include "Parse.h"
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
using Json = nlohmann::json;

Parse::Parse(){
}

bool Parse::cargarBanco(Banco& banco){
  
  std::string nombreBanco;
  
  //Abre el archivo
  std::ifstream archivo("Data/Banco.json");
  
  //de no abrir, retorna false
  if(!archivo.is_open()){
    std::cerr<<"Error no se abrió el archivo"<<std::endl;
    return false;
  }
  
  //Crea un archivo tipo Json llamado banco y mete todo lo que tiene el archivo.json en el.
  Json bancojson = Json::parse(archivo);
  //Ya tengo mi Json banco, entonces cierro el archivo
  archivo.close();
  
  //nombro al banco
  nombreBanco = bancojson["banco"]["nombre"];
  banco.setNombre(nombreBanco);
  return true;
}  
  
  


void Parse::cargarClientes(std::vector<Cliente>& clientes){
  int idTitular;
  //atributos de cliente
  std::string identificacionCliente;
  std::string nombreCliente;
  std::string telefonoCliente;
  
  //Abre el archivo
  std::ifstream archivo("Data/Banco.json");
  
  //de no abrir, retorna false
  if(!archivo.is_open()){
    std::cerr<<"Error el archivo no abrió"<<std::endl;
  }
  
  //Crea un archivo tipo Json llamado banco y mete todo lo que tiene el archivo.json en el.
  Json bancojson = Json::parse(archivo);
  
  //Ya tengo mi Json banco, entonces cierro el archivo
  archivo.close();

  //un for simple, busca en cada titular, los atributos del cliente y los usa para crear un objeto cliente que se ingresa al vector clientes
  for (auto& titular: bancojson["banco"]["titular"]){
    idTitular = titular["cliente"]["idTitular"];
    identificacionCliente = titular["cliente"]["identificacion"];
    nombreCliente = titular["cliente"]["nombre"];
    telefonoCliente = titular["cliente"]["telefono"];
    Cliente cliente(idTitular, identificacionCliente, nombreCliente, telefonoCliente);
    clientes.push_back(cliente);
  }
}




void Parse::cargarCuentas(std::vector<Cuenta>& cuentas){
  //atributos clientes
  int idTitular;
  std::string id;
  long saldo;
  long limiteSobregiro;
  double tasaInteres;
  std::string tipoCuenta;
  
  //abrir archivo
  std::ifstream archivo("Data/Banco.json");
  
  //verificar que abrió 
  if (!archivo.is_open()){
    std::cerr<<"Error. El archivo no se abrió"<<std::endl;
  }
  
  //creo mi objeto tipo json
  Json bancoJson = Json::parse(archivo);
  
  for(auto& titular: bancoJson["banco"]["titular"]){
    
    tipoCuenta = titular["cliente"]["tipoCuenta"];
    //Verifica que tipo de titular es, para espeficar el tipo de cuenta
    if (tipoCuenta == "CuentaCorriente"){
      idTitular = titular["cuenta"]["idTitular"];
      id = titular["cuenta"]["id"];
      saldo = titular["cuenta"]["saldo"];
      limiteSobregiro = titular["cuenta"]["limiteSobregiro"];
      //crea el objeto y lo ingresa
      CuentaCorriente cuenta(idTitular, id, saldo, tipoCuenta);
      cuenta.setLimiteSobregiro(limiteSobregiro);
      cuentas.push_back(cuenta);
    }
    else if(tipoCuenta == "CuentaAhorros"){
      idTitular = titular["idTitular"];
      id = titular["id"];
      saldo = titular["saldo"];
      tasaInteres = titular["tasaInteres"];
      //crea el objeto y lo ingresa
      CuentaAhorros cuenta(idTitular, id, saldo, tipoCuenta);
      cuenta.setTasaInteres(tasaInteres);
      cuentas.push_back(cuenta);      
    }
  }//end for
}


void Parse::cargarTitulares(Banco& banco, std::vector<Cliente>& clientes, std::vector<Cuenta>& cuentas){
  //Atributos titular
  int idTitular;
  std::string tipoTitular;
  std::string fechaVinculacion;
  std::vector<Titular> titulares;
  
  //abrir archivo
  std::ifstream archivo("Data/Banco.json");
  
  //Verificar que abrió
  if (!archivo.is_open()){
    std::cerr<<"Error al abrir el archivo"<<std::endl;
  }
  
  //Crear Json
  Json bancoJson;
  archivo>>bancoJson
  
  //cerrar archivo
  archivo.close();
  
  for (auto& titular: bancoJson["banco"]["titular"]){
    for(auto& cliente: clientes){
     if(titular["idTitular"] == cliente.getIdTitular()){
      for(auto& cuenta: cuentas){
        if (titular["idTitular"] == cuenta.getIdTitular()){
          idTitular = titular["idTitular"];
          tipoTitular = titular["tipoTitular"];
          fechaVinculacion = titular["fechaVinculacion"];
          Titular titular(&cliente, &cuenta, idTitular, tipoTitular, fechaVinculacion);
          titulares.push_back(titular);
        }
      }
     }
    }
   }
  banco.setTitulares(titulares);
}


void Parse::guardar(Banco& banco, std::vector<Cliente>& clientes, std::vector<Cuenta>& cuentas){
  Json bancoJson;
  
  for(auto& cliente: clientes){
      for(auto& cuenta: cuentas){
        if(cliente.getIdTitular == cuenta.getIdTitular){
          Titular titular = banco.getTitular(cliente.getIdTitular);
          banco["banco"]["nombre"] = banco.getNombre();
          
          banco["banco"]["titular"] =
        }
      }
  }
}
