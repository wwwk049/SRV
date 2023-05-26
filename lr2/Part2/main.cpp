#include <iostream>
#include <pthread.h>
#include <sys/neutrino.h>
#include <sched.h>
#include <unistd.h>
#include <dlfcn.h>
#include "mylib.h"

pthread_t thread_id1;
pthread_t thread_id2;
int counter;
pthread_mutex_t mutex;

struct sched_param param1 = {6};
struct sched_param param2 = {12};

void *long_thread1(void *notused)
{
    int n;
    for (n = 0; n < 5; n++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
        std::cout << "Kalaganov, TID " << thread_id1 << " - N of repeat " << n << std::endl;
        sleep(2);
    }
}

void *long_thread2(void *notused)
{
    int m;
    for (m = 0; m < 5; m++)
    {
        std::cout << "Kirill I993, TID " << thread_id2 << " - N of repeat " << m << std::endl;
        sleep(1);
    }
}

int main()
{
    std::cout << "Program threads PID " << getpid() << std::endl;
    pthread_mutex_init(&mutex, NULL);

    pthread_setschedparam(thread_id1, SCHED_RR, &param1);
    pthread_setschedparam(thread_id2, SCHED_RR, &param2);

    pthread_create(&thread_id1, NULL, long_thread1, NULL);
    pthread_create(&thread_id2, NULL, long_thread2, NULL);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    pthread_mutex_destroy(&mutex);
    std::cout << "Counter is equal: " << counter << std::endl;

    return 0;
}
