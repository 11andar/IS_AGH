/*

3. ( 2 ) Proszę napisać program bez użycia dynamicznej alokacji pamięci, który jest uruchamiany z dowolną ilością 
         argumentów wejściowych.
         
         Program ma sklejać niepowtarzające się argumenty wywołania w jeden string.
         
         Na początku program ma wypisać wszystkie argumenty wywołania programu, a na koniec wypisać wynik. W przypadku braku argumentów proszę wypisać stosowny komunikat.
         
         Przykład działania
         
         wywołanie programu: ./a.out Ala ma psa a Ola ma kota i psa
         wypisanie argumentów : Ala
                                ma
                                psa
                                a
                                Ola
                                ma
                                kota
                                i
                                psa
         
         Łańcuch wyjściowy:     AlaaOlakotai

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main( int argc, char *argv[])
{
    if(argc == 1)
        printf("No command line arguments\n");
            
    // array for result string
    char output[100];
    
    bool comp = 0;
    
    for(int i = 1; i < argc; i++)
    {
        // print command line arguments
        printf("%s\n", argv[i]);

        // check if words are the same
        for(int j = 1; j < argc; j++)
        {
            comp = strcmp(argv[i], argv[j]);

            // if words are the same exit the loop
            if(j != i && comp == 0)
                break;
        }      
        
        // concatenate with output only if words weren't the same
        if(i != argc-1 && comp != 0)
            strcat(output, argv[i]);
    }

    // print result 
    printf("%s\n", output);

    return 0;
}