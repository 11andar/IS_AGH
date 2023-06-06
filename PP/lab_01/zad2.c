/*

2. Proszę napisać oraz przetestować procedurę ..... swap(..., ....) , która zamieni wartości przekazanych jej argumentów.
    a. W funkcji main(), utwórz dwie zmienne i zamień ich wartości przy użyciu procedury swap().
    b. Napisz procedurę ..... flip(..., ....) przeznaczoną do odwrócenia jednowymiarowej tablicy. 
       Zastosuj w niej procedurę swap().
    c. Napisz procedurę ..... change_arrs(......., ........, ......) do wymiany zawartości dwóch jednowymiarowych tablic. 
       Zastosuj  w niej procedurę swap()

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(float *a, float *b);
float f_rand(float min, float max);
void init(float *tab, const int size);
void print_arr(float *tab, const int size);
void flip(float *tab, const int size);
void change_arrs(float *tab, float *tab_1, const int size);

int main() 
{
    // initialize variables
    float a = 4.37f;
    float b = 21.20f;
    const int size = 9;
    
    // declare arrays
    float tab[size];
    float tab_1[size];


    // print before swapping
    printf("---- Before swapping ----\n");
    printf("a = %.2f \t b = %.2f\n", a, b);

    // swap variables
    swap(&a,&b);

    // print after swapping
    printf("\n---- After swapping ----\n");
    printf("a = %.2f \t b = %.2f\n", a, b);
    printf("\n");

    // initialize arrays with random values
    init(tab, size);
    init(tab_1, size);

    // print tab
    printf("tab -> ");
    print_arr(tab, size);
    
    // flip tab 
    flip(tab, size);

    // print flipped tab
    printf("flipped tab -> ");
    print_arr(tab, size);

    // print both arrays
    printf("\ntab -> ");
    print_arr(tab, size);

    printf("tab_1 -> ");
    print_arr(tab_1, size);

    // swap values btwn arrays
    change_arrs(tab, tab_1, size);

    // print both arrays
    printf("\n---- After swaping values btwn arrays ----\n\n");
    printf("tab -> ");
    print_arr(tab, size);

    printf("tab_1 -> ");
    print_arr(tab_1, size);

    return 0;
}

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

float f_rand(float min, float max)
{
    float r = (float)rand()/RAND_MAX;

    return r*(max-min) + min;
}

void init(float *tab, const int size)
{
    
    for(int i = 0; i < size; i++)
    {
        *(tab+i) = f_rand(0.0, 10.0);
    }

}

void print_arr(float *tab, const int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%f ", *(tab+i));
    }
    printf("\n");
}

void flip(float *tab, const int size)
{
    int i = 0;
    while(i < size/2)
    {
        swap(tab+i, tab+size-i-1);
        i++;
    }
}

void change_arrs(float *tab, float *tab_1, const int size)
{
    for(int i = 0; i < size; i++)
    {
        swap(tab+i, tab_1+i);
    }
}