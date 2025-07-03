#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child Process (New State): PID = %d\n", getpid());
        printf("Child Process: Entering Ready State (waiting for CPU)...\n");
        sleep(1);
        printf("Child Process (Running State): Now I am executing my task.\n");
        sleep(2);
        printf("Child Process: Entering Waiting State (sleeping for 3 seconds)...\n");
        sleep(3);
        printf("Child Process: Now I am terminating (Terminated State)\n");
        _exit(0);
    } else if (pid > 0) {
        printf("Parent Process (New State): PID = %d, Child PID = %d\n", getpid(), pid);
        printf("Parent Process: Entering Ready State (waiting for CPU)...\n");
        sleep(1);
        printf("Parent Process (Running State): Now I am executing.\n");
        sleep(2);
        printf("Parent Process: Entering Waiting State (waiting for child to finish)...\n");
        wait(NULL);
        printf("Parent Process: Child has terminated. Now I am terminating (Terminated State)\n");
    } else {
        printf("Fork failed. Unable to create process.\n");
    }

    return 0;
}
