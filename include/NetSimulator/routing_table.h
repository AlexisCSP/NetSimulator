#ifndef ROUTING_TABLE_H
#define ROUTING_TABLE_H

#include <map>
#include <vector>
#include "ipv4.h"

class RoutingTable {
private:
    struct entry {
        IPv4 network_destination;
        IPv4 netmask;
        IPv4 gateway;
        IPv4 Interface;
        unsigned metric;
    };
    std::map<unsigned, struct entry> data_;

public:
    RoutingTable();
    virtual ~RoutingTable();
};

#endif
