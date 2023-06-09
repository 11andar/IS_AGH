/*

4. W funkcji main proszę utworzyć dwuwymiarową tablicę liczb całkowitych abc o pięciu wierszach i pięciu kolumnach
( 0.5 ) Proszę napisać procedurę, która dowolną tablicę dwuwymiarową o pięcioelementowych wierszach wypełnia wartościami w taki sposób, że w i-tym wierszu elementy otrzymują wartość i. Procedurę proszę
przetestować na tablicy abc, a następnie wypisać według wzoru poniżej

TAB[0][0] = 0, TAB[0][1] = 0, TAB[0][2] = 0, TAB[0][3] = 0, TAB[0][4] = 0
TAB[1][0] = 1, TAB[1][1] = 1, TAB[1][2] = 1, TAB[1][3] = 1, TAB[1][4] = 1
TAB[2][0] = 2, TAB[2][1] = 2, TAB[2][2] = 2, TAB[2][3] = 2, TAB[2][4] = 2
TAB[3][0] = 3, TAB[3][1] = 3, TAB[3][2] = 3, TAB[3][3] = 3, TAB[3][4] = 3
TAB[4][0] = 4, TAB[4][1] = 4, TAB[4][2] = 4, TAB[4][3] = 4, TAB[4][4] = 4

( 1 ) Wykonać transponowanie tablicy abc - czyli zamienić wiersze z kolumnami, w ramach jednej tablicy wykorzystując funkcję swap (w wywołaniu funkcji nie używamy operatora &) i wypisać według wzoru poniżej
TAB[0][0] = 0, TAB[0][1] = 1, TAB[0][2] = 2, TAB[0][3] = 3, TAB[0][4] = 4
TAB[1][0] = 0, TAB[1][1] = 1, TAB[1][2] = 2, TAB[1][3] = 3, TAB[1][4] = 4
TAB[2][0] = 0, TAB[2][1] = 1, TAB[2][2] = 2, TAB[2][3] = 3, TAB[2][4] = 4
TAB[3][0] = 0, TAB[3][1] = 1, TAB[3][2] = 2, TAB[3][3] = 3, TAB[3][4] = 4
TAB[4][0] = 0, TAB[4][1] = 1, TAB[4][2] = 2, TAB[4][3] = 3, TAB[4][4] = 4

( 0.5 ) Wypisać wartości, które znajdują się bezpośrednio nad przekątną - liczy się prostota wykonania

*/

#include <stdio.h>
#define ROWS 5
#define COLS 5

void fill(int (*tab)[COLS]);
void print_a(int (*tab)[COLS]);
void transpose(int (*tab)[COLS]);
void print_od(int (*tab)[COLS]);

int main(void)
{
    // declare abc array
    int abc[ROWS][COLS];

    // fill abc
    fill(abc);

    // print abc
    print_a(abc);
    
    printf("\n");

    // transpose abc
    transpose(abc);

    // print abc
    print_a(abc);

    printf("\n");

    // print values over diagonal
    print_od(abc);

    return 0;
}

void fill(int (*tab)[COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            tab[i][j] = i;
        }
    }
}

void print_a(int (*tab)[COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("TAB[%d][%d] = %d\t", i, j, tab[i][j]);
        }
        printf("\n");
    }
}

void transpose(int (*tab)[COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = i; j < COLS; j++)
        {
            int temp = tab[i][j];
            tab[i][j] = tab[j][i];
            tab[j][i] = temp;
        }
    }
}

void print_od(int (*tab)[COLS])
{
    for(int i = 0; i < ROWS-1; i++)
        printf("TAB[%d][%d] = %d\n", i, i+1, tab[i][i+1]);
}