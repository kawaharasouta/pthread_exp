#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<pthread.h>

void *thread_f(void *arg);

int main(int argc, char **argv){
	pthread_t thread;

	if (pthread_create(&thread, NULL, thread_f, (void *)5) != 0){
		fprintf(stderr, "pthread_create error\n");
		exit(1);
	}

	printf("main\n");
	sleep(2);
	printf("main fin\n");

	return 0;
}

void *thread_f(void *arg){
	int i;
	int n = (int)arg;

	for (i = 0; i < n; i++){
		printf("%d times new thread\n", i);
		if (i == n)
#if 1
			pthread_exit(NULL);
#else
			exit(1);
#endif
	}
}

