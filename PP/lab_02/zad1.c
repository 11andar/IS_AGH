/*

    1.  W programie mamy tablicę:
        int tab[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,
                       8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11, 21,9,12,5,3,9};
        oraz procedurę
        
        void swap(int*a, int*b){
            int temp = *a;
            *a = *b;
            *b = temp;
            return;
        }

        Proszę
        ( 1 ) napisać funkcję ........find_min_ind (int *, int ) , zwracającą indeks elementu minimalnego w zakresie tablicy przekazanej do funkcji

        ( 1 ) dla każdej 10-ki elementów z tablicy tab proszę w funkcji main wypisać elementy procedurą wypisz_i, oraz wykorzystując funkcję find_min_ind znaleźć element najmniejszy i wypisać jego adres, indeks (w ramach tablicy tab) i wartość

        ( 2 ) napisać procedurę zgodną z prototypem void sort (int *, int *);, w której zostaną wykorzystane funkcje swap oraz find_min_ind sortującą rosnąco tablicę w zakresie przekazanym do funkcji

        ( 1 ) przy użyciu procedury sort posortować każdą 10-kę elementów z tablicy tab_A , i wypisac całą tablicę procedurą wypisz_i.

*/

#include <stdio.h>

void swap(int *a, int *b);
int find_min_ind(int *tab, int size);
void wypisz_i(int *beg, int *end);
void sort(int *beg, int *end);

int main()
{
    int tab[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,
                 8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};

    // calculate the size of tab
    int size = sizeof(tab)/sizeof(int);

    // find min value index in tab
    printf("Min value index: %d\n\n", find_min_ind(tab, size));

    // print every 10 elements of tab
    int elements = 10;
    for(int i = 0; i < size; i+=elements)
    {
        wypisz_i(tab+i, tab+i+elements);
        // find min element and print:
        // address
        printf("Adress: %p\n", tab+i+find_min_ind(tab+i, elements));
        // index in tab 
        printf("Index in tab: %d\n",i+find_min_ind(tab+i, elements));
        // value
        printf("Value: %d\n", *(tab+i+find_min_ind(tab+i, elements)));
        
        printf("\n");

        // sort every 10 elements in tab
        sort(tab+i, tab+i+elements);
    }

    // print sorted tab
    printf("\t==== TAB WITH SORTED ROWS ====\n");
    for(int i = 0; i < size; i+=elements)
    {
        wypisz_i(tab+i, tab+i+elements);
    }
    
    return 0;
}

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_min_ind(int *tab, int size)
{   
    int min = *tab;
    int index = 0;

    for(int i = 0; i < size; i++)
    {
        // find min value
        if(*(tab+i) < min)
        {
            min = *(tab+i);
            index = i;
        }
    }

    return index;
}

void wypisz_i(int *beg, int *end) 
{
    while (beg < end)
        printf("%4d ", *beg++);
    printf("\n");
}

void sort(int *beg, int *end)
{
    int size = end-beg;
    for(int i = 0; i < size; i++)
    {
        // find address of min value
        int *min_ad = beg+i+find_min_ind(beg+i, size-i);
        // place min value at the beggining
        swap(min_ad, beg+i);
    }
}
