/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 30 AUG 2024
  ============================================================================================
  Question 27. Write a program to execute ls -Rl by the following system calls
  c.execle
  ============================================================================================*/
#include <stdio.h>
#include <unistd.h>
int main() {
    char *envp[] = {NULL};
    execle("/bin/ls", "ls", "-Rl", (char *)NULL, envp);
    return 1;
}
/*Sample output:
total 36
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   901 Aug 31 00:50 Q27a.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   898 Aug 31 00:50 Q27b.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   931 Aug 31 00:50 Q27c.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   920 Aug 31 00:50 Q27d.c
-rw-rw-r-- 1 miaklinux3000 miaklinux3000   913 Aug 31 00:48 Q27e.c
-rwxrwxr-x 1 miaklinux3000 miaklinux3000 16008 Aug 31 00:50 a.out
*/