#include <stdio.h>
#include <math.h>

#define MAX 10

int main()
{
    int n, choice;
    double A[MAX][MAX], L[MAX][MAX];
    double eigenvalue[MAX], eigenvector[MAX][MAX];
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\n1. Adjacency Matrix");
    printf("\n2. Laplacian Matrix");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                L[i][j] = A[i][j];
            }
        }
    }
    else
    {

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    double degree = 0;

                    for (k = 0; k < n; k++)
                        degree += A[i][k];

                    L[i][j] = degree;
                }
                else
                {
                    L[i][j] = -A[i][j];
                }
            }
        }
    }

    printf("\nMatrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%8.2lf", L[i][j]);
        }
        printf("\n");
    }

   

    if (n == 2)
    {
        double trace, determinant, d;

        trace = L[0][0] + L[1][1];

        determinant = L[0][0] * L[1][1]
                    - L[0][1] * L[1][0];

        d = sqrt(trace * trace - 4 * determinant);

        eigenvalue[0] = (trace + d) / 2;
        eigenvalue[1] = (trace - d) / 2;

        printf("\nEigenvalues:\n");

        printf("λ1 = %.4lf\n", eigenvalue[0]);
        printf("λ2 = %.4lf\n", eigenvalue[1]);

        printf("\nCorresponding Eigenvectors:\n");

        for (i = 0; i < 2; i++)
        {
            double lambda = eigenvalue[i];

            if (fabs(L[0][1]) > 0.0001)
            {
                eigenvector[0][i] = 1;
                eigenvector[1][i] =
                    -(L[0][0] - lambda) / L[0][1];
            }
            else
            {
                eigenvector[0][i] = 0;
                eigenvector[1][i] = 1;
            }

            printf("For λ = %.4lf : (%.4lf, %.4lf)\n",
                   lambda,
                   eigenvector[0][i],
                   eigenvector[1][i]);
        }
    }
    else
    {
        printf("\nThis simple program supports 2 x 2 matrices.\n");
        printf("For larger matrices, numerical methods/library are required.\n");
    }

    return 0;
}