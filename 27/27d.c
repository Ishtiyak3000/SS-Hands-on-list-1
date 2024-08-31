/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 30 AUG 2024
  ============================================================================================
  Question 27. Write a program to execute ls -Rl by the following system calls
  d.execv
  ============================================================================================*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    execv("/bin/ls", args);
   
    return 1;
}
/*Sample output:
-rwxrwxr-x 1 miaklinux3000 miaklinux3000 16000 Aug 31 00:51 a.out
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   901 Aug 31 00:50 Q27a.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   898 Aug 31 00:50 Q27b.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   931 Aug 31 00:50 Q27c.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   920 Aug 31 00:50 Q27d.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   913 Aug 31 00:48 Q27e.c
*/