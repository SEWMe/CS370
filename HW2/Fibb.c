    #define SIZE_LINE 256
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
   
    int main(int argc, char *argv[])    
{ 


    int mike = atoi(argv[1]);
int maxValue;
    printf("%s%s%s%d%s", "Fibb[",argv[2], "]: The first ", mike, " numbers of the Fibonacci sequence are:");  
    int a=0;
    int b=1;
    int c;
    int number;    
     int value = atoi(argv[1]);
           number = value;   
     printf("\n%d, %d, ",a,b);    
     for(int i = 2 ; i < number ; ++i)
{    
      c = a + b;    
      printf("%d, ",c);    
      a = b;    
      b = c;


     maxValue = c;
  
 }  
 
 printf("\n");

return maxValue;

 return 0;
  
     }    
