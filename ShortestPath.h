#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "Graph.h"
#include <vector>
#include <climits>

class ShortestPath {
public:
    ShortestPath() {}

    std::vector<int> bellmanFord(Graph& g, int src) {
        int V = g.getV();
        std::vector<int> distance(V, INT_MAX);
        distance[src] = 0;

        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < V; j++) {
                for (auto edge : g.getAdj()[j]) {
                    int u = j;
                    int v = edge.first;
                    int weight = edge.second;
                    if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                    }
                }
            }
        }

        for (int j = 0; j < V; j++) {
            for (auto edge : g.getAdj()[j]) {
                int u = j;
                int v = edge.first;
                int weight = edge.second;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    throw std::runtime_error("Graph contains a negative-weight cycle");
                }
            }
        }

        return distance;
    }
};

#endif // SHORTESTPATH_H