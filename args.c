#include <stdio.h>

int main(int argc, char** argv){

    printf("Number of arguments entered = %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("Arguments[%d] = %s\n",i, argv[i]);
    }
    // ver 2:
    int n = 0;
    while (argv[n] != NULL)
    {
        printf("Arguments[%d] = %s\n",n, argv[n]);
        n++;
    }
    // ./args ... ...
    // za edin argument sudurjasht space - ./args "... ..." ili s edinichni ' .. ..  '
    
    /* to create a variable in terminal :  
    
    number=30
    echo $number -> prints 30

    */
    return 0;
}