/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 21. Write a program, call fork and print the parent and child process id. 
  ============================================================================================*/
#include <stdio.h>
#include <unistd.h>

int main()
{

    int pid = fork();

    if (pid == 0)
    {

        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
/*sample output
Parent Process: PID = 35275, Child PID = 35276
Child Process: PID = 35276, Parent PID = 35275
*/