#include "Parse.h"
#include <nlohmann/json.hpp>
#include <fstream>
using Json = nlohmann::json;


bool Parse::crearBanco(Banco& banco){
  
  std::string nombreBanco;
  
  //Abre el archivo
  std::ifstream archivo("Banco.json");
  
  //de no abrir, retorna false
  if(!archivo.is_open()){
    std::cerr<<"Error no se abrió el archivo"<<std::endl;
    return false;
  }
  
  //Crea un archivo tipo Json llamado banco y mete todo lo que tiene el archivo.json en el.
  Json bancojson = json::parse(archivo);
  //Ya tengo mi Json banco, entonces cierro el archivo
  archivo.close();
  
  //nombro al banco
  nombreBanco = bancojson["banco"]["nombre"];
  banco.setNombre(nombreBanco);
  return true;
}  
  
  


bool Parse::cargarClientes(std::vector<Cliente>& clientes){
  int idTitular;
  //atributos de cliente
  std::string identificacionCliente;
  std::string nombreCliente;
  std::string telefonoCliente;
  
  //Abre el archivo
  std::ifstream archivo("Banco.json");
  
  //de no abrir, retorna false
  if(!archivo.is_open()){
    std::cerr<<"Error el archivo no abrió"<<std::endl;
    return false;
  }
  
  //Crea un archivo tipo Json llamado banco y mete todo lo que tiene el archivo.json en el.
  Json bancojosn = json::parse(archivo);
  
  //Ya tengo mi Json banco, entonces cierro el archivo
  archivo.close();

  //un for simple, busca en cada titular, los atributos del cliente y los usa para crear un objeto cliente que se ingresa al vector clientes
  for (auto& titular: bancojson["banco"]["titular"]){
    identificacionCliente = titular["cliente"]["identificacion"];
    nombreCliente = titular["cliente"]["nombre"];
    telefonoCliente = titular["cliente"]["telefono"];
    Cliente cliente(identificacionCliente, nombreCliente, telefonoCliente);
    clientes.push_back(cliente);
  }
  return true;
}




bool Parse::cargarCuentas(std::vector(Cuenta)& cuentas){
  //atributos clientes
  int idTitular;
  std::string id;
  std::string saldo;
  long limiteSobregiro;
  double tasainteres;
  std::string tipoTitular;
  
  //abrir archivo
  std::ifstream archivo("Banco.json");
  
  //verificar que abrió 
  if (!archivo.is_open()){
    std::cerr<<"Error. El archivo no se abrió"<<std::endl;
    return false;
  }
  
  //creo mi objeto tipo json
  Json bancoJson = json::parse(archivo);
  
  for(autor& titular: bancoJson["banco"]["titular"]){
    tipoTitular = titular["tipoTitular"];
    
    //Verifica que tipo de titular es, para espeficar el tipo de cuenta
    if (tipoTitular == "CuentaCorriente"){
      idTitular = titular["idTitular"];
      id = titular["id"];
      saldo = titular["saldo"];
      limiteSobregiro = titular["limiteSobregiro"];
      //crea el objeto y lo ingresa
      CuentaCorriente cuenta(id, saldo, limiteSobregiro);
      cuentas.push_back(cuenta);
    }
    else if(tipoTitular == "CuentaAhorros"){
      idTitular = titular["idTitular"];
      id = titular["id"];
      saldo = titular["saldo"];
      tasaInteres = titular["tasaInteres"];
      //crea el objeto y lo ingresa
      CuentaAhorros cuenta(id, saldo, tasaInteres);
      cuentas.push_back(cuenta);      
    }
  }//end for
  return true;
}


bool cargarTitulares(Banco& banco, std::vector<Cliente>& clientes, std::vector<Cuenta>& cuentas){
  //Atributos titular
  int idTitular;
  std::string tipoTitular;
  std::string fechaVinculacion;
  std::vector<Titular> titulares;
  
  //abrir archivo
  std::fstream archivo("Banco.json");
  
  //Verificar que abrió
  if (!archivo.is_open()){
    std::cerr<<"Error al abrir el archivo"<<std::endl;
    return 1;
  }
  
  //Crear Json
  Json banco = json::parse(archivo);
  
  //cerrar archivo
  archivo.close();
  
  for (auto& titular: banco["banco"]["titular"])
    for(auto& cliente: clientes){
     if(titular["cliente"]["id"] == cliente.getIdentificacion()){
      for(auto& cuenta: cuentas){
        if (titular["cliente"]["cuenta"]){
          idTitular = titular["idTitular"];
          tipoTitular = titular["tipoTitular"];
          fechaVinculacion = titular["fechaVinculacion"]};
          Titular titular(cliente&, cuenta&, idTitular, tipoTitular, fechaVinculacion);
          titulares.push_back(titular);
        }
      }
     }
    }
   }
  banco.setTitulares(titulares);
  return true;
}
