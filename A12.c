// Objective: To construct different matrices associated with graphs. 
// Problem: Write a program to construct: Adjacency Matrix, Degree Matrix, and Laplacian Matrix 
// Input: N = 5, M = 4, Edges = {(1,2), (2,3), (4,5), (1,5)} 
// Output 
// Adjacency, Degree, and Laplacian matrices. 


#include <stdio.h>

int main()
{
    int N = 5;
    int M = 4;

    int edges[4][2] = {
        {1, 2},
        {2, 3},
        {4, 5},
        {1, 5}
    };

    int adjacency[5][5] = {0};
    int degree[5][5] = {0};
    int laplacian[5][5] = {0};

    int i, j;

    for(i = 0; i < M; i++)
    {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;

        adjacency[u][v] = 1;
        adjacency[v][u] = 1;
    }

    
    for(i = 0; i < N; i++)
    {
        int degreeCount = 0;

        for(j = 0; j < N; j++)
        {
            degreeCount += adjacency[i][j];
        }

        degree[i][i] = degreeCount;
    }

   
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            laplacian[i][j] = degree[i][j] - adjacency[i][j];
        }
    }

   
    printf("Adjacency Matrix:\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", adjacency[i][j]);
        }
        printf("\n");
    }

    printf("\nDegree Matrix:\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", degree[i][j]);
        }
        printf("\n");
    }

    printf("\nLaplacian Matrix:\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", laplacian[i][j]);
        }
        printf("\n");
    }

    return 0;
}