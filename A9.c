#include <stdio.h>

int main()
{
    int n = 4, m = 4;
    int edges[4][2] = {
        {1, 2},
        {1, 3},
        {3, 4},
        {2, 4}
    };

    int adj[5][5] = {0};
    int i, j, mask;
    int min = n + 1;

    for (i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Total Dominating Sets: ");

    for (mask = 1; mask < (1 << n); mask++)
    {
        int valid = 1;

        for (i = 1; i <= n; i++)
        {
            int dominated = 0;

            for (j = 1; j <= n; j++)
            {
                if (adj[i][j] && (mask & (1 << (j - 1))))
                {
                    dominated = 1;
                    break;
                }
            }

            if (!dominated)
            {
                valid = 0;
                break;
            }
        }

        if (valid)
        {
            int count = 0;

            for (i = 1; i <= n; i++)
            {
                if (mask & (1 << (i - 1)))
                    count++;
            }

            if (count < min)
            {
                min = count;
                printf("\n");

                for (i = 1; i <= n; i++)
                {
                    if (mask & (1 << (i - 1)))
                        printf("%d ", i);
                }
            }
            else if (count == min)
            {
                printf("\n");

                for (i = 1; i <= n; i++)
                {
                    if (mask & (1 << (i - 1)))
                        printf("%d ", i);
                }
            }
        }
    }

    printf("\n\nTotal Domination Number = %d\n", min);

    return 0;
}