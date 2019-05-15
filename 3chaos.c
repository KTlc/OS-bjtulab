#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>


char buffer[10];

void *worker1(){
    for(int i = 0;i < 100;i++){
        scanf("%c",&buffer[i%10]);
    }
}

void *worker2(){
    for (int i = 0;i < 100;i++){
        char t = buffer[i%10];
        printf("Character:\"%c\"\n",buffer[i%10]);
        sleep(1);
    }
}


int main(int argc, char *argv[])
{   
    

    pthread_t p1, p2;

    pthread_create(&p1, NULL, worker1, NULL);
    pthread_create(&p2, NULL, worker2, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}
