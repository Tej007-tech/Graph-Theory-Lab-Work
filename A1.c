// #include<stdio.h>

// #define N 100

// void createAdjList(int V, int edge[][2], int E, int adj[N][N])
// {
//     for(int i=0; i<E; i++)
//     {
//         int src = edge[i][0];
//         int dest = edge[i][1];

//         for(int j=0; j<N; j++)
//         {
//             if(adj[src][j] == -1)
//             {
//                 adj[src][j] = dest;
//                 break;
//             }
//         }
//     }
// }

// void display(int V, int adj[N][N])
// {
//     for(int i=0; i<V; i++)
//     {
//         printf("%d -> ", i);

//         for(int j=0; j<N; j++)
//         {
//             if(adj[i][j] != -1){
//                 printf("%d ", adj[i][j]);
//             }
//             else{
//                 break;
//             }
//         }

//         printf("\n");
//     }
// }

// int main()
// {
//     int V = 4;
//     int E = 6;

//     int edge[][2] =
//     {
//         {0,1},
//         {1,2},
//         {1,3},
//         {2,3},
//         {3,0},
//         {1,1}
//     };

//     int adj[N][N];


//     for(int i=0; i<N; i++)
//     {
//         for(int j=0; j<N; j++)
//         {
//             adj[i][j] = -1;
//         }
//     }

//     createAdjList(V, edge, E, adj);
//     display(V, adj);

//     return 0;
// }
//  while(front < rear)
//     {
//         int current = queue[front++];

//         printf("%d ", current);

//         for(int i = 0; i < V; i++)
//         {
//             if(adj[current][i] == 1 && visited[i] == 0)
//             {
//                 visited[i] = 1;
//                 queue[rear++] = i;
//             }
//         }
//     }

#include <stdio.h>

int main()
{
    int v, e, src, dest;

    printf("Enter vertices: ");
    scanf("%d", &v);

    int Adj[v][v];

    
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            Adj[i][j] = 0;
        }
    }

    printf("Enter edges: ");
    scanf("%d", &e);

    
    for(int i = 0; i < e; i++)
    {
        printf("Enter src and dest: ");
        scanf("%d %d", &src, &dest);

        Adj[src][dest] = 1;
        Adj[dest][src] = 1;   
    }

    
    
    printf("Final Matrix: \n");
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<v;i++){
        printf("%d -> ",i);
        for(int j=0;j<v;i++){
            if(Adj[i][j] == 1){
                printf("%d ",j);
            }
        }
    }

    for(int i=0;i<v;i++){
        int degree = 0;
        for(int j=0;j<v;i++){
            if(Adj[i][j] == 1){
               degree++;
            }
        }
        // printf("%d - > %d",i,degree);
    }


    return 0;
}