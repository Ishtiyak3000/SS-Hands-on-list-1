/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 24 .Write a program to create an orphan process.
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
        exit(0);
    else { 
        sleep(10);      
        exit(0); 
    }
    return 0; 
} 