#ifndef IPV4_H
#define IPV4_H

#include <cstdint>

class IPv4 {
private:
    uint8_t address_[4];
public:
    IPv4(/* args */);
    ~IPv4();
};

#endif
