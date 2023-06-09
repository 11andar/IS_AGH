#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 4

void print_d(double *beg, double *end);
double sum(double *beg, double *end);

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

    // calculate sum
    double sum_all = sum(*abc, *(abc+ROWS));

    // calculate sum_1 (sum of the first half)
    int half = ROWS*COLS/2;
    int rows_h = half/ROWS;
    int cols_h = half%COLS;

    
    double sum_1 = sum(*abc, *(abc+rows_h)+cols_h);

    // calculate sum_2(sum of the second half)
    double sum_2 = sum(*(abc+rows_h)+cols_h, *(abc+ROWS));
    
    // print sum, sum_1, sum_2
    printf("Sum of all elements: %.1f\n", sum_all);
    printf("Sum of first half: %.1f\n", sum_1);
    printf("Sum of first half: %.1f\n", sum_2);
    
    return 0;
}

void print_d(double *beg, double *end)
{
    while(beg < end)
        printf ("%6.1f,", *beg++);
    printf ("\n");
}

double sum(double *beg, double *end)
{
    double sum_all = 0;

    while(beg < end)
    {
        sum_all += *beg;
        beg++;
    }

    return sum_all;
}
