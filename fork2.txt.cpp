#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
	int p1,p2,p3,p4,p5;
	while((p1=fork())==-1);
	if(!p1)
	{
		printf("I am p1 parent of pid:%d!\n",getpid());
		printf("I am p1 baby pid:%d!\n",getppid());
		while((p2=fork())==-1);
		if(!p2)
		{
			printf("I am p2 parent of pid:%d!\n",getpid());
			printf("I am p2 baby pid:%d!\n",getppid());
			while((p3=fork())==-1);
			if(!p3)
			{
				printf("I am p3 parent of pid:%d!\n",getpid());
				printf("I am p3 baby pid:%d!\n",getppid());
				exit(0);
			}
			else
			wait(0);
			while((p4=fork())==-1);
			if(!p4)
			{
				printf("I am p4 parent of pid:%d!\n",getpid());
				printf("I am p4 baby pid:%d!\n",getppid());
				exit(0);
			}
			else
			wait(0);
			exit(0);
		}
		else
		wait(0);
		while((p5=fork())==-1);
		if(!p5)
		{
			printf("I am p5 parent of pid:%d!\n",getpid());
			printf("I am p5 baby pid:%d!\n",getppid());
			exit(0);
		}
		else
		wait(0);
		exit(0);
	}
	return 0;
}
