#define SIZE_LINE 256
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>




// Driver code
int main(int argc, char *argv[])
{

    
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Error: could not open file");
        return 1;
    }

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    
  
pid_t ppid = getpid(), pid;
int fibb, prime, total;

while (fgets(buffer, MAX_LENGTH, fp))
{
//begin child process
  for(int i = 1; i <= 3; ++i)
    {
    pid = fork();
    if (pid != 0)
    {
      printf("Starter[%d]: Forked process with ID %d.\n", ppid, pid);
    }
    if(pid == 0)
    {
    
    //fibb sequence
    if(i == 1)
    {
        char mike[10];
            snprintf(mike, 10, "%d", getpid());
             execlp("./Fibb", "Fibb", buffer, mike, NULL);
             }
    //Prime sequence
    if(i == 2){
        char mike[10];
            snprintf(mike, 10, "%d", getpid());
             execlp("./Prime", "Prime", buffer, mike, NULL);
}
        //total sequence
         if(i == 3){
        char mike[10];
            snprintf(mike, 10, "%d", getpid());
             execlp("./Total", "Total", buffer, mike, NULL);
        }
        }
        
//parent process
else if(pid > 0)
{
int status;

printf("Starter[%d]: Waiting for process [%d].\n", ppid, pid);
wait(&status);
int retval = WEXITSTATUS(status);
printf("Starter[%d]: Child process returned %d.\n", pid, retval);


if(i == 1)
fibb = retval;
if(i == 2)
prime = retval;
if(i == 3)
total = retval;

}

}
    }
    fclose(fp);
    printf("%s%d%s", "Fibb: ", fibb, "\n");
    printf("%s%d%s", "Prime: ", prime, "\n");
    printf("%s%d%s", "Total Count: ", total, "\n");
  return 0;
}
