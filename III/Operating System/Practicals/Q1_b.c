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

int main()
{
    pid_t p = fork();

    error(p);
    if (p)
    {
        system("echo \'\nChild process !!!\'");
        execlp("/media/avinash/F012C43312C40098/B.SC_CS/#Semesters/IIIrd Sem/Operating System/Practicals/Q5","Q5", NULL);
    }
    else{
        printf("\nParent process : %d !!!\n", p);
    }
    return 0;
}