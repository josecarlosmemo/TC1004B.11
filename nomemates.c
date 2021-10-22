#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handleSignal(int signal)
{
    printf("Jajajaja no me mates\n");
}

int main(int argc, char const *argv[])
{
    signal(2, handleSignal);

    while (1)
    {
        printf("Trabajando... \n");
        sleep(1);
    }

    return 0;
}
