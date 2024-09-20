#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>

class Graph {
protected:
    int V; 
    std::vector<std::list<std::pair<int, int>>> adj; 
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    virtual void addEdge(int v, int w, int weight) = 0; 

    int getV() const { return V; }
    std::vector<std::list<std::pair<int, int>>>& getAdj() { return adj; }
};

#endif // GRAPH_H