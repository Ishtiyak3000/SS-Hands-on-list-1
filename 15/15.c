/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 26 AUG 2024
  ============================================================================================
  Question 15. Write a program to display the environmental variable of the user (use environ) 
  ============================================================================================*/
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {

    for (char **env = environ; *env; env++) {
        printf("%s\n", *env);
    }

    return 0;
}
