#include <stdlib.h>

/*
  Consumer/Producer problem
        - Producer - proce and put in basket
        - Consumer - consume from basket

        If there aren't sufficient items in basket to consume, consumer should wait for producer.
        Producer should wait for consumer to consume if basket is full.

        For starters there is single producer and single consumer.



Producer:
     function produce() {
         while(True){
            basket_mutex.lock();
            if (basket_count < full ){
                basket_count++;
            }
            basket_mutex.unlock();
            sleep(1);
     }
Consumer:
     function consume() {
         while(True) {
            basket_mutex.lock();
            if(basket_size > 0) {
                basket_count--;
            }
            basket_mutex.unlock();
            sleep(1);
         }
      }

Note: if sleep on consumer is 0.1 it will check 10 times if product is availble before product is actually available.
Can we avoid this polling? Use conditional variables

producer()
     while(true) {
         while( cond_var_mutex.lock()) {
             if (basket_size >= full ) {
                cond_var.wait();
             }
             basket_count++;
             cond_var_mutex.unlock
             cond_var.notify_all();
         }
     }

*/
#include <pthread.h>

typedef enum { false, true } bool;

bool stop = false;

void*
consume(void *ptr) {
  while(!stop){
    while(cond_not_full_mutex){
    }
    usleep(1024*1024);
  }
}

int main(){
  pthread_t th_cons, th_prod;

  if (err = pthread_create(&th_cons, NULL, consume, NULL) {
      fprintf(stderr, "pthread_create retcode: %d", err);
      exit(err);
  }
  if (err = pthread_create(&th_pord, NULL, produce, NULL) {
        fprintf(stderr, "pthread_create retcode: %d", err);
        exit(err);
  }

  pthread_join(th_cons, NULL);
  pthread_join(th_cons, NULL);

  return 0;
}
