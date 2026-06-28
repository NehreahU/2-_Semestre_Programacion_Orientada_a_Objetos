#include "Parse.h"
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"
#include "Titular.h"


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
  


void Parse::cargarTitulares(Banco& banco){

  std::vector<Titular>& titulares = banco.getTitulares();
  titulares.clear();

  //Atributos titular
  int idTitular;
  std::string tipoTitular;
  std::string fechaVinculacion;
  //abrir archivo
  std::ifstream archivo("Data/Banco.json");
  
  //Verificar que abrió
  if (!archivo.is_open()){
    std::cerr<<"Error al abrir el archivo"<<std::endl;
  }
  
  //Crear Json
  Json bancoJson;
  archivo>>bancoJson;
  
  //cerrar archivo
  archivo.close();
  
  for (auto& titular: bancoJson["banco"]["titular"]){
    idTitular = titular["idTitular"];
    tipoTitular = titular["tipoTitular"];
    fechaVinculacion = titular["fechaVinculacion"];
    
    
        Titular t(idTitular, tipoTitular, fechaVinculacion);
        titulares.push_back(t);
  }
}



void Parse::cargarClientes(Banco& banco){
  int idTitular;
  std::string identificacionCliente;
  std::string nombreCliente;
  std::string telefonoCliente;
  
  //Vector de titulares del banco
  std::vector<Titular>& titulares = banco.getTitulares();
  
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
  for(auto& tit: titulares){  
        //un for simple, busca en cada titular, los atributos del cliente y los usa para crear un objeto cliente que se ingresa al vector clientes
        for (auto& titular: bancojson["banco"]["titular"]){
         if (titular.contains("cliente") && titular["cliente"].is_array()) {//if control de seguridad
          for(auto& cliente: titular["cliente"]){
            if(tit.getIdTitular() == cliente["idTitular"]){
              idTitular = cliente["idTitular"];
              identificacionCliente = cliente["identificacion"];
              nombreCliente = cliente["nombre"];
              telefonoCliente = cliente["telefono"];
              Cliente* clientePtr = new Cliente(idTitular, identificacionCliente, nombreCliente, telefonoCliente);
              tit.addCliente(clientePtr);
            }//end if
          }//end for titular
         }//end if de control de seguridad 
        }//end for bancoJson
  }
}






void Parse::cargarCuentas(Banco& banco){
  //atributos cuentas
  int idTitular;
  std::string id;
  long saldo;
  long limiteSobregiro;
  double tasaInteres;
  std::string tipoCuenta;

//Vector de titulares del banco
  std::vector<Titular>& titulares = banco.getTitulares();

  
  //Vector de punteros de cuentas del titular  
  //abrir archivo
  std::ifstream archivo("Data/Banco.json");
  
  //verificar que abrió 
  if (!archivo.is_open()){
    std::cerr<<"Error. El archivo no se abrió"<<std::endl;
  }
  
  //creo mi objeto tipo json
  Json bancoJson = Json::parse(archivo);
  
        for(auto& tit: titulares){
                for(auto& titular: bancoJson["banco"]["titular"]){
                        if (titular.contains("cuenta") && titular["cuenta"].is_array()) {//if control de seguridad
                              for(auto& cuenta: titular["cuenta"]){
                                    if(tit.getIdTitular() == cuenta["idTitular"]){
                                      tipoCuenta = cuenta["tipoCuenta"];
                                      //Verifica que tipo de titular es, para espeficar el tipo de cuenta
                                          if (tipoCuenta == "CuentaCorriente"){
                                            idTitular = cuenta["idTitular"];
                                            id = cuenta["id"];
                                            saldo = cuenta["saldo"];
                                            limiteSobregiro = cuenta["limiteSobregiro"];
                                            //crea el objeto y lo ingresa
                                            CuentaCorriente* cuentaPtr = new CuentaCorriente(idTitular, id, saldo, tipoCuenta);
                                            cuentaPtr->setLimiteSobregiro(limiteSobregiro);
                                            tit.addCuenta(cuentaPtr);
                                          }
                                          else if(tipoCuenta == "CuentaAhorros"){
                                            idTitular = cuenta["idTitular"];
                                            id = cuenta["id"];
                                            saldo = cuenta["saldo"];
                                            tasaInteres = cuenta["tasaInteres"];
                                            //crea el objeto y lo ingresa
                                            CuentaAhorros* cuentaPtr = new CuentaAhorros(idTitular, id, saldo, tipoCuenta);
                                            cuentaPtr->setTasaInteres(tasaInteres);
                                            tit.addCuenta(cuentaPtr);      
                                          }
                                    }
                              }
                        }//end if
                 }//end for bancoJson
        }
}






void Parse::guardar(Banco& banco){


  std::vector<Titular>& titulares = banco.getTitulares();
  
  Json bancoJson;
  
  bancoJson["banco"]["nombre"] = banco.getNombre();   
  if(!(titulares.empty())){
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
            
            if(!(clientes.empty())){
                  auxJson["cliente"] = Json::array();
                  for(auto& cliente: clientes){
                    Json cJson;
                    cJson["idTitular"] = cliente->getIdTitular();
                    cJson["identificacion"] = cliente->getIdentificacion();
                    cJson["nombre"] = cliente->getNombre();
                    cJson["telefono"] = cliente->getTelefono();
                    auxJson["cliente"].push_back(cJson);
                  }
            }
        
            //Cuentas
                  if(!(cuentas.empty())){
                    auxJson["cuenta"] = Json::array();
                          for(auto& cuenta: cuentas){
                            Json cJson;
                              if(cuenta->getTipoCuenta() ==  "CuentaAhorros"){
                                cJson["idTitular"] = cuenta->getIdTitular();
                                cJson["id"] = cuenta->getNumeroCuenta();
                                cJson["saldo"] = cuenta->getSaldo();
                                cJson["tipoCuenta"] = cuenta->getTipoCuenta();
                                CuentaAhorros* cuentaA = dynamic_cast<CuentaAhorros*>(cuenta);
                                cJson["tasaInteres"] = cuentaA->getTasaInteres();
                                cJson["limiteSobregiro"] = 0;
                                auxJson["cuenta"].push_back(cJson);
                              }
                              else if(cuenta->getTipoCuenta() == "CuentaCorriente"){
                                cJson["idTitular"] = cuenta->getIdTitular();
                                cJson["id"] = cuenta->getNumeroCuenta();
                                cJson["saldo"] = cuenta->getSaldo();
                                cJson["tipoCuenta"] = cuenta->getTipoCuenta();
                                cJson["tasaInteres"] = 0;
                                CuentaCorriente* cuentaC = dynamic_cast<CuentaCorriente*>(cuenta);
                                cJson["limiteSobregiro"] = cuentaC->getLimiteSobregiro();
                                auxJson["cuenta"].push_back(cJson);
                              }
                          }
                  }
                  bancoJson["banco"]["titular"].push_back(auxJson);
      }
  }
  std::ofstream archivo("Data/Banco.json");
  archivo<<bancoJson.dump(4);
  archivo.close();
}
