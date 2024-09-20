#include "Coloring.h"
#include "ShortestPath.h"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <fstream>

void testDirectedGraphAuto() {
    std::cout << "Starting test for directed graph...\n";
    srand(time(0)); 

    int V = 5; 
    std::cout << "Creating a directed graph with " << V << " vertices.\n";
    DirectedGraph g(V);

    for (int i = 0; i < V; i++) {
        int edges = rand() % (V - 1) + 1; 
        std::cout << "Adding " << edges << " edges to vertex " << i << ".\n";
        for (int j = 0; j < edges; j++) {
            int w = rand() % V;
            int weight = rand() % 10 + 1;
            auto it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), 
            [w](const std::pair<int, int>& element){ return element.first == w; });
            if (it == g.getAdj()[i].end()) {
                std::cout << "Adding edge from " << i << " to " << w << " with weight " << weight << ".\n";
                g.addEdge(i, w, weight);
                it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), 
                [w](const std::pair<int, int>& element){ return element.first == w; });
                assert(it != g.getAdj()[i].end() && it->second == weight);
            }
        }
    }

    std::cout << "Printing the directed graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            std::cout << v << " -> " << x.first << " (weight " << x.second << ")\n";
        }
    }

    std::ofstream file("graph.csv");
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            file << v << "," << x.first << "," << x.second << "\n";
        }
    }
    file.close();

    std::system("C:/Users/georg/AppData/Local/Programs/Python/Python39/python.exe c:/Users/georg/Desktop/Labs_2course/lab4/visualize_graph_Di.py");

    std::cout << "Test for directed graph completed successfully.\n";
}

void testUndirectedGraphAuto() {
    std::cout << "Starting test for undirected graph...\n";
    srand(time(0)); 

    int V = 5; 
    std::cout << "Creating an undirected graph with " << V << " vertices.\n";
    UndirectedGraph g(V);

    for (int i = 0; i < V; i++) {
        int edges = rand() % (V - 1) + 1; 
        std::cout << "Adding " << edges << " edges to vertex " << i << ".\n";
        for (int j = 0; j < edges; j++) {
            int w = rand() % V;
            int weight = rand() % 10 + 1; 
            auto it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), 
            [w](const std::pair<int, int>& element){ return element.first == w; });
            if (i != w && it == g.getAdj()[i].end()) {
                std::cout << "Adding edge from " << i << " to " << w << " with weight " << weight << ".\n";
                g.addEdge(i, w, weight);
                it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), 
                [w](const std::pair<int, int>& element){ return element.first == w; });
                assert(it != g.getAdj()[i].end() && it->second == weight);
            }
        }
    }

    std::cout << "Printing the undirected graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                std::cout << v << " <-> " << x.first << " (weight " << x.second << ")\n";
            }
        }
    }

    std::ofstream file("graph.csv");
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                file << v << "," << x.first << "," << x.second << "\n";
            }
        }
    }
    file.close();

    std::system("C:/Users/georg/AppData/Local/Programs/Python/Python39/python.exe c:/Users/georg/Desktop/Labs_2course/lab4/visualize_graph_UnDi.py");

    std::cout << "Test for undirected graph completed successfully.\n";
}

void testUndirectedGraphColoringAuto() {
    std::cout << "Starting test for undirected graph coloring...\n";
    srand(time(0)); 

    int V = 5; 
    std::cout << "Creating an undirected graph with " << V << " vertices.\n";
    UndirectedGraph g(V);

    for (int i = 0; i < V; i++) {
        int edges = rand() % (V - 1) + 1; 
        std::cout << "Adding " << edges << " edges to vertex " << i << ".\n";
        for (int j = 0; j < edges; j++) {
            int w = rand() % V;
            int weight = rand() % 10 + 1; 
            auto it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), 
                                   [w](const std::pair<int, int>& element){ return element.first == w; });
            if (i != w && it == g.getAdj()[i].end()) {
                std::cout << "Adding edge from " << i << " to " << w << " with weight " << weight << ".\n";
                g.addEdge(i, w, weight);
                it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), 
                                  [w](const std::pair<int, int>& element){ return element.first == w; });
                assert(it != g.getAdj()[i].end() && it->second == weight);
            }
        }
    }

    std::cout << "Printing the graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                std::cout << v << " <-> " << x.first << " (weight " << x.second << ")\n";
            }
        }
    }

    Coloring c;
    std::vector<int> result = c.greedyColoring(g);

    std::cout << "Colors of vertices:\n";
    for (int u = 0; u < g.getV(); u++) {
        std::cout << "Vertex " << u << " --->  Color " << result[u] << "\n";
    }

    assert(*max_element(result.begin(), result.end()) < V);

    std::ofstream file("graph_coloring.csv");
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                file << v << "," << x.first << "," << x.second << "," << result[v] << "," << result[x.first] << "\n";
            }
        }
    }
    file.close();
    std::system("C:/Users/georg/AppData/Local/Programs/Python/Python39/python.exe c:/Users/georg/Desktop/Labs_2course/lab4/visualize_graph_coloring_UnDi.py");

    std::cout << "Test for undirected graph coloring completed successfully.\n";
}

void testDirectedGraphColoringAuto() {
    std::cout << "Starting test for directed graph coloring...\n";
    srand(time(0)); 

    int V = 5; 
    std::cout << "Creating a directed graph with " << V << " vertices.\n";
    DirectedGraph g(V);

    for (int i = 0; i < V; i++) {
        int edges = rand() % (V - 1) + 1; 
        std::cout << "Adding " << edges << " edges to vertex " << i << ".\n";
        for (int j = 0; j < edges; j++) {
            int w = rand() % V;
            int weight = rand() % 10 + 1; 
            auto it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), 
                                   [w](const std::pair<int, int>& element){ return element.first == w; });
            if (it == g.getAdj()[i].end()) {
                std::cout << "Adding edge from " << i << " to " << w << " with weight " << weight << ".\n";
                g.addEdge(i, w, weight);
                it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), 
                                  [w](const std::pair<int, int>& element){ return element.first == w; });
                assert(it != g.getAdj()[i].end() && it->second == weight);
            }
        }
    }

    std::cout << "Printing the graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            std::cout << v << " -> " << x.first << " (weight " << x.second << ")\n";
        }
    }

    Coloring c;
    std::vector<int> result = c.greedyColoring(g);

    std::cout << "Colors of vertices:\n";
    for (int u = 0; u < g.getV(); u++) {
        std::cout << "Vertex " << u << " --->  Color " << result[u] << "\n";
    }

    assert(*max_element(result.begin(), result.end()) < V);

    std::ofstream file("graph_coloring.csv");
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                file << v << "," << x.first << "," << x.second << "," << result[v] << "," << result[x.first] << "\n";
            }
        }
    }
    file.close();
    std::system("C:/Users/georg/AppData/Local/Programs/Python/Python39/python.exe c:/Users/georg/Desktop/Labs_2course/lab4/visualize_graph_coloring_Di.py");

    std::cout << "Test for directed graph coloring completed successfully.\n";
}

void testDirectedGraphShortestPathAuto() {
    std::cout << "Starting test for directed graph shortest path...\n";
    srand(time(0)); 

    int V = 5; 
    std::cout << "Creating a directed graph with " << V << " vertices.\n";
    DirectedGraph g(V);

    for (int i = 0; i < V; i++) {
        int edges = rand() % (V - 1) + 1; 
        std::cout << "Adding " << edges << " edges to vertex " << i << ".\n";
        for (int j = 0; j < edges; j++) {
            int w = rand() % V;
            int weight = rand() % 10 + 1; 

            auto it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), [w](const std::pair<int, int>& pair) {
                return pair.first == w;
            });

            if (it == g.getAdj()[i].end()) {
                std::cout << "Adding edge from " << i << " to " << w << " with weight " << weight << ".\n";
                g.addEdge(i, w, weight);

                assert(std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), [w](const std::pair<int, int>& pair) {
                    return pair.first == w;
                }) != g.getAdj()[i].end());
            }
        }
    }

    std::cout << "Printing the graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            std::cout << v << " -> " << x.first << " (weight " << x.second << ")\n";
        }
    }

    ShortestPath s;
    for (int src = 0; src < V; src++) {
        std::vector<int> result = s.bellmanFord(g, src);

        std::cout << "Shortest paths from vertex " << src << ":\n";
        for (int u = 0; u < g.getV(); u++) {
            if (result[u] == INT_MAX) {
                std::cout << "Vertex " << u << " --->  No path from vertex " << src << "\n";
            } else {
                std::cout << "Vertex " << u << " --->  Distance " << result[u] << "\n";
            }
        }
    }

    std::cout << "Test for directed graph shortest path completed successfully.\n";
}

void testUndirectedGraphShortestPathAuto() {
    std::cout << "Starting test for undirected graph shortest path...\n";
    srand(time(0)); 

    int V = 5; 
    std::cout << "Creating an undirected graph with " << V << " vertices.\n";
    UndirectedGraph g(V);

    for (int i = 0; i < V; i++) {
        int edges = rand() % (V - 1) + 1; 
        std::cout << "Adding " << edges << " edges to vertex " << i << ".\n";
        for (int j = 0; j < edges; j++) {
            int w = rand() % V;
            int weight = rand() % 10 + 1; 

            auto it = std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), [w](const std::pair<int, int>& pair) {
                return pair.first == w;
            });

            if (i != w && it == g.getAdj()[i].end()) {
                std::cout << "Adding edge from " << i << " to " << w << " with weight " << weight << ".\n";
                g.addEdge(i, w, weight);

                assert(std::find_if(g.getAdj()[i].begin(), g.getAdj()[i].end(), [w](const std::pair<int, int>& pair) {
                    return pair.first == w;
                }) != g.getAdj()[i].end());
            }
        }
    }

    std::cout << "Printing the graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                std::cout << v << " <-> " << x.first << " (weight " << x.second << ")\n";
            }
        }
    }

    ShortestPath s;
    for (int src = 0; src < V; src++) {
        std::vector<int> result = s.bellmanFord(g, src);

        std::cout << "Shortest paths from vertex " << src << ":\n";
        for (int u = 0; u < g.getV(); u++) {
            if (result[u] == INT_MAX) {
                std::cout << "Vertex " << u << " --->  No path from vertex " << src << "\n";
            } else {
                std::cout << "Vertex " << u << " --->  Distance " << result[u] << "\n";
            }
        }
    }

    std::cout << "Test for undirected graph shortest path completed successfully.\n";
}

//--------------------------------------------------------------------------------------

void testDirectedGraphManual() {
    std::cout << "Starting test for directed graph...\n";

    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    DirectedGraph g(V);

    std::cout << "Enter edges in the format: source destination weight\n";

    for (int i = 0; i < V; i++) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;

        if (source >= 0 && source < V && destination >= 0 && destination < V) {
            g.addEdge(source, destination, weight);
        } else {
            std::cout << "Invalid source or destination vertex. Skipping this edge.\n";
        }
    }

    std::cout << "Printing the graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            std::cout << v << " -> " << x.first << " (weight " << x.second << ")\n";
        }
    }

    std::cout << "Printing the directed graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            std::cout << v << " -> " << x.first << " (weight " << x.second << ")\n";
        }
    }

    std::ofstream file("graph.csv");
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            file << v << "," << x.first << "," << x.second << "\n";
        }
    }
    file.close();

    std::system("C:/Users/georg/AppData/Local/Programs/Python/Python39/python.exe c:/Users/georg/Desktop/Labs_2course/lab4/visualize_graph_Di.py");

    std::cout << "Test for directed graph completed successfully.\n";
}

void testUndirectedGraphManual() {
    std::cout << "Starting test for undirected graph...\n";

    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    UndirectedGraph g(V);

    std::cout << "Enter edges in the format: source destination weight\n";

    for (int i = 0; i < V; i++) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;

        if (source >= 0 && source < V && destination >= 0 && destination < V) {
            g.addEdge(source, destination, weight);
        } else {
            std::cout << "Invalid source or destination vertex. Skipping this edge.\n";
        }
    }

    std::cout << "Printing the graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                std::cout << v << " <-> " << x.first << " (weight " << x.second << ")\n";
            }
        }
    }

    std::ofstream file("graph.csv");
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                file << v << "," << x.first << "," << x.second << "\n";
            }
        }
    }
    file.close();

    std::system("C:/Users/georg/AppData/Local/Programs/Python/Python39/python.exe c:/Users/georg/Desktop/Labs_2course/lab4/visualize_graph_UnDi.py");

    std::cout << "Test for undirected graph completed successfully.\n";
}

void testUndirectedGraphColoringManual() {
    std::cout << "Starting test for undirected graph coloring...\n";

    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    UndirectedGraph g(V);

    std::cout << "Enter edges in the format: source destination weight\n";
    for (int i = 0; i < V; i++) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;
        if (source >= 0 && source < V && destination >= 0 && destination < V) {
            g.addEdge(source, destination, weight);
            auto it = std::find_if(g.getAdj()[source].begin(), g.getAdj()[source].end(), 
                                [destination](const std::pair<int, int>& pair) {
                                    return pair.first == destination;
                                });
            assert(it != g.getAdj()[source].end());
        } else {
            std::cout << "Invalid edge. Skipping this edge.\n";
        }
    }

    std::cout << "Printing the undirected graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                std::cout << v << " <-> " << x.first << " (weight " << x.second << ")\n";
            }
        }
    }

    Coloring c;
    std::vector<int> result = c.greedyColoring(g);

    std::cout << "Colors of vertices:\n";
    for (int u = 0; u < g.getV(); u++) {
        std::cout << "Vertex " << u << " --->  Color " << result[u] << "\n";
    }

    assert(*max_element(result.begin(), result.end()) < V);

    std::ofstream file("graph_coloring.csv");
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                file << v << "," << x.first << "," << x.second << "," << result[v] << "," << result[x.first] << "\n";
            }
        }
    }
    file.close();
    std::system("C:/Users/georg/AppData/Local/Programs/Python/Python39/python.exe c:/Users/georg/Desktop/Labs_2course/lab4/visualize_graph_coloring_UnDi.py");

    std::cout << "Test for undirected graph coloring completed successfully.\n";
}

void testDirectedGraphColoringManual() {
    std::cout << "Starting test for directed graph coloring...\n";

    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    DirectedGraph g(V);

    std::cout << "Enter edges in the format: source destination weight\n";
    for (int i = 0; i < V; i++) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;
        if (source >= 0 && source < V && destination >= 0 && destination < V) {
            g.addEdge(source, destination, weight);
            auto it = std::find_if(g.getAdj()[source].begin(), g.getAdj()[source].end(), 
                                [destination](const std::pair<int, int>& pair) {
                                    return pair.first == destination;
                                });
            assert(it != g.getAdj()[source].end());
        } else {
            std::cout << "Invalid edge. Skipping this edge.\n";
        }
    }

    std::cout << "Printing the directed graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            std::cout << v << " -> " << x.first << " (weight " << x.second << ")\n";
        }
    }

    Coloring c;
    std::vector<int> result = c.greedyColoring(g);

    std::cout << "Colors of vertices:\n";
    for (int u = 0; u < g.getV(); u++) {
        std::cout << "Vertex " << u << " --->  Color " << result[u] << "\n";
    }

    assert(*max_element(result.begin(), result.end()) < V);

    std::ofstream file("graph_coloring.csv");
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                file << v << "," << x.first << "," << x.second << "," << result[v] << "," << result[x.first] << "\n";
            }
        }
    }
    file.close();
    std::system("C:/Users/georg/AppData/Local/Programs/Python/Python39/python.exe c:/Users/georg/Desktop/Labs_2course/lab4/visualize_graph_coloring_Di.py");

    std::cout << "Test for directed graph coloring completed successfully.\n";
}

void testUndirectedGraphShortestPathManual() {
    std::cout << "Starting test for undirected graph shortest path...\n";

    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    UndirectedGraph g(V);

    std::cout << "Enter edges in the format: source destination weight\n";
    for (int i = 0; i < V; i++) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;

        if (source >= 0 && source < V && destination >= 0 && destination < V) {
            g.addEdge(source, destination, weight);
        } else {
            std::cout << "Invalid source or destination vertex. Skipping this edge.\n";
        }
    }

    std::cout << "Printing the graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            if (v < x.first) {
                std::cout << v << " <-> " << x.first << " (weight " << x.second << ")\n";
            }
        }
    }

    ShortestPath s;
    for (int startVertex = 0; startVertex < V; startVertex++) {
        std::vector<int> result = s.bellmanFord(g, startVertex);

        assert(std::find(result.begin(), result.end(), INT_MAX) == result.end());

        std::cout << "Shortest paths from vertex " << startVertex << ":\n";
        for (int u = 0; u < g.getV(); u++) {
            std::cout << "Vertex " << u << " --->  Distance " << result[u] << "\n";
        }
    }

    std::cout << "Test for undirected graph shortest path completed successfully.\n";
}

void testDirectedGraphShortestPathManual() {
    std::cout << "Starting test for directed graph shortest path...\n";

    int V;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    DirectedGraph g(V);

    std::cout << "Enter edges in the format: source destination weight\n";
    for (int i = 0; i < V; i++) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;

        if (source >= 0 && source < V && destination >= 0 && destination < V) {
            g.addEdge(source, destination, weight);
        } else {
            std::cout << "Invalid source or destination vertex. Skipping this edge.\n";
        }
    }

    std::cout << "Printing the graph:\n";
    for (int v = 0; v < V; v++) {
        for (auto x : g.getAdj()[v]) {
            std::cout << v << " -> " << x.first << " (weight " << x.second << ")\n";
        }
    }

    ShortestPath s;
    for (int startVertex = 0; startVertex < V; startVertex++) {
        std::vector<int> result = s.bellmanFord(g, startVertex);

        std::cout << "Shortest paths from vertex " << startVertex << ":\n";
        for (int u = 0; u < g.getV(); u++) {
            if (result[u] == INT_MAX) {
                std::cout << "Vertex " << u << " --->  No path from vertex " << startVertex << "\n";
            } else {
                std::cout << "Vertex " << u << " --->  Distance " << result[u] << "\n";
            }
        }
    }

    std::cout << "Test for directed graph shortest path completed successfully.\n";
}