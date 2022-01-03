#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;
int a = 0;
void* thr(){
  printf("%s\n","THREAAADS YEEEAh");
  sleep(3);
  printf("%s\n","ENDinG THREAAADS((" );
  for(int i = 0; i < 1000000 ; i++) {
    pthread_mutex_lock(&mutex);
    a++;
    pthread_mutex_unlock(&mutex);
  }
}

int main(){

  pthread_t t1, t2, t3, t4;
  pthread_mutex_init(&mutex, NULL);

  if(pthread_create(&t1, NULL, &thr, NULL) != 0) {return 1;}
  if(pthread_create(&t2, NULL, &thr, NULL) != 0) {return 2;}
  if(pthread_create(&t3, NULL, &thr, NULL) != 0) {return 3;}
  if(pthread_create(&t4, NULL, &thr, NULL) != 0) {return 4;}
  if(pthread_join(t1, NULL) != 0) {return 5;}
  if(pthread_join(t2, NULL) != 0) {return 6;}
  if(pthread_join(t3, NULL) != 0) {return 7;}
  if(pthread_join(t4, NULL) != 0) {return 8;}

  pthread_mutex_destroy(&mutex);

  printf("%i\n", a);
  return 0;
}
