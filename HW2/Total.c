#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])  
{

int value = 0;


for(int i = 0; i < atoi(argv[1]) +1; i++)
{

  value = value + i;
}

printf("%s%s%s%s%d%s", "Total[", argv[2], "]:", "Sum = ", value, "\n");


return value;

}
