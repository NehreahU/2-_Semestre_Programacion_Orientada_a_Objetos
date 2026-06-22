/*
    Proyecto: Report-BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando 
    funcionalidades para registrar, buscar y analizar la información de los donantes.

    Este proyecto genera reportes de una base de datos de donantes de sangre, proporcionando 
    informacion sobre las ubicaciones de los dontantes, el tipo de sangre y la edad.

    El código se basó en el proyecto BloodDatabase, fue traducido al español 
    y adaptado a las necesidades del curso.



    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
    
    Contribuidores:
    Estudiante Carlos Anibal Ceron del Castillo
    Código: 202537097
    Email: carlos.ilich.ceron@correounivalle.edu.co

    Estudiante: Anyela Lineth Cabrera Ordoñez 
    Código: 202540031 
    Email: anyela.cabrera@correounivalle.edu.co
  
    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Mayo 2026
*/
#include "Reports.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

Reports::Reports() { auxDonor.clear(); }
void Reports::loadDataBase(const std::vector<Donor> &auxdonor) {
  this->auxDonor = auxdonor;
}
int Reports::donorTotal() const { return auxDonor.size(); }

int Reports::donorTotal(const int &district, const int &age, const int &bloodType) const {
  int total = 0;
  for (const auto &d : auxDonor) {

    if (d.district == district && d.age >= age && d.bloodType == bloodType)
      total++;
  }
  return total;
}

int Reports::donorTotal(const int &district, const int &bloodType) const {
  int total = 0;
  for (const auto &d : auxDonor) {

    if (d.district == district && d.bloodType == bloodType)
      total++;
  }
  return total;
}
double Reports::donorMeanAge(const int &district) const {
  int total = 0, ages = 0;

  for (const auto &d : auxDonor) {
    if (d.district == district){
      ages += d.age;
      total++;
  }
}
return (ages / total);
}

double Reports::donorMeanAge(const int& d1,const int& d2, const int& d3) const {
  int total = 0, ages = 0;

  for (const auto &d : auxDonor) {
    if (d.district == d1 ||d.district == d2 ||d.district == d3  ){
      ages += d.age;
      total++;
  }
}
return (ages / total);
}

void Reports::generarReporteAnual() const {

cout<< R"(
 __________________________________________________________________
|..................................................................| 
|..................................................................| 
|......%%%%%...%%%%%%..%%%%%....%%%%...%%%%%...%%%%%%..%%%%%%......| 
|......%%..%%..%%......%%..%%..%%..%%..%%..%%....%%....%%..........|
|......%%%%%...%%%%....%%%%%...%%..%%..%%%%%.....%%....%%%%........| 
|......%%..%%..%%......%%......%%..%%..%%..%%....%%....%%..........| 
|......%%..%%..%%%%%%..%%.......%%%%...%%..%%....%%....%%%%%%......| 
|..................................................................| 
|.......%%%%...%%..%%..%%..%%...%%%%...%%..........................| 
|......%%..%%..%%%.%%..%%..%%..%%..%%..%%..........................| 
|......%%%%%%..%%.%%%..%%..%%..%%%%%%..%%..........................| 
|......%%..%%..%%..%%..%%..%%..%%..%%..%%..........................| 
|......%%..%%..%%..%%...%%%%...%%..%%..%%%%%%......................| 
|..................................................................| 
|__________________________________________________________________|)"<<endl<<endl;

    double matriz[8][10] = {0};
    double vector[8]= {0};
    string tipoSangre[] = {"A+","A-","B+","B-","AB+","AB-","O+","O-"};
    int total = auxDonor.size();
    
    for (const auto &d : auxDonor){
        if (d.bloodType >=1 && d.bloodType <= 8 && d.district >= 1 && d.district <=10){
            matriz[d.bloodType-1][d.district-1]++;
            vector[d.bloodType-1]++;
        }
    }
    cout<<"TS/DP\t";
    for (int j = 0; j <=9;j++){
        cout<<"D("<<j+1<<")\t";
    }
    cout<<"Total\t";
    cout<<"(%) TP\t"<<endl;

    for (int i = 0; i < 8;i++){
        cout<<tipoSangre[i]<<"\t";
        for (int j =0; j < 10;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<vector[i]<<"\t";
        cout<<(vector[i]/total)*100<<"%"<<endl;           
    }
}

