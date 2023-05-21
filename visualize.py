import networkx as nx
import matplotlib.pyplot as plt

# Define your adjacency matrix
matrix = [
 [0, 10, 0, 0, 7, 0, 0, 0, 0],
 [0, 0, 5, 0, 0, 0, 8, 0, 0],
 [0, 0, 0, 2, 0, 0, 0, 6, 0],
 [0, 3, 0, 0, 0, 9, 0, 0, 1],
 [0, 0, 0, 4, 0, 0, 0, 0, 0],
 [0, 0, 0, 0, 0, 0, 0, 5, 0],
 [11, 0, 0, 0, 0, 0, 0, 0, 0],
 [0, 0, 0, 0, 0, 0, 12, 0, 0],
 [0, 0, 0, 0, 0, 0, 0, 0, 0]
]



# Create a new directed graph
G = nx.DiGraph()

# Add edges to the graph with weights from the adjacency matrix
for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        if matrix[i][j] != 0:
            G.add_edge(i, j, weight=matrix[i][j])

# Draw the graph
pos = nx.shell_layout(G)
nx.draw(G, pos, with_labels=True, node_color='lightblue', 
         font_weight='bold', arrows=True, arrowstyle='-|>', 
         arrowsize=20)

# Draw edge labels
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

# Show the graph
plt.show()
