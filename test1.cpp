#include<stdio.h>    /*标准输入输出定义*/
#include<stdlib.h>   /*标准函数库定义*/
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t t1=getpid();
	printf("I am the id of the current process:%d!\n",t1);
	pid_t t2=getpid();
	printf("I am the id of the parrent process:%d!\n",t1);
	return 0;
 } 
