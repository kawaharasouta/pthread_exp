#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<pthread.h>

void th(void *arg);

int main(int argc, char **argv){
	pthread_t thread;

	if (pthread_create(&thread, NULL, th, NULL) != 0){
		fprintf(stderr, "pthread_create error\n");
		exit(1);
	}
	printf("main fin\n");

	sleep(1);

	return 0;
}

void th(void *arg){
	printf("new thread\n");
}

