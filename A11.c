#include <stdio.h>

int graph[4][4] = {
    {1, 1, 0, 0},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {0, 0, 1, 1}
};

int subsets[15][4] = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},

    {1,1,0,0},
    {1,0,1,0},
    {1,0,0,1},
    {0,1,1,0},
    {0,1,0,1},
    {0,0,1,1},

    {1,1,1,0},
    {1,1,0,1},
    {1,0,1,1},
    {0,1,1,1},

    {1,1,1,1}
};

int checkHallsCondition()
{
    int i, j, k;
    int leftCount, rightCount;
    int used[4];

    for(i = 0; i < 15; i++)
    {
        leftCount = 0;

        for(j = 0; j < 4; j++)
        {
            if(subsets[i][j] == 1)
            {
                leftCount++;
            }
        }

        for(j = 0; j < 4; j++)
        {
            used[j] = 0;
        }

        for(j = 0; j < 4; j++)
        {
            if(subsets[i][j] == 1)
            {
                for(k = 0; k < 4; k++)
                {
                    if(graph[j][k] == 1)
                    {
                        used[k] = 1;
                    }
                }
            }
        }

        rightCount = 0;

        for(j = 0; j < 4; j++)
        {
            if(used[j] == 1)
            {
                rightCount++;
            }
        }

        
        if(rightCount < leftCount)
        {
            return 0;
        }
    }

   
    return 1;
}

int main()
{
    int ans;

    ans = checkHallsCondition();

    if(ans == 1)
    {
        printf("Hall's condition is satisfied\n");
    }
    else
    {
        printf("Hall's condition is not satisfied\n");
    }

    return 0;
}