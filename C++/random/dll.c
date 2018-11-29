#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <assert.h>

/*
  DLL --
  Reader -- contineously reads each node
  Writer -- insert/delete/update node
     a. Node data
     b. Node itself - i.e. insert/delete/traverse node

  Take case a
    - lock node
    - read/update data
    - unlock node

  Take case b
   - reader
    - lock con_mutex
    - busy node = node
    - notify
    - unlock mutex
    - do work
    - lock cond_mutex
    - node = none
    - notify
    - unlock mutex

   - writer
    - lock mutex
    - while ( this == busy )
        cond_wait()
    - do work
    - unlock mutex
       
 */



typedef struct dll_node_def {
   void *data;
   struct dll_def* prev;
   struct dll_def* next;
} dll_node;

typedef struct dll_def {
   dll_node *head;
   dll_node *tail;
}

dll_node *
dll_next( dll_node *node ) {
   assert( node );
   if( !node->next ) {
      if ( !node->prev ) {
         return node;
      }
      return node->prev;
   }
   return node->next;
}

void
dll_add ( dll *dll, void* data ) {
   
}

void 
dll_delete( dll_node *node) {

}

static void*
reader( void *arg) {
   int i = 0;
   while( 1 ) {
      printf ( "Reading node %d" , i );
      i++;
   }
   return NULL;
}

static void*
writer( void *arg) {
   int i = 0;
   while( 1) {
      printf ( "inserting node at %d", i );
      i++;
   }
   return NULL;
}

int 
main( int argc, char **argv ) {
   dll_node* dll = (dll_node *) calloc( 1, sizeof( dll_node ) );
   pthread_t reader_th, writer_th;
   pthread_attr_t attr;
   
   //Create reader thread
   pthread_create( 
   //Create writer thread
}
