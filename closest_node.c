#include<stdio.h>
#define INFINITY 9999
#define MAX 9

/**
 * Finds and prints the closest node to the start node
 * @param Graph the graph to search
 * @param startnode the node to start from
 * @return void
 */
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
