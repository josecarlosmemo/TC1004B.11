#include <stdio.h>  // Input & Output
#include <unistd.h> // fork()

int main(int argc, char const *argv[])
{
    int pid = fork();

    if (pid == 0)
    {
        printf("Soy el proceso hijo, PID = %d\n", pid);
    }
    else
    {
        printf("Soy el proceso padre, PID = %d\n", pid);
    }

    return 0;
}
