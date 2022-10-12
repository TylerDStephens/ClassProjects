//Tyler Stephens, Project 3 Part B
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define TIMES 10
#define ROWS 5

void *threadA(void *);
void *threadB(void *);

pthread_mutex_t mutex;

int main() {

    pthread_t pid;
    pthread_setconcurrency(2);
    pthread_create(&pid, NULL, threadA, NULL);
    pthread_create( &pid, NULL, threadB, NULL);
    pthread_exit(NULL);
}
void *threadA(void *args) {
    int i, j;
    for (i = 0; i < TIMES; i++) {
        pthread_mutex_lock(&mutex);
        for (j = 0; j < ROWS; j++) {
            sleep(1);
            printf("%i: %s\n", i + 1, "AAAAAAAAAA");
        }
       printf("\n");
       pthread_mutex_unlock(&mutex);
       sleep(2);
    }
    pthread_exit(NULL);
}
void *threadB(void *args) {
    int i, j;
    for (i = 0; i < TIMES; i++) {
        pthread_mutex_lock(&mutex);
        for (j = 0; j < ROWS; j++) {
            sleep(1);
            printf("%i: %s\n", i + 1, "BBBBBBBBBB");
        }
       printf("\n");
       pthread_mutex_unlock(&mutex);	
       sleep(2);
    }
    pthread_exit(NULL);
}