#include <stdio.h>
#include <stdlib.h>

#define MAX_PATHS 1000
#define MAX_NODES 9
#define INF 99999999

typedef struct {
    int path[MAX_NODES];
    int pathLength;
    int totalWeight;
} Path;

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

void DFS(int start, int end, int totalWeight, int graph[MAX_NODES][MAX_NODES], int visited[], int path[], int* path_idx, Path paths[], int* pathCount) {
    visited[start] = 1;
    path[*path_idx] = start;
    (*path_idx)++;

    if (start == end) {
        createPath(path, *path_idx, totalWeight, paths, pathCount);
    } else {
        for (int i = 0; i < MAX_NODES; i++) {
            if (!visited[i] && graph[start][i] != INF) {
                DFS(i, end, totalWeight + graph[start][i], graph, visited, path, path_idx, paths, pathCount);
            }
        }
    }

    (*path_idx)--;
    visited[start] = 0;
}

int comparePaths(const void* a, const void* b) {
    return ((Path*)b)->totalWeight - ((Path*)a)->totalWeight;
}

void printAllPaths(int start, int end, int graph[MAX_NODES][MAX_NODES]) {
    int visited[MAX_NODES] = {0};
    int path[MAX_NODES];
    int path_idx = 0;
    Path paths[MAX_PATHS];
    int pathCount = 0;

    DFS(start, end, 0, graph, visited, path, &path_idx, paths, &pathCount);

    qsort(paths, pathCount, sizeof(Path), comparePaths);

    for (int i = 0; i < pathCount; i++) {
        printf("Path %d (total weight = %d): ", i + 1, paths[i].totalWeight);
        for (int j = 0; j < paths[i].pathLength; j++) {
            printf("%d ", paths[i].path[j]);
        }
        printf("\n");
    }
}

// int main() {
//     int graph[MAX_NODES][MAX_NODES];
//     for(int i = 0; i < MAX_NODES; i++) {
//         for(int j = 0; j < MAX_NODES; j++) {
//             if(i != j) {
//                 graph[i][j] = INF;
//             } else {
//                 graph[i][j] = 0;
//             }
//         }
//     }

//     // Add edges to the graph here...
//     graph[0][1] = 2;
//     graph[1][2] = 3;
//     graph[2][3] = 4;
//     graph[3][4] = 5;

//     int start = 0, end = 4;
//     printAllPaths(start, end, graph);

//     return 0;
// }
