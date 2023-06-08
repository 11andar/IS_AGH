/*

    1. ( 2 ) Proszę zadeklarować dwie tablice liczb rzeczywistych A_1[8][6] oraz A_2[10][6] .
             
             Następnie proszę napisać procedurę fill(..........., ...........) wypełniającą tablicę dwuwymiarową liczbami rzeczywistymi od -1.5 z krokiem 0.4, tak, aby wywołanie procedury dla naszych tablic wyglądało następująco :
             
             - dla tablicy A_1 wywołanie wypelnij (A_1, 8);
             - dla tablicy A_2 wywołanie wypelnij (A_2, 10);
             
             Potem proszę wypisać każdą tablicę na dwa sposoby, za każdym razem wykorzystując procedurę print_d 
             (w wywołaniach nie używamy operatora &):
             
             - jednym wywołaniem cała tablica
             - dla każdego wiersza osobne wywołanie procedury

*/

#include <stdio.h>
#define COLS 6

void fill(double (*tab)[COLS], int ROWS);
void print_d(double *beg, double *end);

int main(void)
{
    // define rows
    int rows_1 = 8;
    int rows_2 = 10;
    
    // declare arrays
    double A_1[rows_1][COLS];
    double A_2[rows_2][COLS];

    // initialize arrays
    fill(A_1, rows_1);
    fill(A_2, rows_2);

    // print arrays with one call for each using print_d()
    // indexes rows_1 and rows_2 are out of boundries of an array
    printf(" ==== A_1 ====\n");
    print_d(*A_1, *(A_1+rows_1-1)+COLS);
    
    printf("\n");

    printf(" ==== A_2 ====\n");
    print_d(*A_2, *(A_2+rows_2-1)+COLS);

    // print arrays row by row using print_d()
    printf("\n\t\t==== A_1 ====\n");
    
    for(int i = 0; i < rows_1; i++)
        print_d(*(A_1+i), *(A_1+i)+COLS);
    

    printf("\n\t\t==== A_2 ====\n");
    
    for(int i = 0; i < rows_2; i++)
        print_d(*(A_2+i), *(A_2+i)+COLS);

    return 0;
}

void fill(double (*tab)[COLS], int ROWS)
{
    double d = -1.5;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            tab[i][j] = d;
            d += 0.4;
        }
    }
}

void print_d(double *beg, double *end)
{
    while(beg < end)
        printf ("%6.1f,", *beg++);
    printf ("\n");
}