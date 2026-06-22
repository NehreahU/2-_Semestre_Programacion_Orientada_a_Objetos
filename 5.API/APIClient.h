/*

    Proyecto: IMC - Refactoring
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    La clase APIClient se encarga de realizar solicitudes HTTP a una API externa
    para obtener información sobre el Índice de Masa Corporal (IMC). Utiliza la
    biblioteca cURL para manejar las interacciones de red y la biblioteca 
    nlohmann::json para procesar la respuesta en formato JSON.

    Responsabilidades:
    - Realizar solicitudes HTTP a la API de cálculo del IMC.
    - Configurar las opciones de solicitud, incluyendo la URL y los encabezados necesarios.
    - Manejar la captura y procesamiento de la respuesta de la API.
    - Manejar errores y excepciones que puedan ocurrir durante las solicitudes.

    Colaboradores:
    - cURL: Utilizado para la comunicación HTTP.
    - nlohmann::json: Utilizado para manipular y analizar datos JSON.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#ifndef APICLIENT_H
#define APICLIENT_H

#include <string>

class APIClient {
public:
    std::string realizarSolicitud(const std::string &url, const std::string &hd1, const std::string &hd2) const;
};

#endif // APICLIENT_H
