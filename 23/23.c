/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 23.Write a program to create a Zombie state of the running program.
  ============================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() 
{ 
   
    int  pid = fork();   
    if (pid > 0) 
    {
        sleep(30); 
        wait(NULL);}
    else        
        exit(0); 
  
    return 0; 
} 
