#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 1000

int saldo;
pthread_mutex_t saldo_lock = PTHREAD_MUTEX_INITIALIZER;

void *suma100(void *arg)
{
    int saldoLocal;
    pthread_mutex_lock(&saldo_lock);
    saldoLocal = saldo;
    saldoLocal += 100;
    saldo = saldoLocal;
    // char *c = (char *)arg;
    // printf("Hola desde un hilo %s \n", c);
    pthread_mutex_unlock(&saldo_lock);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t threads[NUM_THREADS];
    saldo = 0;

    // char *s = "soy un argumento";

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, suma100, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Saldo Final es: %d\n", saldo);

    pthread_exit(NULL);

    return 0;
}
