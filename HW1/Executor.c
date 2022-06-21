//
// Created by AFHIR on 5/19/2022.
//
#include "Executor.h"
#include <stdlib.h>
#include <stdio.h>

int get_iteration_no(int rand)
{
    int upper = 100;
    int lower = 50;
    int var = ((rand % (upper - lower) + lower));
    printf("[Executor]: Number of iterations is: %d\n", var);
    return var;
}

int get_arr_size(int rand)
{
    int lower = 100;
    int upper = 150;
    int var = ((rand % (upper - lower) + lower));
    return var;
}

char get_arr_val(int rand)
{
    int lower = 65;
    int upper = 91;

    char x = (char)((rand % (upper - lower) + lower));

    return x;
}

float ratio(char *arr, int size, int *maxCountPointer)
{
    double vowels = 0;
    double constants = 0;

    for(int x = 0; x < size; x++)
    {
        switch(arr[x])
        {
            case 'A':
                vowels++;
                break;
            case 'E':
                vowels++;
                break;
            case 'I':
                vowels++;
                break;
            case 'O':
                vowels++;
                break;
            case 'U':
                vowels++;
                break;
            default:
                constants++;

        }


    }
    
  

if(vowels > *maxCountPointer)
{

    *maxCountPointer = vowels;
    
}


   return vowels / constants;


}


double get_running_ratio()
{


    int maxCount = 0;
    int maxIteration = 0;
    //KEEPS THE SUM OF THE RATIOS FROM ITERATIONS
    double sumRatios = 0;
    
    

    //IT THEN USES THE RANDOM NUMBER GENERATOR TO COMPUTE THE NUMBER OF TIMES THAT IT MUST ALLOCATE AND DE-ALLOCATE ARRAYS.
    int numIter = get_iteration_no(rand());
    for(int k = 0; k < numIter; k++) {
        int sizeArray = get_arr_size(rand());
        //ALLOCATE MEMORY TO THE HEAP
        char *pointer;
        pointer = malloc(sizeof(char) * sizeArray);
        //STORE VALUES IN ALLOCATED MEMORY
        for (int i = 0; i < sizeArray; i++) {
            *(pointer + i) = get_arr_val(rand());
           
            
        }

        int maxcountTemp = maxCount;
        double ratioNumber = ratio(pointer, sizeArray, &maxCount);


        //if the temporary copy of maxCount is not the same as maxCount, it means
        //the ratio() modified the maxCount, so the current iteration is the highest count of vowels. Change
        //the value of maxIteration to the current iteration number.
        

        
        
        if(maxcountTemp != maxCount)
        {
        
            maxIteration = k + 1;
        }

        sumRatios += ratioNumber;
        
        
        
        //FREE UP MEMORY THAT WAS ALLOCATED AT BEGINNING OF LOOP
        if(k <= numIter)
        {
        free(pointer);
        }
        
        
        
    }


    printf("[Executor]: Iteration with maximum vowel count is: %d\n", maxIteration);

    float value = sumRatios / (float)numIter;

    double otherValue = value * 1.00000;



      
    return otherValue;


   





}
