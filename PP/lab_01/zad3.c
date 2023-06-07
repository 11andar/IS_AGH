/*

    3.  Proszę napisać funkcję, która będzie zwracać w wyniku sumę elementów tablicy t[n] liczb całkowitych, 
        oraz pozwoli wypisać w funkcji main():
        - wartość minimalną i maksymalną, 
        - wartość średnią jej elementów,
        - maksymalne i minimalne odchylenie od wartości średniej (wartość bezwzględna funkcja fabs)

        Prototyp funkcji int suma (int *t, int n, ????);

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int sum(int *tab, int n);
void init(int *tab, int size);
void print_arr(int *tab, int size);

int main()
{
    int size = 10;
    
    // allocate memory for an array
    int *tab = malloc(size*sizeof(int));
    
    // initialize array with random values
    init(tab, size);

    // print array
    printf("tab -> ");
    print_arr(tab, size);

    // print sum
    printf("Sum: %d\n", sum(tab, size));

    // free memory
    free(tab);

    return 0;
}

int sum(int *tab, int n)
{
    int sum = 0;
    int min = *tab;
    int max = *tab;
    double avrg = 0;
    double max_dev = 0;
    double min_dev = 0;

    for(int i = 0; i < n; i++)
    {
        // find min value
        if(*(tab+i) < min)
            min = *(tab+i);
        
        // find max value
        else if(*(tab+i) > max)
            max = *(tab+i);    

        // calculate sum
        sum += *(tab+i);
    }

    // calculate avrg
    avrg = (double)sum/n;

    // calculate max and min deviation from avrg
    max_dev = (double)fabs(max - avrg);
    min_dev = (double)fabs(min - avrg);

    // print results
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Average: %.2f\n", avrg);
    printf("Min deviation: %.2f\n", min_dev);
    printf("Max deviation: %.2f\n", max_dev);

    // return sum
    return sum;
}

void init(int *tab, int size)
{
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        *(tab+i) = rand() % 11;
    }
}

void print_arr(int *tab, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(tab+i));
    }
    printf("\n");
}