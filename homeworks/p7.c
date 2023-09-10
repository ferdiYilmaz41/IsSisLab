#include <pthread.h>
#include <stdio.h>
void childFunc(void *argument){
int i;
for (i = 1; i <= 20; ++i ){
printf(" Child Count - %d\n", i);
}
pthread_exit(0);
}
int main(void){
pthread_t hThread;
int ret;
ret=pthread_create(&hThread,NULL,(void*)childFunc, NULL);

if (ret < 0) {
printf("Thread Creation Failed\n");
return 1;
}
pthread_join (hThread, NULL); /* Parent waits for */
printf("Parent is continuing....\n");
return 0;
}
