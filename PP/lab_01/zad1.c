/*
    1.Proszę dokończyć program nie używając operatora tablicowego [ ]

*/

#include <stdio.h>
#define N 10

int suma(const int* tab, const int size);

int main(void)
{

    //deklaracja tablicy 10 liczb całkowitych, użyj N
    int* tab = malloc(N*sizeof(int));

    //deklaracja wskaźnika p do liczby całkowitej, użyj NULL
    int* p = NULL;

    //nie używaj zmiennej int do indeksowania tablicy
    //przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od 7 do 35 i wypisz je na ekran

    srand(time(NULL));

    for(p = tab; p < tab + N ; p++) 
    {
        *p = rand()%29 + 7; // nie korzystaj z tab

        //oblicz wartość indeksu kolejnych elementów tablicy, wypisz wartości kolejnych elementów używając p
        printf("p[%d] = %d\n", p-tab, *p);
    }

    printf("\n");

    //oblicz rekurencyjnie sumę elementów tablicy.
    int sum = suma(tab, p-tab); //nie używaj N
    
    printf("sum = %d\n", sum);

    free(tab);
    
    return 0;
}

//funkcja rekurencyjna liczaca sume elementów tablicy
int suma (const int* tab, const int size) //nie używaj N
{ 
    if(size > 0)
        return *(tab+size-1) + suma(tab, size-1);
    else
        return 0;
}