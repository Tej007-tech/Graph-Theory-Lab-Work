// Objective: To understand the basic properties and structure of trees using graph operations.
// Problem 1: Write a program to perform the following operations on a tree:
// 1. Identify all pendent (leaf) vertices.
// 2. Find the degree of each vertex.
// 3. Find distance between vertices.
// 4. Find eccentricity of each vertex
// 5. Find the center of the tree.
// 6. Verify whether the given graph is a tree or not.
// Input: V = 6, edges [][] = {(0,1), (1,2), (1,3), (3,4), (3,5)}
// Output:
// 1. List of pendent vertices
// 2. Degree of each vertex
// 3. Distance matrix
// 4. Eccentricity of each vertex
// 5. Center of the tree
// 6. Confirmation whether the graph is a tree

#include <stdio.h>

#define V 6

void BFS(int adj[V][V], int start, int dist[V][V])
{
    int visited[V] = {0};
    int queue[V];

    for (int i = 0; i < V; i++)
        dist[start][i] = -1;

    int front = 0, rear = 0;

    visited[start] = 1;
    dist[start][start] = 0;
    queue[rear++] = start;

    while (front < rear)
    {
        int curr = queue[front++];

        for (int i = 0; i < V; i++)
        {
            if (adj[curr][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                dist[start][i] = dist[start][curr] + 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int edge[][2] =
        {
            {0, 1},
            {1, 2},
            {1, 3},
            {3, 4},
            {3, 5}};

    int e = 5;

    int Adj[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            Adj[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int src = edge[i][0];
        int dest = edge[i][1];

        Adj[src][dest] = 1;
        Adj[dest][src] = 1;
    }

    printf("Adjacency Matrix:\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }

    printf("\nDegree of Vertices:\n");

    for (int i = 0; i < V; i++)
    {
        int degree = 0;

        for (int j = 0; j < V; j++)
        {
            if (Adj[i][j] == 1)
                degree++;
        }

        printf("Vertex %d -> Degree = %d\n", i, degree);
    }

    printf("\nPendant Vertices:\n");

    for (int i = 0; i < V; i++)
    {
        int degree = 0;

        for (int j = 0; j < V; j++)
        {
            if (Adj[i][j] == 1)
                degree++;
        }

        if (degree == 1)
            printf("%d\n", i);
    }

    int dist[V][V];

    for (int i = 0; i < V; i++)
    {
        BFS(Adj, i, dist);
    }

    printf("\nDistance Matrix:\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%2d ", dist[i][j]);
        }
        printf("\n");
    }

    int ecc[V];

    printf("\nEccentricity of each Vertex:\n");

    for (int i = 0; i < V; i++)
    {
        ecc[i] = 0;

        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] > ecc[i])
                ecc[i] = dist[i][j];
        }

        printf("Vertex %d -> %d\n", i, ecc[i]);
    }

    
    int min = ecc[0];

    for (int i = 1; i < V; i++)
    {
        if (ecc[i] < min)
            min = ecc[i];
    }

    printf("\nCenter of Tree:\n");

    for (int i = 0; i < V; i++)
    {
        if (ecc[i] == min)
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}