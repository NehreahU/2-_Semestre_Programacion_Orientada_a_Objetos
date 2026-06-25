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
      idTitular = titular["cuenta"]["idTitular"];
      id = titular["cuenta"]["id"];
      saldo = titular["cuenta"]["saldo"];
      tasaInteres = titular["cuenta"]["tasaInteres"];
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
    idTitular = titular["idTitular"];
    tipoTitular = titular["tipoTitular"];
    fechaVinculacion = titular["fechaVinculacion"];
    
    std::vector<Cliente*> auxClientes;
    std::vector<Cuenta*> auxCuentas;
        for(auto& cliente: clientes){
          if (titular["idTitular"] == cliente.getIdTitular()){
            auxClientes.push_back(&cliente);
          }
        }
        for(auto& cuenta: cuentas){
          if (titular["idTitular"] == cliente.getIdTitular()){
            auxCuentas.push_back(&cuenta);
          }
        }
        Titular titular(auxClientes, auxCuentas, idTitular, tipoTitular, fechaVinculacion);
        titulares.push_back(titular);
  }
  banco.setTitulares(titulares);
}


void Parse::guardar(Banco& banco){
  std::vector<Titular>& titulares = banco.getTitulares();
  
  Json bancoJson;


  
  bancoJson["banco"]["nombre"] = banco.getNombre();   
  bancoJson["banco"]["titular"] = Json::array();


  
  
  for(auto& titular: titulares){
      Json auxJson;
      auxJson["idTitular"] = titular.getIdTitular();
      auxJson["tipoTitular"] = titular.getTipoTitular();
      auxJson["fechaVinculacion"] = titular.getFechaVinculacion();
      //Clientes
      std::vector<Cliente*>& clientes = titular.getClientes();
      std::vector<Cuenta*>& cuentas = titular.getCuentas();
      
      //Clientes
      auxJson["cliente"] = Json::array();
      for(auto& cliente: clientes){
        Json cJson;
        if(cliente.getIdTitular == titular.getIdTitular){
          cJson["idTitular"] = cliente.getIdTitular();
          cJson["identificacion"] = cliente.getIdentificacion();
          cJson["nombre"] = cliente.getNombre();
          cJson["telefono"] = cliente.getTelefono();
          auxJson["cliente"].push_back(cJson);
        }
      }
      auxJson["cuenta"] = Json::array();
      for(auto& cuenta: cuentas){
        Json cJson;
        if(cuenta.getIdTitular == titular.getIdTitular){
          if(cuenta.getTipoCuenta == "CuentaAhorros"){
            cJson["idTitular"] = cuenta.getIdTitular();
            cJson["id"] = cuenta.getIdTitular();
            cJson["saldo"] = cuenta.getSaldo();
            cJson["tipoCuenta"] = cuenta.getTipoCuenta();
            cJson["tasaInteres"] = cuentaAhorros.getTasaInteres();
            cJson["limiteSobregiro"] = 0;
            auxJson["cuenta"].push_back(cJson);
          }
          else if(cuenta.getTipoCuenta == "CuentaCorriente"){
            cJson["idTitular"] = cuenta.getIdTitular();
            cJson["id"] = cuenta.getIdTitular();
            cJson["saldo"] = cuenta.getSaldo();
            cJson["tipoCuenta"] = cuenta.getTipoCuenta();
            cJson["tasaInteres"] = 0;
            cJson["limiteSobregiro"] = cuentaCorriente.getLimiteSobregiro();
            auxJson["cuenta"].push_back(cJson);
          }
        }
      bancoJson["banco"]["titular"].push_back(auxJson);
  }
  std::ofstream archivo("Data/Banco.json");
  archivo<<bancoJson.dump(4);
  archivo.close();
}
