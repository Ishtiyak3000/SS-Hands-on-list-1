/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 30 AUG 2024
  ============================================================================================
  Question 25. Write a program to create three child processes. The parent should wait for a
  particular child (use waitpid system call).
  ============================================================================================*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int  child_1,child_2,child_3;
    
    if ((child_1=fork())==0)
    {   
        sleep(2);
    }
    else if ((child_2 = fork())==0)
    {
         sleep(20);
    }
    else if ((child_3 = fork())==0)
    {
         sleep(4);
    }
    else
    {
        waitpid(child_2, NULL, 0);
    }
    return 0;
}