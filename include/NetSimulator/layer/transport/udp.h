#ifndef UDP_H
#define UDP_H

#include <cstdint>

namespace UDP {

    struct Header {
        uint16_t source_port;
        uint16_t destination_port;
        uint16_t length;
        uint16_t checksum;
    };

    struct Segment {
        Header header;
        void* payload;
    };

    void* encode(void* payload);
    Segment decode(void* data);
}

#endif
