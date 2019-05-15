#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>

int ticketCount = 1000;
int sellTimes = 0;
int returnTimes = 0;
sem_t *mutex = NULL;

void *sellticket(){
    //int temp = ticketCount;
    for(int i = 0;i<sellTimes;i++){
        sem_wait(mutex);
        int temp = ticketCount;
        pthread_yield();
        temp--;
        pthread_yield();
        ticketCount = temp;
        sem_post(mutex);
        //ticketCount--;
    }
    //ticketCount = temp;
}

void *returnticket(){
    for(int i = 0;i<returnTimes;i++){
        sem_wait(mutex);
        int temp = ticketCount;
        pthread_yield();
        temp++;
        pthread_yield();
        ticketCount = temp;
        sem_post(mutex);
    }
}

int main(int argc, char *argv[]){
    mutex = sem_open("mutex",O_CREAT,0666,1);
    pthread_t p1, p2;
    printf("分别输入购票，退票次数：\n");
    scanf("%d %d",&sellTimes,&returnTimes);
    pthread_create(&p1, NULL, sellticket, NULL);
    pthread_create(&p2, NULL, returnticket, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("剩余票数:%d\n",ticketCount);
    return 0;
}