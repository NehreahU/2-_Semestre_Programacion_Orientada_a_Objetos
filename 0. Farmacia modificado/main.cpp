#include "Inventario.h"
#include "MMedicamentos.h"
#include "Vista.h"
#include <string>
#include <iostream>



/*
Acá en el main únicamente hay lo necesario, todas las funciones y métodos, están contenidos en las clases el "system("clear");" limpia la consola
*/

int main() {
  system("clear");//"system("clear");" limpia la consola
  int eleccion=-1;//en -1 para liberar la opción 0 como salida del programa y los naturales como opciones.
  Inventario catalogo;//Inicio un objeto catalogo
  MMedicamentos control;//Inicio un objeto de conrtol
  Vista ver;//Inicio un objeto de visión
  control.cargarArchivo(catalogo);
  


  
  
  while(!(eleccion==0)){
    ver.mostrarTituloConNieve();
                              
                              
    std::cout<<R"(
                                        Seleccione la opción deseada:
                                        1. Agregar medicamento a inventario.
                                        2. Eliminar medicamento del inventario.
                                        3. Buscar medicamento del inventario.
                                        4. Mostrar todo el inventario.
                                        5. Cambiar cantidad de algún medicamento.
                                        0. Salir.)"<<std::endl;
    std::cin>>eleccion;
    if (eleccion == 0){
      std::cout<<"El programa se cerrará"<<std::endl;
      return 0;
    }
    else if (eleccion >0 && eleccion <= 5){
      
      switch(eleccion){//Para hacer funcionar el tablero de opciones. Cada case es una opción, encierra en llaves para mantener las variables contenidas {};
      
      
          case 1:{
            system("clear");
            ver.imprimirAgregar();//Muestra un titulo grande que dice "Agregar"
            std::cin.ignore();//Ignora una entrada de teclado
            control.agregarMedicamento(catalogo);//Agrega un medicamento al catalogo/inventario
            control.guardarArchivo(catalogo);//Agrega la nueva línea de medicamento al txt
            break;
          }



          case 2:{
            system("clear");
            ver.imprimirEliminar();//imprime titulo
            std::cin.ignore();
            int ID;
            std::cout<<"Ingrese el ID del medicamento que desea buscar y eliminar"<<std::endl;
            std::cin>>ID;
            std::cout<<"Se ha eliminado el medicamento: "<<std::endl;
            ver.imprimirMedicamento(catalogo, ID);//Imprime los datos de un medicamento del catalogo según una ID dada
            catalogo.eliminarMedicamento(ID);//Elimina un medicamento del catalogo según una ID dada
            control.actualizarArchivo(catalogo);//Actualiza todo el archivo dejandolo exactamente igual a los datos del objeto catalogo de la clase inventario.
            break;
          }



          case 3:{
            system("clear");
            ver.imprimirBuscar();   
            std::cin.ignore();
            int ID;
            std::cout<<"Ingrese el ID del medicamento que desea buscar"<<std::endl;
            std::cin>>ID;
            ver.imprimirMedicamento(catalogo,ID);
            break;
          }



          case 4:{
            system("clear");
            ver.imprimirInventario(); 
            ver.mostrarInventario(catalogo);//Imprime una matriz con los datos de todo el inventario
            break;
          }    



          case 5:{
            int ID;
            std::cout<<"Ingrese el ID del medicamento a cambiar cantidad"<<std::endl;
            std::cin>>ID;
            int cantidad;
            std::cout<<"Ingrese la nueva cantidad"<<std::endl;
            std::cin>>cantidad;     
            system("clear");
            ver.imprimirCantidad();     
            control.cambiarCantidad(catalogo,ID,cantidad);//Cambia la cantidad según un ID y una cantidad dada.
            control.actualizarArchivo(catalogo);
            break;
          }  
       
      }
   }
   else{
    std::cout<<"Opción no valida"<<std::endl;
   }
    std::cout<<"Presione Enter para continuar"<<std::endl;
    std::cin.ignore();
    std::cin.get();
    
    system("clear");
    
  }
  
  return 0;

}
