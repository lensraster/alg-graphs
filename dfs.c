#include <stdio.h>
#include <stdlib.h>

#define MAX_PATHS 1000  // Maximum number of paths
#define MAX_NODES 9  // Maximum number of nodes in the graph
#define INF 99999999  // Infinity value used for initialization

typedef struct {
    int path[MAX_NODES];  // Store the nodes in this path
    int pathLength;  // The number of nodes in this path
    int totalWeight;  // The total weight (cost) of this path
} Path;

// Function to create a new path and add it to the array of paths
void createPath(int path[], int pathLength, int totalWeight, Path paths[], int* pathCount) {
    Path p;
    p.pathLength = pathLength;
    p.totalWeight = totalWeight;
    for(int i = 0; i < pathLength; i++) {
        p.path[i] = path[i];
    }
    paths[*pathCount] = p;
    (*pathCount)++;
}

// DFS function to explore all paths from a starting node to an ending node
void DFS(int start, int end, int totalWeight, int graph[MAX_NODES][MAX_NODES], int visited[], int path[], int* path_idx, Path paths[], int* pathCount) {
    // Mark the start node as visited and add it to the current path
    visited[start] = 1;
    path[*path_idx] = start;
    (*path_idx)++;

    // If we've reached the end node, add the current path to the array of paths
    if (start == end) {
        createPath(path, *path_idx, totalWeight, paths, pathCount);
    } else {
        // If we haven't reached the end node, continue exploring the graph
        for (int i = 0; i < MAX_NODES; i++) {
            if (!visited[i] && graph[start][i] != INF) {
                DFS(i, end, totalWeight + graph[start][i], graph, visited, path, path_idx, paths, pathCount);
            }
        }
    }

    // Backtrack: remove the current node from the current path and mark it as unvisited
    (*path_idx)--;
    visited[start] = 0;
}

// Comparison function for qsort
int comparePaths(const void* a, const void* b) {
    return ((Path*)b)->totalWeight - ((Path*)a)->totalWeight;
}

// Function to find and print all paths from a starting node to an ending node
void printAllPaths(int start, int end, int graph[MAX_NODES][MAX_NODES]) {
    int visited[MAX_NODES] = {0};  // Array to track visited nodes
    int path[MAX_NODES];  // Array to store the current path
    int path_idx = 0;  // Index of the current path
    Path paths[MAX_PATHS];  // Array to store all paths
    int pathCount = 0;  // Number of paths found

    // Start DFS
    DFS(start, end, 0, graph, visited, path, &path_idx, paths, &pathCount);

    // Sort paths in descending order of total weight
    qsort(paths, pathCount, sizeof(Path), comparePaths);

    // Print all paths
    for (int i = 0; i < pathCount; i++) {
        printf("Path %d (total weight = %d): ", i + 1, paths[i].totalWeight);
        for (int j = 0; j < paths[i].pathLength; j++) {
            printf("%d ", paths[i].path[j]);
        }
        printf("\n");
    }
}
