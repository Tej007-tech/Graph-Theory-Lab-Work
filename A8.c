// Objective: To determine the dominating set and domination number of a graph. 
// Problem: Write a program to: 
// 1. Find dominating sets 
// 2. Find domination number 
// 3. Find total dominating sets 
// 4. Find total domination number 
// Input: N = 4, M = 4, Edges = {(1,2), (1,3), (3,4), (2,4)} 
// Output: 
// Possible Dominating Sets: 
// {1,4} 
// {2,3} 
// {1,2} 
// {1,3} 
// {2,4} 
// {3,4} 
// Domination Number = 2 
// Total Dominating Sets: {1,3} {2,4} 
// Total Domination Number = 2 

#include <stdio.h>

int main()
{
    int N = 4;
    int M = 4;

    int edges[4][2] = {
        {1, 2},
        {1, 3},
        {3, 4},
        {2, 4}
    };

    int graph[4][4] = {0};

    int i, j, k;
    int mask;

    int dominationNumber = N + 1;
    int totalDominationNumber = N + 1;

   
    for(i = 0; i < M; i++)
    {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

   
    printf("Possible Dominating Sets:\n");

    for(mask = 1; mask < (1 << N); mask++)
    {
        int dominated[4] = {0};
        int setSize = 0;
        int isDominating = 1;

        for(i = 0; i < N; i++)
        {
            if(mask & (1 << i))
            {
                setSize++;

                dominated[i] = 1;

                for(j = 0; j < N; j++)
                {
                    if(graph[i][j] == 1)
                    {
                        dominated[j] = 1;
                    }
                }
            }
        }

        for(i = 0; i < N; i++)
        {
            if(dominated[i] == 0)
            {
                isDominating = 0;
                break;
            }
        }

        if(isDominating)
        {
            printf("{");

            for(i = 0; i < N; i++)
            {
                if(mask & (1 << i))
                {
                    printf("%d", i + 1);

                    for(k = i + 1; k < N; k++)
                    {
                        if(mask & (1 << k))
                        {
                            printf(",");
                            break;
                        }
                    }
                }
            }

            printf("}\n");

            if(setSize < dominationNumber)
            {
                dominationNumber = setSize;
            }
        }
    }

    printf("Domination Number = %d\n", dominationNumber);


 
    printf("\nTotal Dominating Sets:\n");

    for(mask = 1; mask < (1 << N); mask++)
    {
        int dominated[4] = {0};
        int setSize = 0;
        int isTotalDominating = 1;

        for(i = 0; i < N; i++)
        {
            if(mask & (1 << i))
            {
                setSize++;

              
                for(j = 0; j < N; j++)
                {
                    if(graph[i][j] == 1)
                    {
                        dominated[j] = 1;
                    }
                }
            }
        }

        for(i = 0; i < N; i++)
        {
            if(dominated[i] == 0)
            {
                isTotalDominating = 0;
                break;
            }
        }

        if(isTotalDominating)
        {
            printf("{");

            for(i = 0; i < N; i++)
            {
                if(mask & (1 << i))
                {
                    printf("%d", i + 1);

                    for(k = i + 1; k < N; k++)
                    {
                        if(mask & (1 << k))
                        {
                            printf(",");
                            break;
                        }
                    }
                }
            }

            printf("}\n");

            if(setSize < totalDominationNumber)
            {
                totalDominationNumber = setSize;
            }
        }
    }

    printf("Total Domination Number = %d\n", totalDominationNumber);

    return 0;
}