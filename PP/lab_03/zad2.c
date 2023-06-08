/*

    2. ( 2 ) Proszę napisać program , w którym będzie zaalokowana pamięć na dynamiczną tablicę liczb całkowitych table o rozmiarze
             podanym przez użytkownika, potem należy wypełnić ją liczbami losowymi z zakresu (-5, 5),a następnie jej elementy przepisać na dwie tablice dynamiczne: 
             
             - elementy parzyste do tablicy arg_e (przyjmujemy, że zero jest parzyste)
             - elementy nieparzyste do tablicy arg_o 
             
             Wszystkie tablice wypisujemy procedurą print_i(w wywołaniach nie używamy operatora &)
             
             UWAGA
             
             Tablice arg_e oraz arg_o mają "rosnąć" wraz z dodawaniem do nich elementów
             przykład dla n = 7
             
             int table -> -3, 0, 4, 3, -1, 1, 2,
             int arg_e -> 0, 4, 2,
             int arg_o -> -3, 3, -1,

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fill(int *tab, int size);
void print_arr(int *tab, int size);

int main(void)
{
    int size;
    int even = 0;
    int odd = 0;

    // get size of an array 
    printf("Array size: ");
    scanf("%d", &size);
    
    // allocate memory
    int *tab = malloc(size*sizeof(int));

    // initialize array with random values [-5, 5]
    fill(tab, size);

    // check how many even and odd numbers
    for(int i = 0; i < size; i++)
    {
        if(tab[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    // allocate memory for arg_e and arg_o
    int *arg_e = malloc(even*sizeof(int));
    int *arg_o = malloc(odd*sizeof(int));

    // fill arg_e and arg_o
    for(int i=0, j=0, k=0; i<size, j<even, k<odd; i++)
    {
        if(tab[i] % 2 == 0)
        {
            arg_e[j] = tab[i];
            j++;
        }
        else
        {
            arg_o[k] = tab[i];
            k++;
        }
    }    
    
    // print tab
    printf("tab -> ");
    print_arr(tab, size);
    
    // print arg_e and arg_o
    printf("arg_e -> ");
    print_arr(arg_e, even);
    
    printf("arg_o -> ");
    print_arr(arg_o, odd);

    // free memory
    free(tab);
    free(arg_e);
    free(arg_o);
    
    return 0;
}

void fill(int *tab, int size)
{
   srand(time(NULL));
   for(int i = 0; i < size; i++)
        tab[i] = rand()%11 - 5;
    printf("\n");
}

void print_arr(int *tab, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}