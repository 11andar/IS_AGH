/*

4. ( 2 ) Proszę uzupełnić program (bez dynamicznej alokacji pamięci) według wskazówek zawartych w komentarzach.

    Wynik działania programu dla wywołania ./a.out Jedenascie Dwiescie
    A --> napis_1 = Jedenascie napis_2 = Dwiescie
    B --> napis_1 = Dwiescie napis_2 = Jedenascie

*/

#include <stdio.h> // konieczne biblioteki
#include <string.h>

void swap_str(char *str1, char *str2, int len);

int main(int argc, char *argv[])
{ 
    //deklaracja koniecznych zmiennych, miedzy innymi tablic nap_1 oraz nap_2
    int len = 30;
    char nap_1[len];
    char nap_2[len];

    strcpy(nap_1, argv[1]);
    strcpy(nap_2, argv[2]);

    //zapisanie argumentów wywołania programu do tablic nap_1 oraz nap_2
    printf ("A --> napis_1 = %s napis_2 = %s\n", nap_1, nap_2); //zostanie wypisane: A --> napis_1 = Jedenascie napis_2 = Dwiescie

    // swap strings
    swap_str(nap_1, nap_2, len);

    //wymiana zawartosci tablic nap_1 i nap_2
    printf ("B --> napis_1 = %s napis_2 = %s\n", nap_1, nap_2); //zostanie wypisane: B --> napis_1 = Dwiescie napis_2 = Jedenascie
    
    return 0;
}

void swap_str(char *str1, char *str2, int len)
{
    char temp_str[len];

    strcpy(temp_str, str1);
    strcpy(str1, str2);
    strcpy(str2, temp_str);
    
}