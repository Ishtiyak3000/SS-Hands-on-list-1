/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 30 AUG 2024
  ============================================================================================
  Question 29. Write a program to get scheduling policy and modify the scheduling policy 
  (SCHED_FIFO,SCHED_RR).
  
  ============================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int  pid = getpid(); 
    int current_policy = sched_getscheduler(pid);
    struct sched_param param={1};
    if(current_policy==0) printf("Current Scheduling policy is Normal\n");
    else if(current_policy==1)printf("Current Scheduling policy is FIFO");
    else if(current_policy==2) printf("Current Scheduling policy is RR");
    sched_setscheduler(pid, 1, &param);
    printf("Scheduling policy changed to FIFO\n");
    sched_setscheduler(pid, 2, &param) ;
    printf("Scheduling policy changed to RR\n");
    return 0;
}
/*sample output
Current Scheduling policy is Normal
Scheduling policy changed to FIFO
Scheduling policy changed to RR
*/
