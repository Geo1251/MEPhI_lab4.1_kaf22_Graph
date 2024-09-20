#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include "Graph.h"

class DirectedGraph : public Graph {
public:
    DirectedGraph(int V) : Graph(V) {}
    void addEdge(int v, int w, int weight) override {
        adj[v].push_back({w, weight}); 
    }
};

#endif // DIRECTEDGRAPH_H