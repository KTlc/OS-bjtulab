#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		printf("I am the parent of pid:%d!\n",getpid());
		while(1);
	}
	else if(!pid)
	{
		printf("I am the baby pid:%d!\n",getpid());
		int ret;
		ret=execl("/usr/bin/vi","vi",NULL);
		if(ret==-1)
		{
			perror("error!\n");
		}
	}
	else if(pid==-1)
	{
		perror("fork\n");
	}
	return 0;
}
