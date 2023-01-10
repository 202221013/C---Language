#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reinit_ary(int a[][10], int b[][10]);
void print_ary(int a[][10]);


int main()
{
    int a[10][10] = { 0 };
    int b[10][10] = { 0 };

    reinit_ary(a, b);
    print_ary(a);
    print_ary(b);

    return 0;
}

void reinit_ary(int a[][10], int b[][10])
{
    int number, xc, yc;
    srand((unsigned)time(NULL));


    for (int i = 0; i < 100; i++)
    {
        int x = rand() % 10;
        int y = rand() % 10;
        xc = x;
        yc = y;
        printf("(x , y) = (%d, %d)\n ", xc, yc);
        number = rand() % 100 + 1;
        printf("result = %d\n", number);

        a[xc][yc] = number;

        if (a[xc][yc] >= 1)
        {
            b[xc][yc] += 1;
        }
    }
}

void print_ary(int a[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%3d", a[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");
}