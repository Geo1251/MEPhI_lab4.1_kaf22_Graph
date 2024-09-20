import matplotlib.pyplot as plt
import networkx as nx
import csv

G = nx.Graph()

colors = {}

with open('graph_coloring.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        G.add_edge(int(row[0]), int(row[1]), weight=int(row[2]))
        colors[int(row[0])] = int(row[3])
        colors[int(row[1])] = int(row[4])

color_map = [colors[node] for node in G.nodes()]

pos = nx.spring_layout(G)
nx.draw(G, pos, node_color=color_map, with_labels=True)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

plt.show()