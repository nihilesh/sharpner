// Copyright (c) 2016 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char* argv[]) {
   pid_t child_pid = 0;
   child_pid = fork();
   if (!child_pid ) {
      sleep (10);
      exit(0);
   }
   else {
      waitpid(child_pid, NULL, 0);
   }
   return 0;
}
