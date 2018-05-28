#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<pthread.h>

void *thread_f(void *arg);

int main(int argc, char **argv){
	pthread_t thread;

	if (argc != 2){
		fprintf(stderr, "arg error\n");
		exit(1);
	}

	if (pthread_create(&thread, NULL, thread_f, (void *)atoi(argv[1])) != 0){
		fprintf(stderr, "pthread_create error\n");
		exit(1);
	}

	printf("main\ncreate thread %u\n", thread);
	//sleep(2);

	int ret;
	if (pthread_join(thread, (void **)&ret) != 0){
		fprintf(stderr, "pthread_join error\n");
		exit(1);
	}
	thread = NULL;
	printf("ret: %d\n", ret);
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
			pthread_exit((void *)n);
#else
			exit(1);
#endif
	}
}

