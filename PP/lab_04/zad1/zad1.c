#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_f(float *beg, float *end);
void print_arr(float *tab, int size);
void print_ptr(float **tab, int size);
void swap(float *a, float *b);
void swap_ptr(float **a, float **b);

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

    // print TAB_1 without using int variable
    printf("\n==== TAB_1 ====\n");
    
    for(PTR = TAB_1; PTR < TAB_1+size; PTR++)
        printf("%p\n", *PTR);
    
    printf("\n");

    // move TAB_2 one up using PTR and PTR_1
    for(PTR = TAB_1, PTR_1 = PTR+1; PTR < TAB_1+size-1; PTR++, PTR_1++)
        swap(*PTR, *PTR_1);

    // print TAB_2 and TAB_1
    printf("\nTAB_2 -> ");
    print_arr(TAB_2, size);

    printf("\n==== TAB_1 ====\n");
    print_ptr(TAB_1, size);
    
    printf("\n");

    // flip values of TAB_1 using PTR and PTR_1
    PTR_1 = TAB_1;
    
    while(PTR_1 != PTR)
    {
        swap_ptr(PTR_1, PTR);
        PTR_1++;
        PTR--;
    }

    // print TAB_2 using TAB_1
    printf("\nTAB_2 (TAB_1) -> ");
    for(int i = 0; i < size; i++)
        printf("%.2f ", *(*(TAB_1+i)));
    
    printf("\n");

    // print TAB_2 using wypisz_f
    printf("TAB_2 (wypisz_f) -> ");
    wypisz_f(TAB_2, TAB_2+size);

    // print TAB_1
    printf("\n==== TAB_1 ====\n");
    print_ptr(TAB_1, size);
    
    printf("\n");

    return 0;
}

void wypisz_f (float *beg, float *end)
{
    while (beg < end)
        printf ("%6.2f", *beg++);
    printf ("\n");
}

void print_arr(float *tab, int size)
{
    for(int i = 0; i < size; i++)
        printf("%.2f ", *(tab+i));
}

void print_ptr(float **tab, int size)
{
    for(int i = 0; i < size; i++)
        printf("%p\n", *(tab+i));
}

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ptr(float **a, float **b)
{
    float *temp = *a;
    *a = *b;
    *b = temp;
}