/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 11. Write a program to open a file, duplicate the file descriptor and append the 
  file with both the descriptors and check whether the file is updated properly or not.
  a. use dup
  b. use dup2
  c. use fcntl
  ============================================================================================*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

    char *text[4] = {"Ishtiyak ", "Ahmad ", "Khan ", "MT2024062"};
    char **ptr = text;
    int fd = open("sample.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);

    write(fd, *ptr, strlen(*ptr));
    printf("Checking output After Appending with original fd:\n======================\n");
    system("cat sample.txt");
    printf("\n======================\n");

    // a- Duplicating using dup then appending it

    int fd_dup = dup(fd);
    write(fd_dup, *(ptr + 1), strlen(*(ptr + 1)));
    printf("Checking output After Appending with dup fd:\n======================\n");
    system("cat sample.txt");
    printf("\n======================\n");

    // b-Duplicating using dup2 then further appending it

    int fd_dup2 = dup2(fd, 62);
    write(fd_dup2, *(ptr + 2), strlen(*(ptr + 2)));

    printf("Checking output After Appending with dup2 fd:\n======================\n");
    system("cat sample.txt");
    printf("\n======================\n");

    // c-Duplicating using fcntl then further appending it

    int fd_fcntl = fcntl(fd, F_DUPFD, 300);
    write(fd_fcntl, *(ptr + 3), strlen(*(ptr + 3)));
    printf("Checking output After Appending with fcntl fd:\n======================\n");
    system("cat sample.txt");
    printf("\n======================\n");

    close(fd_fcntl);
    close(fd_dup2);
    close(fd_dup);
    close(fd);
    return 0;
}
// sample output
/*
Checking output After Appending with original fd:
======================
Ishtiyak 
======================
Checking output After Appending with dup fd:
======================
Ishtiyak Ahmad 
======================
Checking output After Appending with dup2 fd:
======================
Ishtiyak Ahmad Khan 
======================
Checking output After Appending with fcntl fd:
======================
Ishtiyak Ahmad Khan MT2024062
======================
*/