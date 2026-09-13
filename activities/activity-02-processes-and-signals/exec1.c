#include <stdio.h>
#include <unistd.h>

/*
The program must print its process id (getpid) and its parent's process id (getppid).
The program must print something else and each must print something different. What each prints is entirely up to you.
The program must exec the "next" program in the sequence (you will define the sequence of these programs through this step).
*/

int main(void) {
    printf("exec1: pid=%d, parent pid=%d\n", getpid(), getppid());
    printf("this is the first program\n");
    fflush(stdout);
    execl("./exec2", "exec2", (char*) NULL);

    perror("exec failed");
    return 1;

}
