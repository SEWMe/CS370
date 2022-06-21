#include <stdio.h>
#include "Executor.h"
#include <time.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {

    if(argc > 2)
    {
        printf("Too many arguments given.");
        exit(1);
    }

    int seed = atoi(argv[1]);
    srand(seed);

    printf("[Starter]: With seed: %d\n", seed);
    
    
    double var = get_running_ratio();
    
    printf("[Starter]: Running Ratio:   %f\n", var);
    
    return 0;


   

}
