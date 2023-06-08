#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 4

void print_d(double *beg, double *end);

int main(void)
{
    // declare abc
    double abc[ROWS][COLS];

    // initialize abc with random values [-10, 10]
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            abc[i][j] = (double) rand()/RAND_MAX*20 - 10;
        }
    }

    // print abc row by row
    for(int i = 0; i < ROWS; i++)
        print_d(*(abc+i), *(abc+i)+COLS);
    
    return 0;
}

void print_d(double *beg, double *end)
{
    while(beg < end)
        printf ("%6.1f,", *beg++);
    printf ("\n");
}