/*

    2. ( 2 ) Proszę napisać i przetestować funkcję (wypisać wartości przykładowych zmiennych oraz otrzymany wynik), która przyjmuje jako parametry 
             2 wskaźniki na liczby całkowite i oblicza wartość bezwzględną z ilorazu wartości, na które wskazują te wskaźniki. Funkcja ma zwrócić 
             wskaźnik na zmienną przechowującą tak otrzymaną wartość. 
             
             Wypisywanie wartości odbywa się wyłącznie w funkcji main.

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double *fun(const int *a, const int *b);

int main(void)
{
    int n1, n2;
    
    printf("Number 1: ");
    scanf("%d", &n1);

    printf("Number 2: ");
    scanf("%d", &n2);

    double *outcome = fun(&n1, &n2);
    
    printf("|N1/N2| = %.2f\n", *outcome);

    free(outcome);
    
    return 0;
}

double *fun(const int *a, const int *b)
{
    double *abs = malloc(sizeof(double)); 
    
    *abs = fabs((double)*a / *b); 

    return abs;
}