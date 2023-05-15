#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include "shortest_path.c"
#include "dfs.c"

#define INFINITY 9999
#define MAX 9

void findShortestPath(int Graph[MAX][MAX]) {
    int city1;
    int city2;
    printf("Shoose the first city: ");
    scanf("%d", &city1);
    printf("Shoose the second city: ");
    scanf("%d", &city2);

    printf("You have chosen city1: %d and city2 %d\n", city1, city2);
    dijkstra(Graph, city1, city2);
}

void findAllPaths(int Graph[MAX][MAX]) {
    int city1;
    int city2;
    printf("Shoose the first city: ");
    scanf("%d", &city1);
    printf("Shoose the second city: ");
    scanf("%d", &city2);

    printf("You have chosen city1: %d and city2 %d\n", city1, city2);

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

void findMinimalDistance() {
    int city1;
    printf("Shoose the first city");
    scanf("%d", &city1);
}

// void readJsonFile(const char *filename) {
//     json_t *root;
//     json_error_t error;

//     root = json_load_file(filename, 0, &error);

//     if (!root) {
//         fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
//         return;
//     }

//     if (!json_is_object(root)) {
//         fprintf(stderr, "error: root is not an object\n");
//         json_decref(root);
//         return;
//     }

//     json_t *data;
//     const char *key;

//     json_object_foreach(root, key, data) {
//         printf("%s: %s\n", key, json_string_value(data));
//     }

//     json_decref(root);
// }

int main() {
    int choice;

    //readJsonFile("cities.json");

    int Graph[V][V] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},
      {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},
      {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0},
      {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},
      {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    printf("Choose an option:\n");
    printf("1. Find shortest path 1\n");
    printf("2. Find all paths 2\n");
    printf("3. Find minimal distance 3\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            findShortestPath(Graph);
            break;
        case 2:
            findAllPaths(Graph);
            break;
        case 3:
            findMinimalDistance();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
