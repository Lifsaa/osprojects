#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <errno.h>


volatile sig_atomic_t timed_out = 0;

void on_alarm(int) {
    timed_out = 1;
}


int main(int argc, char** argv) {
    if(argc < 3 ) {
        printf("Prog should have exactly 3 args or more");
        return 1;
    }
    int seconds = atoi(argv[1]);

    pid_t child = fork();

    if (child == -1) {
        perror("fork");
        return 1;
    }

    if (child == 0) {
        execvp(argv[2], &argv[2]);
        perror("execvp");
        _exit(127);
    }
    struct sigaction action = {0};
    action.sa_handler = on_alarm;
    sigaction(SIGALRM, &action,NULL);

    struct itimerval timer = {0};
    timer.it_value.tv_sec = seconds;

    if(setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("settimer");
        return 1;
    }
    int status;
    pid_t result;
    result  = waitpid(child, &status,0);
    while (result == -1 && errno == EINTR && !timed_out) {
        result  = waitpid(child, &status,0);
    }
    if (timed_out) {
        printf("Poor child being killed ...\n");
        kill(child, SIGKILL);
        waitpid(child, &status, 0);
        return 1;
    }

    if (result == -1) {
        return 1;
    }

    struct itimerval remaining;
    getitimer(ITIMER_REAL, &remaining);
    printf("time left: %ld seconds\n", (long)remaining.it_value.tv_sec);

    if(WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    return 1;
}

/*Note: You may have written a program like this before. This may be slightly different
. Approach it from scratch to review the material.
Write a program, named my_timeout, that can be used to limit the duration of another program.
 my_timeout takes, as command-line arguments, an integer number of seconds and another command
 (optionally with arguments of its own). The my_timeout program must spawn a child process to
 execute the argument command (with its command-line arguments) and set an alarm (use setitimer with ITIMER_REAL)
  that will be triggered after the specified number of seconds (use sigaction). If the child process
 has not terminated by the time that the alarm has triggered, then it should be killed
 (and the exit status of my_timeout should be non-zero). If the child process terminates,
 then the amount of time remaining on the timer must be printed and the exit status of my_timeout
  should be that of the child process.
For example,
% my_timeout 5 sleep 10
Killing child ...
% echo $?
1
% my_timeout 10 sleep 5
time left: 4 seconds
% echo $?

A signal is a notification sent to a proc that something happened.
Here when timer runs out, OS sends parent proc SIALARM

Now a signal handler is a func we register to run when that signal arrive.
so my handler on_alarm is gonna set a sentiel value so that parent can see that limit expired

*/
