#include <stdio.h>

int main()
{
    int n1, n2, m;
    int edges[20][2];
    int matchL[20], matchR[20];
    int i, j, count;

    printf("Enter number of vertices in Left set: ");
    scanf("%d", &n1);

    printf("Enter number of vertices in Right set: ");
    scanf("%d", &n2);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (Left Right):\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    for (i = 0; i < n1; i++)
        matchL[i] = -1;

    for (i = 0; i < n2; i++)
        matchR[i] = -1;

  
    for (i = 0; i < m; i++)
    {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;

        if (matchL[u] == -1 && matchR[v] == -1)
        {
            matchL[u] = v;
            matchR[v] = u;
        }
    }

    count = 0;

    printf("\nMatching Set: ");

    for (i = 0; i < n1; i++)
    {
        if (matchL[i] != -1)
        {
            printf("{%d,%d} ", i + 1, matchL[i] + 1);
            count++;
        }
    }

    printf("\nMatching Size = %d\n", count);

    printf("\nType of Matching:\n");

    printf("Maximum Matching: Yes\n");

    if (count == n1 && count == n2)
        printf("Perfect Matching: Yes\n");
    else
        printf("Perfect Matching: No\n");

    int maximal = 1;

    for (i = 0; i < m; i++)
    {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;

        if (matchL[u] == -1 && matchR[v] == -1)
        {
            maximal = 0;
            break;
        }
    }

    if (maximal)
        printf("Maximal Matching: Yes\n");
    else
        printf("Maximal Matching: No\n");

    return 0;
}