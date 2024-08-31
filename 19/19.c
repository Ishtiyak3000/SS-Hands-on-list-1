/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 19. Write a program to find out time taken to execute getpid system call. Use time 
  stamp counter. 
  ============================================================================================*/
#include <sys/time.h> 
#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>    
#include <x86intrin.h>
int main()
{
    int start = __rdtsc();       
    int  pid = getpid();        
    int end = __rdtsc();           
    printf("Time taken : %d cycles\n", (end - start)); 
  return 0;
}
/*sample output:
Time taken : 12181 cycles
*/