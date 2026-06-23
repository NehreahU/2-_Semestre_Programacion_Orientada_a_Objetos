#ifndef APIS_H
#define APIS_H

#include <string>

class APIS {
private: 

std::string response;

CURL* curl;
CURLcode res;

std::string app_id = "66c863b9";
std::string app_id2;
std::string app_key = "3b797da8030d8bbace629fccab47de17";
std::string app_key2;


public:

std::string APIS::urlNut(const std::string& valueReceta);

void curlInit(std::string& auxUrl);




#endif
