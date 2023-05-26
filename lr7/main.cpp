#include <iostream>
#include <pthread.h>
#include <unistd.h>

int data_ready = 0;
int inf = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

void *consumer(void *notused) {
    std::cout << "Eto potrebitel" << std::endl;
    while (true) {
        pthread_mutex_lock(&mutex);
        std::cout << "W1 Kalaganov" << std::endl;
        while (!data_ready) {
            std::cout << "W2 Kirill" << std::endl;
            pthread_cond_wait(&condvar, &mutex);
            std::cout << "W3 I993" << std::endl;
        }
        std::cout << "dannie on proizv = " << inf << std::endl;
        data_ready = 0;
        pthread_cond_signal(&condvar);
        pthread_mutex_unlock(&mutex);
    }
}

void *producer(void *notused) {
    std::cout << "Eto proizvoditel" << std::endl;
    while (true) {
        sleep(2);
        std::cout << "proizvoditel polychil dannie ot h/w = " << inf << std::endl;
        pthread_mutex_lock(&mutex);
        std::cout << "Wp1" << std::endl;
        while (data_ready) {
            std::cout << "Wp2" << std::endl;
            pthread_cond_wait(&condvar, &mutex);
        }
        data_ready = 1;
        inf++;
        std::cout << "Wp3" << std::endl;
        pthread_cond_signal(&condvar);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    std::cout << "Start" << std::endl;
    pthread_t consumerThread, producerThread;
    pthread_create(&consumerThread, NULL, consumer, NULL);
    pthread_create(&producerThread, NULL, producer, NULL);
    sleep(10);
    return 0;
}
