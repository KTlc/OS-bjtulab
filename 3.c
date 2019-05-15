#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>


char buffer[10];
//sem_t *mutex = NULL;
sem_t *empty = NULL;
sem_t *full = NULL;

void *worker1(){
    for(int i = 0;i < 100;i++){
        sem_wait(empty);
        //sem_wait(mutex);
        scanf("%c",&buffer[i%10]);
        // char c;
        // c = getchar();
        // buffer[i%10] = c;
        //sem_post(mutex);
        sem_post(full);
        
        // buffer[i] = t;
    }
}

void *worker2(){
    for (int i = 0;i < 100;i++){
        sem_wait(full);
        //sem_wait(mutex);
        char t = buffer[i%10];
        printf("Character:\"%c\"\n",buffer[i%10]);
        //sem_post(mutex);
        sem_post(empty);
        sleep(1);
    }
}


int main(int argc, char *argv[])
{   
    
    //mutex = sem_open("mutex",O_CREAT,0666,1);
    empty = sem_open("emptyname",O_CREAT,0666,10);
    full = sem_open("fullname",O_CREAT,0666,0);
    pthread_t p1, p2;

    pthread_create(&p1, NULL, worker1, NULL);
    pthread_create(&p2, NULL, worker2, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    //printf("Final value : %d\n", counter);
    //sem_close(mutex);
    sem_close(empty);
    sem_close(full);
    //sem_unlink("mutex");
    sem_unlink("emptyname");
    sem_unlink("fullname");
    return 0;
}
