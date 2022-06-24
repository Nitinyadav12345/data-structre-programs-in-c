#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	fork();
	printf("ny pid =%d\n",getpid());
	return 0;
}
