#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char** argv){
    int sum = 0;
    
    for (int i = 0; i < argc; i++)
    {
        sum += atoi(argv[i]); // atoi makes a string to int
    }
    printf("Sum = %d\n",sum);

    
    return 0;
}