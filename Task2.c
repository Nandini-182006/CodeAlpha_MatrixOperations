#include <stdio.h>

void addMatrix(int r, int c, int a[10][10], int b[10][10]);
void multiplyMatrix(int r1, int c1, int r2, int c2,
                    int a[10][10], int b[10][10]);
void transposeMatrix(int r, int c, int a[10][10]);

int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;
    int choice, i, j;

    printf("===== MATRIX OPERATIONS =====\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");

    printf("Enter Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter Rows and Columns: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter Matrix A:\n");
            for(i = 0; i < r1; i++)
                for(j = 0; j < c1; j++)
                    scanf("%d", &a[i][j]);

            printf("Enter Matrix B:\n");
            for(i = 0; i < r1; i++)
                for(j = 0; j < c1; j++)
                    scanf("%d", &b[i][j]);

            addMatrix(r1, c1, a, b);
            break;

        case 2:
            printf("Enter Rows and Columns of Matrix A: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter Rows and Columns of Matrix B: ");
            scanf("%d%d", &r2, &c2);

            if(c1 != r2)
            {
                printf("Matrix Multiplication Not Possible!\n");
                return 0;
            }

            printf("Enter Matrix A:\n");
            for(i = 0; i < r1; i++)
                for(j = 0; j < c1; j++)
                    scanf("%d", &a[i][j]);

            printf("Enter Matrix B:\n");
            for(i = 0; i < r2; i++)
                for(j = 0; j < c2; j++)
                    scanf("%d", &b[i][j]);

            multiplyMatrix(r1, c1, r2, c2, a, b);
            break;

        case 3:
            printf("Enter Rows and Columns: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter Matrix:\n");
            for(i = 0; i < r1; i++)
                for(j = 0; j < c1; j++)
                    scanf("%d", &a[i][j]);

            transposeMatrix(r1, c1, a);
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}

void addMatrix(int r, int c, int a[10][10], int b[10][10])
{
    int i, j, sum[10][10];

    printf("\nAddition Matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int r1, int c1, int r2, int c2,
                    int a[10][10], int b[10][10])
{
    int i, j, k;
    int mul[10][10];

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            mul[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMultiplication Matrix:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int r, int c, int a[10][10])
{
    int i, j;

    printf("\nTranspose Matrix:\n");

    for(i = 0; i < c; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}