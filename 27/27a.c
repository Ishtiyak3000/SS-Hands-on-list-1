/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 30 AUG 2024
  ============================================================================================
  Question 27. Write a program to execute ls -Rl by the following system calls
  a. execl
  ============================================================================================*/
#include <stdio.h>
#include <unistd.h>

int main() {
  
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);
    return 1;
}
/*Sample output:
total 36
-rwxrwxr-x 1 miaklinux3000 miaklinux3000 15952 Aug 31 00:47 a.out
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   472 Aug 31 00:40 Q27a.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   469 Aug 31 00:41 Q27b.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   502 Aug 31 00:43 Q27c.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   491 Aug 31 00:45 Q27d.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   484 Aug 31 00:46 Q27e.c
*/