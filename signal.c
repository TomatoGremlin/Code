#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>
#include <string.h>

/*void handler(int sig){
    printf("hello %d\n", sig);
}*/

void getHint(int sig){
    printf("1.Multiplication, then addition\n");
}

int main(){
    //signal(SIGINT, handler);
   // while(1);

    pid_t pid = fork();
    if (pid == -1)
    {
        return EXIT_FAILURE;
    }

    if (pid == 0)
    {
        //child
        sleep(5);
        kill(getppid(),SIGUSR1);
    }
    else{
        //parent
        struct sigaction sa;
        sa.sa_handler = getHint;
        sa.sa_flags = SA_RESTART;
        sigaction(SIGUSR1, &sa, NULL);
        
        int num;
        printf("5+2*6 = ?\n");
        scanf("%d", &num);
        if ( num ==18)
        {
            printf("Correct\n");
        }else{
            printf("Error\n");
        }
        kill(pid,SIGUSR1);
        wait(NULL);
    }
    return 0;
}