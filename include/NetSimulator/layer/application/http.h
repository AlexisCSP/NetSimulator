#ifndef HTTP_H
#define HTTP_H

#include <string>
#include <vector>
#include <cstdint>

namespace HTTP {

    struct Header {
        std::string name;
        std::string value;
    };
    
    struct RequestMessage {
        std::string method;
        std::string url;
        std::string version;
        std::vector<Header> headers;
    };

    struct ResponseMessage {
        std::string version;
        std::string status_code;
        std::string phrase;
        std::vector<Header> headers;
    };

    void* encode(RequestMessage request_message);
    void* encode(ResponseMessage response_message);
    RequestMessage decode(void* data);
}

#endif