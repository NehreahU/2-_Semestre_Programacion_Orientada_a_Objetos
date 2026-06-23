/*
    Proyecto: IMC 
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto permite trabajar con:
    Uso de clases 
    Uso de bibliotecas
    Uso de APIs
    Reutilización de código
    Software modular y compatibles con otro software

    

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/
#include "IMC.h"
#include <sstream> // Para std::stringstream
#include <string>
#include <nlohmann/json.hpp> // Biblioteca JSON

IMC::IMC()  {}

double IMC::calcularIMC(double peso, double altura) const
{
    return peso / std::pow(altura, 2);
}

/*
double Persona::calcularIMCAPI() const
{
    // Inicializa una sesión de CURL y asigna el manejador a la variable 'hnd'
    CURL *hnd = curl_easy_init();

    // Usar std::stringstream para construir la URL dinámicamente
    std::stringstream url; // Crea un objeto stringstream para construir la URL
    // Inserta el peso y la altura en la URL
    url << "https://body-mass-index-bmi-calculator.p.rapidapi.com/metric?weight=" << peso << "&height=" << altura;

    // Convierte el contenido del stringstream a un std::string
    std::string urlStr = url.str();
    // Convierte el std::string a un C-string y configura la URL para la solicitud CURL
    curl_easy_setopt(hnd, CURLOPT_URL, urlStr.c_str());

    // Las siguientes líneas se han comentado porque se reemplazan por la URL dinámica anterior
    //curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    //curl_easy_setopt(hnd, CURLOPT_URL, "https://body-mass-index-bmi-calculator.p.rapidapi.com/metric?weight=150&height=1.83");

    // Inicializa un puntero a una lista de encabezados para la solicitud HTTP
    struct curl_slist *headers = NULL;
    // Añade el encabezado de la clave de API a la lista de encabezados
    headers = curl_slist_append(headers, "x-rapidapi-key: 261657ce93msha29aa7438d5a366p1adfa7jsn7bdd387f38d7");
    // Añade el encabezado del host a la lista de encabezados
    headers = curl_slist_append(headers, "x-rapidapi-host: body-mass-index-bmi-calculator.p.rapidapi.com");
    // Configura la solicitud CURL para usar los encabezados definidos
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

// Aquí creamos un std::string para almacenar el resultado
        std::string responseString;
        std::string tempBuffer;

        // Capturar la salida estándar y redirigirla al string
        FILE* fp = fopen("/tmp/imc_response.txt", "wb"); // Archivo temporal
        curl_easy_setopt(hnd, CURLOPT_WRITEDATA, fp);    // Escribe la salida al archivo


    // Realiza la solicitud CURL
    CURLcode ret = curl_easy_perform(hnd);

     // Si la solicitud es exitosa, leemos el archivo temporal a un std::string
        if (ret == CURLE_OK) {
            fclose(fp);  // Cerramos el archivo
            fp = fopen("/tmp/imc_response.txt", "r"); // Lo abrimos para leer
            if (fp) {
                char buffer[1024]; // Buffer temporal para leer
                while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                    responseString += buffer; // Acumulamos en responseString
                }
                fclose(fp);
            }
        } else {
            std::cerr << "Error en la solicitud CURL: " << curl_easy_strerror(ret) << std::endl;
        }

        // Limpia los recursos
        curl_slist_free_all(headers);
        curl_easy_cleanup(hnd);
        nlohmann::json jsonResponse = nlohmann::json::parse(responseString);

                // Acceder a los datos del JSON
                std::cout << "IMC: " << jsonResponse["bmi"] << std::endl;
                std::cout << "Categoría: " << jsonResponse["bmi_category"] << std::endl;
                
        return jsonResponse["bmi"];
}
*/
double IMC::calcularIMCAPI(double peso, double altura) const
{
    double retornar=0;

    // Usar std::stringstream para construir la URL dinámicamente
    std::stringstream url; // Crea un objeto stringstream para construir la URL
    // Inserta el peso y la altura en la URL
    url << "https://body-mass-index-bmi-calculator.p.rapidapi.com/metric?weight=" << peso << "&height=" << altura;
    std::string hd1="x-rapidapi-key: 261657ce93msha29aa7438d5a366p1adfa7jsn7bdd387f38d7";
    std::string hd2="x-rapidapi-host: body-mass-index-bmi-calculator.p.rapidapi.com";

    // Convierte el contenido del stringstream a un std::string
    std::string urlStr = url.str();

    try {

        std::string responseString = apiCliente.realizarSolicitud(urlStr, hd1, hd2); // Llama al adaptador APIClient
        // Procesar la respuesta JSON
        nlohmann::json jsonResponse = nlohmann::json::parse(responseString);
        
        // Verifica si los campos esperados están presentes
        if (jsonResponse.contains("bmi")) {
           retornar= jsonResponse["bmi"];
         return retornar;
        } else {
            throw std::runtime_error("Respuesta JSON no contiene los campos esperados.");
        }

    } catch (const std::invalid_argument &e) {
        std::cerr << "Error al parsear JSON: " << e.what() << std::endl; // Manejo de errores de JSON
    } catch (const std::runtime_error &e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl; // Manejo de excepciones
    } catch (...) {
        std::cerr << "Error desconocido al procesar la solicitud." << std::endl; // Captura de cualquier otro error
    }
    return 9999; // Retorna 9999 en caso de error
}

void IMC::evaluarIMC(const double &peso, const double &altura) const
{
    double imc = calcularIMC(peso, altura);
    std::cout << "Su Índice de Masa Corporal (IMC) es: " << imc << std::endl;

    if (imc < 18.5)
    {
        std::cout << "Usted está por debajo del peso normal." << std::endl;
    }
    else if (imc >= 18.5 && imc <= 24.9)
    {
        std::cout << "Usted tiene un peso normal." << std::endl;
    }
    else if (imc >= 25 && imc <= 29.9)
    {
        std::cout << "Usted tiene sobrepeso." << std::endl;
    }
    else
    {
        std::cout << "Usted tiene obesidad." << std::endl;
    }
}