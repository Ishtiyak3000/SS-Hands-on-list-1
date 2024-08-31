/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 20. Find out the priority of your running program. Modify the priority with nice 
  command.
  ============================================================================================*/
#include<stdio.h>
#include <sys/resource.h>
#include<unistd.h>
int main()
{
int pid=getpid();
int priority_before= getpriority(PRIO_PROCESS, pid);
printf("Pid=%d has priority %d \n",pid,priority_before);
nice(10);
int priority_after = getpriority(PRIO_PROCESS, getpid());
printf("Priority after using nice = %d\n", priority_after);
return 0;
}
/* Sample output:
Pid=35121 has priority 0 
Priority after using nice = 10
*/