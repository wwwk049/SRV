#include <stdio.h>
#include <pthread.h>
#include <sys/neutrino.h>
#include "mylib.h"

void *long_thread1(void *notused)
{
  int n;
  for(n=0; n<5; n++)
  {
    pthread_mutex_lock(&mutex);
    counter++;
    pthread_mutex_unlock(&mutex);
    printf("Kalaganov, TID %d - N of repeat %d \n", thread_id1, n);
    sleep(2);
  }
}

void *long_thread2(void *notused)
{
  int m;
  for(m=0; m<5; m++)
  {
  	printf("Kirill I993, TID %d - N of repeat %d \n", thread_id2, m);
    sleep(1);
  }
}
