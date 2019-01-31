#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include "routing_table.h"

class Router {
private:
    std::string name_;
    RoutingTable routing_table_;
public:
    Router();
    virtual ~Router();
};

#endif
