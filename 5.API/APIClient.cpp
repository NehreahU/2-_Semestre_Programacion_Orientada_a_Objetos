#include "APIClient.h"
#include <curl/curl.h>
#include <stdexcept>
#include <iostream>

std::string APIClient::realizarSolicitud(const std::string &url, const std::string &hd1, const std::string &hd2) const  {
    CURL* hnd = curl_easy_init();
    if (!hnd) {
        throw std::runtime_error("Error al inicializar cURL");
    }
    
    std::string responseString;
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, hd1.c_str());
    headers = curl_slist_append(headers, hd2.c_str());
    curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    
     // Capturar la salida estándar y redirigirla al string
        FILE* fp = fopen("/tmp/imc_response.txt", "wb"); // Archivo temporal
        curl_easy_setopt(hnd, CURLOPT_WRITEDATA, fp);    // Escribe la salida al archivo


    // Captura la respuesta
   // curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, NULL);
    //curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &responseString);
    
    CURLcode ret = curl_easy_perform(hnd);
    
    // Manejo de errores
    if (ret != CURLE_OK) {
        curl_slist_free_all(headers);
        curl_easy_cleanup(hnd);
        throw std::runtime_error("Error en la solicitud cURL: " + std::string(curl_easy_strerror(ret)));
    }
    else {
        fclose(fp);  // Cerramos el archivo
            fp = fopen("/tmp/imc_response.txt", "r"); // Lo abrimos para leer
            if (fp) {
                char buffer[1024]; // Buffer temporal para leer
                while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                    responseString += buffer; // Acumulamos en responseString
                }
                fclose(fp);
            }
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(hnd);
    return responseString; // Retorna la respuesta como cadena
}
