#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char** argv){
    double a, b, x;
    int flag = 0;

    int option;
    while ((option = getopt(argc, argv, "a:b:)") != -1))
    {
        switch (option)
        {
        case 'a':
            scanf(optarg, "%lf", &a);
            break;
        case 'b':
            scanf(optarg, "%lf", &b);
            break;
        default:
        printf("Invalid");
            break;
        }
    }
    if (flag!= 2)
    {
        printf("Invalid arguments");
    }
    x = -b/a;
    printf("x =%2f", x);

    return 0;
}