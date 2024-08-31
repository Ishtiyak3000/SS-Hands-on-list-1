/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 30 AUG 2024
  ============================================================================================
  Question 28. Write a program to get maximum and minimum real time priority.
  ============================================================================================*/
#include <stdio.h>
#include <sched.h>
int main()
{

    int maxfifo = sched_get_priority_max(SCHED_FIFO);
    int minfifo = sched_get_priority_min(SCHED_FIFO);
    int maxrr = sched_get_priority_max(SCHED_RR);
    int minrr = sched_get_priority_min(SCHED_RR);
    printf("Maximum real-time priority (SCHED_FIFO): %d\n", maxfifo);
    printf("Minimum real-time priority (SCHED_FIFO): %d\n", minfifo);
    printf("Maximum real-time priority (SCHED_RR): %d\n", maxrr);
    printf("Minimum real-time priority (SCHED_RR): %d\n", minrr);

    return 0;
}
/*sample output:
Maximum real-time priority (SCHED_FIFO): 99
Minimum real-time priority (SCHED_FIFO): 1
Maximum real-time priority (SCHED_RR): 99
Minimum real-time priority (SCHED_RR): 1
*/