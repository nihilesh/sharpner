#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void do_something(){
   while(true) {
	cout << "Sleeping for 10 sec" << endl;
	sleep(10);
   }
}

int main (void) {
    struct sigaction sa;
    sa.sa_handler = SIG_IGN; //handle signal by ignoring
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGCHLD, &sa, 0) == -1) {
        perror(0);
        exit(1);
    }
    int pid = fork();
    if (pid == 0) { //child process
        _exit(0);
    }

    cout << "Child : " << pid << endl;
    do_something(); //parent process
    return 0;
}
