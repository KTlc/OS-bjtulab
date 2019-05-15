#include <stdio.h> 
#include <unistd.h>  
#include <string.h> 
#include <stdlib.h>

int main()
{
    int noNamePipe[2];
    char buf[64];
    pid_t pid;

    if(-1 == pipe(noNamePipe))
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
   
    pid = fork();

    if(pid > 0){

        sleep(3);
        printf("父进程\n");
        char s[] = "父进程创建的字符串。\n";
        write(noNamePipe[1],s,sizeof(s));
        close(noNamePipe[0]);
        close(noNamePipe[1]);
    } else if(pid == 0)
    {       
        printf("子进程\n");
        read(noNamePipe[0],buf,sizeof(buf));
        printf("%s\n",buf);
        close(noNamePipe[0]);
        close(noNamePipe[1]);
    }
    return 0;
}