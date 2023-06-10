#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    return 0;
}