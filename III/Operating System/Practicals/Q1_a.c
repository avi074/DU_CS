#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define error(a)                                \
    if (a == -1)                                \
    {                                           \
        perror("Unable to create Process !!!"); \
        exit(-1);                               \
    }

void a()
{
    pid_t p = fork();
    error(p);
    if(p)
        printf("\nCalling with child process id : %d !!!\n", p);
    else
        printf("\nCalling with parent process id : %d !!!\n", p);
}

int main()
{	
    a();
    printf("Terminating process !!!\n");
}
