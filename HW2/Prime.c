#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>




int main(int argc, char *argv[])
{

printf("%s%s%s%s%d%s", "Prime[", argv[2], "]: ", "The first ", atoi(argv[1]), " prime numbers are: \n");

int val = 3;
int val1;
int count;

int maxValue = 0;
printf("%d, ", 2);
for (count = 2; count <= atoi(argv[1]);)
  {
    for (val1 = 2; val1 <=  val - 1 ; val1++)
    {
      if (val%val1 == 0)
        break;
    }
    if (val1 == val)
    {
      printf("%d, ", val);
      count++;
    }
    val++;
    if(count <= atoi(argv[1]))
  {
  maxValue = val;
  
  }
  }
  
printf("\n");
  return maxValue;
}
