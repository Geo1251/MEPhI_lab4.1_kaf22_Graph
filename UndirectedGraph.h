#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "Graph.h"

class UndirectedGraph : public Graph {
public:
    UndirectedGraph(int V) : Graph(V) {}
    void addEdge(int v, int w, int weight) override {
        adj[v].push_back({w, weight}); 
        adj[w].push_back({v, weight}); 
    }
};

#endif // UNDIRECTEDGRAPH_H