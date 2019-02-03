#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "../include/NetSimulator/ipv4.h"

IPv4::IPv4() {
    const std::size_t num_bytes = 4; 
    for(std::size_t i = 0; i < num_bytes; i++) {
        address_[i] = 0;
    }
}

IPv4::IPv4(std::string address) {
    // TODO: Add check for valid IPv4 address
    std::vector<std::string> address_parts;
    boost::split(address_parts, address, boost::is_any_of("."));
    std::size_t i = 0;
    for(auto&& part : address_parts) {
        address_[i++] = boost::lexical_cast<uint>(part);
    }
}

IPv4::~IPv4() {
    // Empty 
}

uint32_t IPv4::address() {
    return *(uint32_t *) address_;
}

std::ostream& operator<<(std::ostream& out, const IPv4& ip) {
    // TODO: Refactor to general implementation
    out << unsigned(ip.address_[0]) << "."
        << unsigned(ip.address_[1]) << "." 
        << unsigned(ip.address_[2]) << "." 
        << unsigned(ip.address_[2]);
    return out;
}