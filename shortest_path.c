#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9  // number of vertices in the graph

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int inPath[]) {
    int min = INT_MAX, min_index;
    // Iterate through all vertices to find the vertex with minimum distance
    for (int v = 0; v < V; v++)
        if (inPath[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

/**
 * Function to print shortest path from source to j using sPathTree array
 * It starts from the destination and goes backwards to the source.
 * Each element of sPathTree[] contains the parent node of the current node
 *  that lays on the shortest path back to the source node
 * @param sPathTree the array containing the shortest path tree
 * @param j the index of the node to print the path to
 * @return void
 */
void printPath(int sPathTree[], int j) {
    if (sPathTree[j] == - 1)
        return;
    printPath(sPathTree, sPathTree[j]);
    printf("%d ", j);
}

// Function to print the final solution
void printSolution(int sPathTree[], int dest) {
    printf("Path: ");
    printPath(sPathTree, dest);
    printf("\n");
}

/**
 * Finds and prints the shortest path between two cities
 * The function implements Dijkstra's single source shortest path algorithm
 * for a graph represented using adjacency matrix representation
 * @param graph the graph to search
 * @param src the index of the node to start from
 * @param dest the index of the node to end at
 * @return void
 */
int** dijkstra(int graph[V][V], int src) {
    int inPath[V]; // inPath[i] will be 1 if vertex i is included in shortest
                   // path tree or shortest distance from src to i is finalized
                   // We need it to avoid processing already processed vertices

    int dist[V];  // dist[i] will hold the shortest distance from src to every vertex i
    int sPathTree[V]; // This array stores the shortest path tree

    // This array will hold the shortest path and the distance
    // together so that we can return them both
    int **return_array = (int **)malloc(2 * sizeof(int *));
    for(int i = 0; i < 2; i++) {
        return_array[i] = (int *)malloc(V * sizeof(int));
    }
                            
 
    // Initialize all distances as INFINITE and inPath[] as 0
    for (int i = 0; i < V; i++) {
        sPathTree[i] = -1;
        dist[i] = INT_MAX;
        inPath[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest paths from src to all the other vertices
    for (int count = 0; count < V-1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, inPath);

        // Mark the picked vertex as processed
        inPath[u] = 1;

        // Iterate through all adjacent vertices of u (the picked vertex)
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            if (!inPath[v] && graph[u][v] && (dist[u] + graph[u][v] < dist[v])) {
                sPathTree[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // Copy the distance and the shortest path tree to the return array
    for (int i = 0; i < V; i++) {
        return_array[0][i] = dist[i];
        return_array[1][i] = sPathTree[i];
    }

    return return_array;
}
