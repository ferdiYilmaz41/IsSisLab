#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 7
char *messages[NUM_THREADS];
void *printHello(void *threadid){
int *id_ptr, taskid;
sleep(1);
id_ptr = (int *) threadid;
taskid = *id_ptr;
printf("(from thread %d) %s\n", taskid, messages[taskid]);
pthread_exit(NULL);
}
void main(){
pthread_t threads[NUM_THREADS];
int *taskids[NUM_THREADS], rc, t;
messages[0] = "English: Hello World!";
messages[1] = "French: Bonjour, le monde!";
messages[2] = "Spanish: Hola al mundo";
messages[3] = "Klingon: Nuq neH!";
messages[4] = "German: Guten Tag, Welt!";
messages[5] = "Russian: Zdravstvytye, mir!";
messages[6] = "Japan: Sekai e konnichiwa!";
messages[7] = "Latin: Orbis, te saluto!";
for(t=0;t<NUM_THREADS;t++){
taskids[t] = (int *) malloc(sizeof(int));
*taskids[t] = t;
printf("Creating thread %d\n", t);
rc=pthread_create(&threads[t],NULL,printHello,(void
*)taskids[t]);
if (rc){
printf("ERROR;return code of pthread_create() %d\n", rc);
exit(-1);
}
}
pthread_exit(NULL);
}
