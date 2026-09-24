// Objective: To implement Depth First Search traversal for a graph.
// Problem: Write a program to perform DFS traversal starting from a given source vertex.
// Input: adj[][] = [[1,2], [0,2], [0,1,3,4], [2], [2]]
// Output:
// [0, 1, 2, 3, 4]




#include <stdio.h>

int visited[5];


void dfs(int graph[5][5], int node)
{
    visited[node] = 1;
    printf("%d ", node);

    for(int i = 0; i < 5; i++)
    {
        if(graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(graph, i);
        }
    }
}

int main()
{
    
    int graph[5][5] = {
        {0,1,1,0,0},
        {1,0,1,0,0},
        {1,1,0,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };

    printf("DFS Traversal: ");
    dfs(graph, 0);

    return 0;
}