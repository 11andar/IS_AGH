/*

    3. ( 2 ) Wykorzystując funkcję suma proszę napisać funkcję (bez użycia operatora &) .......tab_avg(......, ...........);, 
             która dla tablicy dwuwymiarowej o wierszach COLS-elementowych (argumentu wywołania funkcji) zwróci tablicę przechowującą wartości średnie z poszczególnych wierszy tablicy, dla której funkcja została wywołana.
    
             W funkcji main należy:
             
            a) ( 0.5 ) utworzyć przykładową tablicę TAB dwuwymiarową typu integer - ilość kolumn oraz ilość wierszy należy określić za pomocą dyrektywy #define.
             
                Tablicę wypełnić liczbami losowymi z zakresu <-5, 5>, następnie wypisać wierszami procedurą wypisz_i (w wywołaniach nie używamy operatora &)
             
            b) ( 1.5 ) dla utworzonej tablicy TAB wywołać funkcję tab_avg i wypisać uzyskaną tablicę średnich odpowiednią procedurą 
                (w wywołaniach nie używamy   operatora &)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 6

void wypisz_i(int *beg, int *end);

int main(void)
{
    // declare TAB
    int TAB[ROWS][COLS];

    // fill TAB with random values [-5, 5]
    srand(time(NULL));
    
    for(int *ptr = *TAB; ptr < *(TAB+ROWS-1)+COLS-1; ptr++)
        *ptr = rand()%11 - 5;

    // print TAB row by row usnig wypisz_i
    for(int i = 0; i < ROWS; i++)
        wypisz_i(*(TAB+i), *(TAB+i)+COLS);
    
    return 0;
}

void wypisz_i(int *beg, int *end)
{
    while (beg < end)
        printf ("%4d ", *beg++);
    printf ("\n");
}