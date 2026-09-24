//  Objective: To analyze the structural properties of a connected graph using spanning trees, branches, chords, 
// rank, and nullity. 
// Problem 1: In a social network of N people, some of them are directly connected as friends. If person A is a friend 
// of person B, and person B is a friend of person C, then A, B, and C are all part of the same friend circle (a connected 
// component in graph terms). You are given an undirected graph represented by an adjacency matrix of size N x N, 
// where matrix[i][j] = 1 indicates a direct friendship between person i and person j.  
// Your task is to determine the total number of friend circles. 
// Input: 
// 4 // total N people  
// 1 1 0 0 // adj. Matrix 
// 1 1 0 0 
// 0 0 1 1 
// 0 0 1 1 
// Output:5

// #include <stdio.h>

// #define V 4

// int visited[V];

// void dfs(int graph[V][V], int node)
// {
//     visited[node] = 1;

//     for (int i = 0; i < V; i++)
//     {
//         if (graph[node][i] == 1 && visited[i] == 0)
//         {
//             dfs(graph, i);
//         }
//     }
// }

// int main()
// {
//     int adj[V][V] =
//     {
//         {1,0,0,0},
//         {0,1,0,0},
//         {0,0,1,0},
//         {0,0,0,1}
//     };

//      int count = 0;

//     for (int i = 0; i < V; i++)
//     {
//         if (visited[i] == 0)
//         {
//             dfs(adj, i);
//             count++;
//         }
//     }

//     printf("%d",count);

//     return 0;
// }


// Problem 2: Write a program to perform the following operations on a connected graph: 
// 1. Construct a spanning tree of the graph.  
// 2. Identify all branches and chords.  
// 3. Find all fundamental circuits 
// 4. Calculate: Rank and Nullity of the graph  
// 5. Verify that: Number of branches = Rank and Number of chords = Nullity. 
// Input:  
// Enter number of vertices: 5 
// Enter number of edges: 6 
// edges[][] = {(0,1),(0,2),(1,2),(1,3),(2,4),(3,4)} 
// Output:  
// Branches: 
// (0,1) 
// (0,2) 
// (1,3) 
// (2,4) 
// Chords: 
// (1,2) 
// (3,4) 
// Fundamental Circuits: C1 = {(0,1),(0,2),(1,2)} C2 = {(1,3),(2,4),(3,4)}  
// Rank of Graph = 4 
// Nullity of Graph = 2 
 

#include <stdio.h>

#define V 5
#define E 6


int edges[E][2] = {
    {0,1},
    {0,2},
    {1,2},
    {1,3},
    {2,4},
    {3,4}
};


int adj[V][V];


int visited[V];
int parent[V];


int branch[E][2];
int branchCount = 0;


int chord[E][2];
int chordCount = 0;

//----------------------------------
// Create Adjacency Matrix
//----------------------------------
void createGraph()
{
    for(int i=0;i<E;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][v]=1;
        adj[v][u]=1;
    }
}


void DFS(int u)
{
    visited[u]=1;

    for(int v=0;v<V;v++)
    {
        if(adj[u][v] && !visited[v])
        {
            parent[v]=u;

            branch[branchCount][0]=u;
            branch[branchCount][1]=v;
            branchCount++;

            DFS(v);
        }
    }
}


int isBranch(int u,int v)
{
    for(int i=0;i<branchCount;i++)
    {
        if((branch[i][0]==u && branch[i][1]==v) ||
           (branch[i][0]==v && branch[i][1]==u))
            return 1;
    }
    return 0;
}


void findChords()
{
    for(int i=0;i<E;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        if(!isBranch(u,v))
        {
            chord[chordCount][0]=u;
            chord[chordCount][1]=v;
            chordCount++;
        }
    }
}


void printPath(int u)
{
    while(parent[u]!=-1)
    {
        printf("(%d,%d) ",parent[u],u);
        u=parent[u];
    }
}


int main()
{
    createGraph();

    for(int i=0;i<V;i++)
    {
        visited[i]=0;
        parent[i]=-1;
    }

    DFS(0);

    printf("Branches (Spanning Tree):\n");
    for(int i=0;i<branchCount;i++)
    {
        printf("(%d,%d)\n",branch[i][0],branch[i][1]);
    }


    findChords();

    printf("\nChords:\n");
    for(int i=0;i<chordCount;i++)
    {
        printf("(%d,%d)\n",chord[i][0],chord[i][1]);
    }

    printf("\nFundamental Circuits:\n");

    for(int i=0;i<chordCount;i++)
    {
        int u=chord[i][0];
        int v=chord[i][1];

        printf("C%d = ",i+1);

        printPath(u);
        printPath(v);

        printf("(%d,%d)",u,v);

        printf("\n");
    }

    
    int rank=V-1;
    int nullity=E-rank;

    printf("\nRank of Graph = %d\n",rank);
    printf("Nullity of Graph = %d\n",nullity);


    printf("\nVerification:\n");

    if(branchCount==rank)
        printf("Branches = Rank (%d = %d) Verified\n",branchCount,rank);
    else
        printf("Branches != Rank\n");

    if(chordCount==nullity)
        printf("Chords = Nullity (%d = %d) Verified\n",chordCount,nullity);
    else
        printf("Chords != Nullity\n");

    return 0;
}