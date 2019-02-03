#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <boost/graph/adjacency_list.hpp>

typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list<boost::listS, boost::vecS,boost::undirectedS, 
            boost::no_property, EdgeWeightProperty> UndirectedGraph;

class Network {
private:
    UndirectedGraph topology_;
public:
    Network();
    ~Network();
};

#endif
