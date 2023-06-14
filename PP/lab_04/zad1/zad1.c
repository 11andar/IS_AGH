#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_f(float *beg, float *end);

int main(void) 
{
    int size = 7;

    // declare arrays
    float *TAB_1[size];
    float TAB_2[size];

    // initialize TAB_1 and TAB_2
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {    
        TAB_2[i] = ((float) rand()/RAND_MAX) * (10.0);
        TAB_1[i] = TAB_2+i;
    }

    // define pointers
    float **PTR = TAB_1;
    float **PTR_1 = TAB_1;

    // print TAB_2 using PTR and wypisz_f
    printf("TAB_2 -> ");
    wypisz_f(*PTR, *PTR+size);
    printf("\n");

    // print TAB_1 without using int variable
    printf("==== TAB_1 ====\n");
    
    for(PTR = TAB_1; PTR < TAB_1+size; PTR++)
        printf("%p\n", *PTR);
    printf("\n");

    return 0;
}

void wypisz_f (float *beg, float *end)
{
    while (beg < end)
        printf ("%6.2f", *beg++);
    printf ("\n");
}