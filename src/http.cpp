#include "../include/NetSimulator/layer/application/http.h"
#include <cstring>

#define CR "\r"
#define LF "\n" 

void* HTTP::encode(HTTP::RequestMessage request_message) {
    std::string message_string = request_message.method + " "
                                + request_message.url + " "
                                + request_message.version + CR + LF;

    for(auto&& header : request_message.headers) {
        message_string += header.name + " " + header.value + CR + LF;
    }
    
    message_string.append(CR);
    message_string.append(LF);
    char* encoded_message = new char[message_string.size()];

    strncpy(encoded_message, message_string.c_str(), message_string.size());
    return encoded_message; 
}

void* HTTP::encode(HTTP::ResponseMessage response_message);

HTTP::RequestMessage HTTP::decode(void* data);