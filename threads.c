#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* thr(){
  printf("%s\n","THREAAADS YEEEAh");
  sleep(3);
  printf("%s\n","ENDinG THREAAADS((" );
}

int main(){
  pthread_t t1, t2;
  if(pthread_create(&t1, NULL, &thr, NULL) != 0) {return 1;}
  if(pthread_create(&t2, NULL, &thr, NULL) != 0) {return 2;}
  if(pthread_join(t1, NULL) != 0) {return 3;}
  if(pthread_join(t2, NULL) != 0) {return 4;}
  return 0;
}
