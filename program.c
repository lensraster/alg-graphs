#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include "shortest_path.c"
#include "dfs.c"
#include "closest_node.c"
#include "disconnected.c"

#define INFINITY 9999
#define MAX 9

void findShortestPath(int Graph[MAX][MAX]) {
    int city1;
    int city2;
    printf("Choose the first city: ");
    scanf("%d", &city1);
    printf("Choose the second city: ");
    scanf("%d", &city2);

    printf("You have chosen city1: %d and city2: %d\n", city1, city2);
    dijkstra(Graph, city1, city2);
}

void findAllPaths(int Graph[MAX][MAX]) {
    int city1;
    int city2;
    printf("Choose the first city: ");
    scanf("%d", &city1);
    printf("Choose the second city: ");
    scanf("%d", &city2);

    printf("You have chosen city1: %d and city2: %d\n", city1, city2);

    // Set missing edges to INF
    for(int i = 0; i < MAX; i++) {
      for(int j = 0; j < MAX; j++) {
          if(i != j) {
              if (Graph[i][j] == 0) {
                Graph[i][j] = INF;
              }
          } else {
              Graph[i][j] = 0;
          }
      }
    }
    printAllPaths(city1, city2, Graph);
}

void findMinimalDistance(int Graph[MAX][MAX]) {
    int city1;
    printf("Choose the starting city: ");
    scanf("%d", &city1);

    closestAdjacentNode(Graph, city1);
}

void findDisconnected(int Graph[MAX][MAX]) {
    // Set missing edges to INF
    for(int i = 0; i < MAX; i++) {
      for(int j = 0; j < MAX; j++) {
          if(i != j) {
              if (Graph[i][j] == 0) {
                Graph[i][j] = INF;
              }
          } else {
              Graph[i][j] = 0;
          }
      }
    }

    floydWarshall(Graph);
}

int main() {
    int choice;

    int Graph[N][N] = {
      {0, 10, 0, 0, 7, 0, 0, 0, 0},
      {0, 0, 5, 0, 40, 0, 8, 0, 0},
      {0, 0, 0, 2, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 9, 0, 0, 0},
      {0, 0, 0, 4, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {11, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 12, 0, 0},
      {0, 0, 0, 3, 0, 0, 0, 0, 0}
    };

    printf("Choose an option:\n");
    printf("1. Find shortest path\n");
    printf("2. Find all paths\n");
    printf("3. Find minimal distance\n");
    printf("4. Find all disconnected nodes\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            findShortestPath(Graph);
            break;
        case 2:
            findAllPaths(Graph);
            break;
        case 3:
            findMinimalDistance(Graph);
            break;
        case 4:
            findDisconnected(Graph);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
