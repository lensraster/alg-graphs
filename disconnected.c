#include<stdio.h>
#include<stdlib.h>

#define N 9
#define MAX 9

void printSolutionMatrix(int dist[][N]);

void printSolutionStr(int dist[][N]);

// The main function that finds shortest distances from all vertices to all other vertices
void floydWarshall(int graph[][N])
{
    int dist[N][N], i, j, k;

    // Initialize the solution matrix same as the input graph matrix.
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dist[i][j] = graph[i][j];

    // Pick all vertices one by one and update all shortest paths which include the picked vertex as an intermediate vertex
    for (k = 0; k < N; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < N; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < N; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolutionStr(dist);
}

void printSolutionMatrix(int dist[][N])
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void printSolutionStr(int dist[][N])
{
    printf ("Nodes without connection:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j) {
                if (dist[i][j] == INF)
                    printf("node %d and node %d\n", i, j);
            }
        }
    }
}
