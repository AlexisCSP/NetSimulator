#ifndef IPV4_H
#define IPV4_H

#include <iostream>
#include <cstdint>
#include <string>

class IPv4 {
private:
    uint8_t address_[4];
public:
    IPv4();
    IPv4(std::string address);
    ~IPv4();
    uint32_t address();
    friend std::ostream& operator<<(std::ostream& out, const IPv4& ip);
};

#endif
