import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

df = pd.read_csv('graph.csv', header=None)

G = nx.DiGraph()

for _, row in df.iterrows():
    G.add_edge(str(row[0]), str(row[1]), weight=row[2])


pos = nx.spring_layout(G)  
nx.draw(G, pos, with_labels=True, arrows=True)  
labels = nx.get_edge_attributes(G, 'weight')  
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)  

plt.show()  