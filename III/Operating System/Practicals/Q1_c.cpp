#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

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
        cout << "\nWe are in the child process (" << p << ") !!!";
    else
        cout << "\nWe are in the parent process (" << p << ") !!!";

    if (!p)
    {
        cout << "\nWaiting for child process to terminate !!!";
        wait(NULL);
        cout << "\nChild Terminated !!!\nParent Terminated !!!";
    }
}