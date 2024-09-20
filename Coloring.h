#ifndef COLORING_H
#define COLORING_H

#include "Graph.h"
#include "DirectedGraph.h"
#include <vector>
#include <algorithm>

class Coloring {
public:
    Coloring() {}

    std::vector<int> greedyColoring(Graph &g) {
        int V = g.getV();
        std::vector<int> result(V, -1); 
        result[0] = 0; 

        for (int u = 1; u < V; u++) {
            std::vector<bool> available(V, false); 

            for (auto &pair : g.getAdj()[u]) {
                int i = pair.first;
                if (result[i] != -1) {
                    available[result[i]] = true;
                }
            }

            int cr;
            for (cr = 0; cr < V; cr++) {
                if (available[cr] == false) {
                    break;
                }
            }

            result[u] = cr; 
        }

        return result; 
    }

    std::vector<int> greedyColoring(DirectedGraph &g) {
        int V = g.getV();
        std::vector<int> result(V, -1); 
        result[0] = 0; 

        for (int u = 1; u < V; u++) {
            std::vector<bool> available(V, false); 

            for (auto &pair : g.getAdj()[u]) {
                int i = pair.first;
                if (result[i] != -1) {
                    available[result[i]] = true;
                }
            }

            for (int v = 0; v < V; v++) {
                for (auto &pair : g.getAdj()[v]) {
                    if (pair.first == u && result[v] != -1) {
                        available[result[v]] = true;
                    }
                }
            }

            int cr;
            for (cr = 0; cr < V; cr++) {
                if (available[cr] == false) {
                    break;
                }
            }

            result[u] = cr; 
        }

        return result; 
    }
};

#endif // COLORING_H