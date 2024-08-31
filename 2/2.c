/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 2.Write a simple program to execute in an infinite loop at the background. Go to 
  /proc directory and identify all the process related information in the corresponding proc 
   directory. 
  ============================================================================================*/
#include <stdio.h>
int main()
{
   while(1);
   return 0;
//    To run it in background, after compiling we can run command './a.out &' after that a pid
//    will be displayed now we can go to cd /proc/pid and then run ls -l to see all information
}