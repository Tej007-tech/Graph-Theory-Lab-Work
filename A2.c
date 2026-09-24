// Objective: To implement Breadth First Search traversal for a graph.
// Problem: Perform a Breadth First Search (BFS) traversal starting from vertex 0.
// Input: adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]]
// Output:
// [0, 1, 2, 3, 4]



#include <stdio.h>

#define V 5

void BFS(int adj[V][V], int start)
{
    int visited[V] = {0};
    int queue[V];

    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear){
        int curr = queue[front++];
        printf("%d ",curr);

        for(int i=0;i<V;i++){
            if(adj[curr][i] == 1 && visited[i] == 0)
             {
                 visited[i] = 1;
                 queue[rear++] = i;
             }
        }
    }
    
   
}

int main()
{
    int adj[V][V] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };


    BFS(adj, 2);

    return 0;
}