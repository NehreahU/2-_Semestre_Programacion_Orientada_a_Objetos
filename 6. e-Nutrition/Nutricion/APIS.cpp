#include <curl/curl.h>
#include <iomanip>
#include "APIS.h"



// Función de callback para manejar la respuesta
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}

// Método de traduce un string en urlencoded
std::string APIS::urlNut(const std::string& valueReceta) {
    std::ostringstream encoded;
    encoded << std::hex << std::uppercase;
    std::string url
    
    for (unsigned char c : valueReceta) {
        // Si es alfanumérico, guión, subrayado o punto, lo dejamos sin cambios
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded << c;
        } else {
            // Si no, lo convertimos a %XX
            encoded << '%' << std::setw(2) << int(c);
        }
    }
    url = "https://api.edamam.com/api/nutrition-data?app_id=" + app_id + "&app_key=" + app_key + "&ingr="+encoded.str();
    return url;
}


void APIS::curlInit(std::string& auxUrl){
    curl = curl_easy_init();
    if(curl) {
        // Configura la URL
        curl_easy_setopt(curl, CURLOPT_URL, auxUrl.c_str());

        // Callback para almacenar la respuesta en una cadena
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Realiza la solicitud
        res = curl_easy_perform(curl);

        // Verifica el resultado
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Muestra la respuesta JSON de la API
            std::cout << "Respuesta de la API: " << response << std::endl;
        }

        // Limpia la memoria
        curl_easy_cleanup(curl);
    }
}



