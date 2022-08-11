#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

double routine(void* arg){
    FILE *f = fopen(arg, "r");
    if (f == NULL)
    {
        perror("Could not open file\n");
        return -1;
    }
    double n;
    double sum = 0 ; 
    while (fscanf(f, "%lf", n)!= EOF)
    {
        sum += n;
    }
    fclose(f);
    return sum;
}


int main(int argc, char** argv){

    pthread_t th[argc];
    double sum =0;

    for (int i = 1; i < argc; i++){
        if (pthread_create(th + i, NULL, routine, NULL)){
            perror("create");
            return EXIT_FAILURE;
        }
        sum += routine(argv[i]);
    }
    for (int i = 1; i < argc; i++){
        int *ptrValue;
        if (pthread_join(th[i], (void**)&ptrValue)){
            perror("join");
            return EXIT_FAILURE;
        }
        printf("Value = %d\n", *ptrValue);
        free(ptrValue);
    }
   
    return 0;
}