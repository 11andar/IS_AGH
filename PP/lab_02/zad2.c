/*

2. ( 3 )Proszę napisać wykorzystując operatory binarne i maski bitowe program, w którym zostaną zaimplementowane
        procedura zamieniająca liczbę całkowitą bez znaku na string reprezentujący jej zapis binarny, zgodna z prototypem :
        
        void write_binar(unsigned n, char * ptr)
        
        funkcja zgodna z prototypem: unsigned bits(unsigned x, unsigned n)zwracająca n najstarszych bitów z liczby x - pozostałe bity maja być wyzerowane
        
        Liczba oraz ilość bitów do wypisania ma być wczytywana z klawiatury - należy sprawdzić czy podana ilość bitów jest poprawna

        Wynik dla liczby 435 oraz 20 bitów
        liczba wczytana 43577 : 00000000000000010100101000111001
        20 najstarszych bitow : 00000000000000010100000000000000

*/

#include <stdio.h>
// n_bits - number of bits
void write_binar (unsigned n, char *wsk, int n_bits); // don't use '/' or '%', use a bit mask
unsigned bits(unsigned x, unsigned n); // use bit operations
void print_arr(char *tab, int size);


int main ()
{
    unsigned int result, number, bit_num;
    unsigned int n_bits = 32;

    char number_string[n_bits]; // array for binary representation

    // get number and number of bits
    printf("Number: ");
    scanf("%d", &number);
    
    do
    {
        printf("bit_num [0, 32]: ");
        scanf("%d", &bit_num);
    
    } while(bit_num < 0 || bit_num > n_bits);

    // convert number to binary
    write_binar(number, number_string, n_bits);
    
    // print binary representation of number
    printf("%d in binary: ", number); // 43577 in binary: 00000000000000010100101000111001
    print_arr(number_string, n_bits);

    // get given number of oldest bits  
    result = bits(number, bit_num); 
    
    // convert result to binary
    write_binar(result, number_string, n_bits);
    
    // print outcome
    printf("%u oldest bits: ", bit_num); //20 oldest bits: 00000000000000010100000000000000
    print_arr(number_string, n_bits);

    return 0; 
}

void write_binar(unsigned num, char *ptr, int n_bits)
{
    // right shift num by 1 (same as dividing by 2) and get the rest (LSB)
    // same as num%2
    for(int i = 0; i < n_bits; i++)
    {
        *(ptr+n_bits-1-i) = num & 1;
        num = num >> 1;
    }
}

unsigned bits(unsigned x, unsigned n)
{
    // return n oldest bits of x
    for(int i = 0; i < 32 - n; i++)
    {
        // set bits to 0
        x = (~(1 << i)) & x;
    }

    return x;
}

void print_arr(char *tab, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d", *(tab+i));
    }
    printf("\n");
}