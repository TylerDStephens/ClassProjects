//Tyler Stephens, Project 3 Part A
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define TIMES 10
#define ROWS 5

void *threadA(void *);
void *threadB(void *);

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
        for (j = 0; j < ROWS; j++) {
            sleep(1);
            printf("%i: %s\n", i + 1, "AAAAAAAAAA");
        }
      printf("\n");
      sleep(2);
    }
    pthread_exit(NULL);
}
void *threadB(void *args) {
    int i, j;
    for (i = 0; i < TIMES; i++) {
      for (j = 0; j < ROWS; j++) {
          sleep(2);
          printf("%i: %s\n", i + 1, "BBBBBBBBBB");
      }
      printf("\n");
      sleep(2);
    }
    pthread_exit(NULL);
}