// Objective: To identify articulation points in an undirected graph
// and determine connectivity and separability of a graph.
//
// Problem: Write a program to find all cut-vertices of a graph.
//
// Input: Connected graph with vertices and edges.
// Output: List of articulation points.

#include <stdio.h>

#define V 5

int visited[V];


void dfs(int graph[V][V], int node, int skip)
{
    visited[node] = 1;

    for (int i = 0; i < V; i++)
    {
    
        if (i != skip && graph[node][i] == 1 && !visited[i])
        {
            dfs(graph, i, skip);
        }
    }
}

int main()
{
   

    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };

  

    
    for (int skip = 0; skip < V; skip++)
    {
     
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }

       
        int start = -1;

        for (int i = 0; i < V; i++)
        {
            if (i != skip)
            {
                start = i;
                break;
            }
        }

    
        dfs(graph, start, skip);


        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (i != skip && !visited[i])
            {
                count = 1;
                break;
            }
        }

        
        if (count)
        {
            printf("%d ", skip);
        }
    }

    return 0;
}