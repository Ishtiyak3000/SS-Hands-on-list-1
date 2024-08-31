#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

    int hour = atoi(argv[1]);
    int minute = atoi(argv[2]);
    if(fork()==0){
        setsid();
        chdir("/");
        umask(0);
        while(1){
            time_t now = time(NULL);
            struct tm *timeinfo = localtime(&now);
            if(timeinfo->tm_hour == hour && timeinfo->tm_min == minute)
            {
                system("./script.sh");
                exit(0);
            }
            else
            {
                printf("Daemon process is running...\n");
                sleep(30);
            }
        }
    }
    else 
        exit(0);
}