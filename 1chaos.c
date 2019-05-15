#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t pid;
    pid = fork();
    // if (pid > 0){
    //     for(;;){
    //     }
    // }
    if (pid == 0){
        pid_t p2;
        p2 = fork();
        if (p2 == 0){
            for(;;){
                printf("I am the process p2\n");
                sleep(1);
            }  
        }
        else if (p2 > 0){
            pid_t p3;
            p3 = fork();
            if (p3 == 0){
                for(;;){
                    printf("I am the process p3\n");
                    sleep(1);
                }
            }
            else if (p3 > 0){
                pid_t p4;
                p4 = fork();
                if (p4 == 0){
                    for(;;){
                        printf("I am the process p4\n");
                        sleep(1);
                    }
                }
            }
        }
    }
    if (pid > 0){
        for(;;){
        printf("I am the process p1\n");
        sleep(1);
    }
    }   
    return 0;
}