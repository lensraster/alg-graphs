#include <stdio.h>
#include <limits.h>

#define V 9  // number of vertices in the graph

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int inPath[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (inPath[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Function to print shortest path from source to j using parent array
void printPath(int parent[], int j) {
    if (parent[j] == - 1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Function to print the final solution
void printSolution(int parent[], int dest) {
    printf("Path: ");
    printPath(parent, dest);
    printf("\n");
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];  // dist[i] will hold the shortest distance from src to i

    int inPath[V]; // inPath[i] will be 1 if vertex i is included in shortest
                   // path tree or shortest distance from src to i is finalized

    int parent[V]; // This array stores the shortest path tree

    // Initialize all distances as INFINITE and stpSet[] as 0
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
        inPath[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, inPath);

        // Mark the picked vertex as processed
        inPath[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            if (!inPath[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // print the constructed distance array and shortest path
    printf("Shortest distance from %d to %d is %d\n", src, dest, dist[dest]);
    printSolution(parent, dest);
}

// int main() {
//     int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
//                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
//                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
//                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
//                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
//                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
//                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
//                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
//                        {0, 0, 2, 0, 0, 0, 6, 7, 0}
//                       };
//     int source = 0, destination = 8;
//     dijkstra(graph, source, destination);
//     return 0;
// }
