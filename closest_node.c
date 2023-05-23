#include<stdio.h>
#define INFINITY 9999
#define MAX 9

void closestAdjacentNode(int Graph[MAX][MAX], int startnode) {
    int cost[MAX], visited[MAX], min, next_vertex, i, j, closest_vertex;

    min = INFINITY;
    for(i = 0; i < MAX; i++) {
      if (Graph[startnode][i] != 0 && Graph[startnode][i] < min) {
        min = Graph[startnode][i];
        closest_vertex = i;
      }
    }

    printf("Closest node is %d with distance %d\n", closest_vertex, min);
}
