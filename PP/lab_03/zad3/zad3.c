#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 4

void print_d(double *beg, double *end);
double sum(double *beg, double *end);
int row_number(double *beg, double *end);
double *find_min_ptr(double *beg, double *end);
double *fun_find(double (*tab)[COLS], int rows);

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
    printf("\n");

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
    printf("Sum of first half: %.1f\n\n", sum_2);
    
    // print max value and row containing it
    int max_row = row_number(*abc, *(abc+ROWS));

    printf("Row with max value: ");
    print_d(*(abc+max_row), *(abc+max_row)+COLS);
    printf("\n");

    // get a pointer to min value in abc
    double *min_ptr = fun_find(abc, ROWS);

    // print min value
    printf("min: %.1f\n", *min_ptr);
    
    // print row and column of min value
    printf("min_row: %ld\n", (min_ptr-*abc)/COLS);
    printf("min_col: %ld\n", (min_ptr-*abc)%COLS);
    
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

int row_number(double *beg, double *end)
{
    double *max_ptr = beg;
    double *ptr = beg;

    while(ptr < end)
    {
        if(*ptr > *max_ptr)
            max_ptr = ptr;
        ptr++;
    }

    // print max value
    printf("max: %.1f\n", *max_ptr);

    return (max_ptr-beg)/COLS;
}

double *find_min_ptr(double *beg, double *end)
{
    double *min = beg++;

    while(beg < end)
    {
        if(*min > *beg) 
            min = beg;
        beg++;
    }
    
    return min;
}

double *fun_find(double (*tab)[COLS], int rows)
{
    double *min_ptr = *tab;
    
    for(int i = 0; i < rows; i++)
    {
        double *min_in_row = find_min_ptr(*(tab+i), *(tab+i)+COLS);
        
        if(*min_in_row < *min_ptr)
            min_ptr = min_in_row;
    }

    return min_ptr;
}
