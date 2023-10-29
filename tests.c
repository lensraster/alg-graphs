#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include "shortest_path.c"
#include <assert.h>

#define MAX 9

void test_finding_shortest_path() {
    int Graph[MAX][MAX] = {
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
    int **return_array = dijkstra(Graph, 0);
    assert(return_array[0][5] == 20);
    assert(return_array[1][5] == 3);
    assert(return_array[1][3] == 4);
    assert(return_array[1][4] == 0);
}

int main() {
    test_finding_shortest_path();
    printf("All tests ran successfully\n");
    return 0;
}