#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NKIDS 50
int tot_items = 0;
struct kidrec{
int data;
pthread_t id;
};
void *kidfunc(void *p){
int *ip = (int *)p;
int tmp, n;
tmp = tot_items;
for (n = 50000; n--;)
tot_items = tmp + *ip;
}
void main(){
struct kidrec kids[NKIDS];
int m;
for (m=0; m<NKIDS; ++m){
kids[m].data = m+1 ;
pthread_create(&kids[m].id,NULL,kidfunc,&kids[m].data);
}
for (m=0; m<NKIDS; ++m)
pthread_join (kids[m].id, NULL);
printf ("End! Grand Total = %d\n", tot_items);
}