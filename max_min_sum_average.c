#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int compare (const void * a, const void * b){
    double n1 = *(double*)a;
    double n2 = *(double*)b;
    
    if (fabs(n1 - n2) < 0.0001){
        return 0;
    } 
    else if (n1 > n2){
        return 1;
    }
    return -1;
}

int main(int argc, char** argv){

    double sum = 0;
    double min = argv[1];
    double max = argv[1];
    double average;
    fork();
   // qsort(argv, argc, sizeof(argv[1]), compare);
    
    for (size_t i = 0; i < argc; i++)
    {
        if (min > argv[i])
        {
            min = argv[i];
        }
        if (max < argv[i])
        {
            max = argv[i];
        }
    }
    
    if( ==0)[
      //child
      for (int i = 0; i < argc; i++)
        {
            sum += atoi(argv[i]); // atoi makes a string to int
        }
        average = sum / argc;
    ]
    else{
        //parent
        printf("Sum = %lf\n",sum);
        printf("Average = %lf\n",average);
    }
    

    
    return 0;
}