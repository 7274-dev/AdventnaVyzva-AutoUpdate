#include <sys/types.h>
#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>

#include <unistd.h>

#define TIME_HOURS 2
#define TIME_MINUTES 0

void update(int time) {
    while (true) {
        system("bash deploy.sh");
        printf("Update Complete! Next update is scheduled in %d hours, and %d minutes", TIME_HOURS, TIME_MINUTES);
        sleep((unsigned int) time);
    }
}

int main() {
    #ifdef __WIN32
        printf("Linux only! Sorry bro\n");
        return 1;
    #endif
    int time_seconds = (TIME_HOURS * 3600) + (TIME_MINUTES * 60);
    if (geteuid() != 0) {
        printf("You need to have root privileges to run this script.\nPlease try again, this time using 'sudo'. Exiting.\n");
        return 1;
    }
    else {
        printf("Starting Daemon service.\n");
        update(time_seconds);
    }
}
