// Objective: Determine connectivity and separability of a graph 
// Problem: Write a program to: 
// 1. Find vertex connectivity 
// 2. Find edge connectivity 
// 3. Construct fundamental cut-sets 
// 4. Determine whether graph is separable or non-separable 
// Input: Undirected graph. 
// Output: Connectivity values and graph type 


// 3. Construct Fundamental Cut-Sets using DFS Spanning Tree

#include <stdio.h>

int graph[10][10];
int visited[10];
int n;

void DFS(int v){
    int i;

    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
           
            printf("%d - %d\n", v, i);

            DFS(i);
        }
    }
}

int main()
{
    int e, u, v, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

 
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (j = 0; j < n; j++)
            graph[i][j] = 0;
    }


    printf("Enter edges:\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    
    printf("\nDFS Spanning Tree:\n");

    DFS(0);

    printf("\nNumber of Fundamental Cut-Sets = %d\n", n - 1);

    return 0;
}