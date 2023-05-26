#ifndef MYLIB_H
#define MYLIB_H

void *long_thread1(void *notused);
void *long_thread2(void *notused);

extern pthread_t thread_id1;
extern pthread_t thread_id2;

extern int counter;

extern pthread_mutex_t mutex;

#endif
