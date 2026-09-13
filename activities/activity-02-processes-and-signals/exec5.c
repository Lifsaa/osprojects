#include <stdio.h>
#include <unistd.h>

/*
The program must print its process id (getpid) and its parent's process id (getppid).
The program must print something else and each must print something different. What each prints is entirely up to you.
The program must exec the "next" program in the sequence (you will define the sequence of these programs through this step).
*/

int main(void) {
    printf("exec5: pid=%d, parent pid=%d\n", getpid(), getppid());
    printf("this is the fifth program\n");
    fflush(stdout);

    return 0;

}
