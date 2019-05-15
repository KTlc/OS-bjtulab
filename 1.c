#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    sem_t *a1 = NULL;
    sem_t *a2 = NULL;
    sem_t *mutex = NULL;
    sem_t *b = NULL;
    sem_t *c = NULL;
    a1 = sem_open("a1",O_CREAT,0666,0);
    a2 = sem_open("a2",O_CREAT,0666,0);
    b = sem_open("b",O_CREAT,0666,0);
    c = sem_open("c",O_CREAT,0666,0);
    mutex = sem_open("mutex",O_CREAT,0666,1);
    pid_t pid;
    pid = fork();
    if (pid > 0){
        for(;;){
        printf("I am the process p1\n");
        sem_post(a1);
        sem_post(a2);
        sleep(1);
    }
    }
    if (pid == 0){
        pid_t p2;
        p2 = fork();
        if (p2 == 0){
            for(;;){
                sem_wait(a1);
                sem_wait(mutex);
                printf("I am the process p2\n");
                sem_post(mutex);
                sem_post(b);
                sleep(1);
            }  
        }
        else if (p2 > 0){
            pid_t p3;
            p3 = fork();
            if (p3 == 0){
                for(;;){
                    sem_wait(a2);
                    sem_wait(mutex);
                    printf("I am the process p3\n");
                    sem_post(mutex);
                    sem_post(c);
                    sleep(1);
                }
            }
            else if (p3 > 0){
                pid_t p4;
                p4 = fork();
                if (p4 == 0){
                    for(;;){
                        sem_wait(b);
                        sem_wait(c);
                        printf("I am the process p4\n");
                        sleep(1);
                    }
                }
            }
        }
    }
    
    sem_close(a1);
    sem_close(a2);
    sem_close(b);
    sem_close(c);
    sem_close(mutex);
    sem_unlink("a1");
    sem_unlink("a2");
    sem_unlink("b");
    sem_unlink("c");
    sem_unlink("mutex");
    return 0;
}