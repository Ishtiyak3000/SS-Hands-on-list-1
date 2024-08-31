/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 26 AUG 2024
  ============================================================================================
  Question 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper 
  print statement to verify whether the data is available within 10 seconds or not 
  (check in $man 2 select).
  ============================================================================================*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
int main() 
 {
    fd_set fdsbuffer;
    struct timeval timeout;
    FD_ZERO(&fdsbuffer);
    FD_SET(STDIN_FILENO, &fdsbuffer);
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    int val = select(1, &fdsbuffer, NULL, NULL, &timeout);
    if (val == -1) {
        perror("select() error");
    } else if (val>0) {
        printf("Data is available on STDIN within 10 seconds.\n");
    } else {
        printf("No data was entered on STDIN within 10 seconds.\n");
    }

    return 0;
}

