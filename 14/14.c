/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 26 AUG 2024
  ============================================================================================
  Question 14 Write a program to find the type of a file.
  a. Input should be taken from command line.
  b. program should be able to identify any type of a file. 
  ============================================================================================*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat fileinfo;
    lstat(argv[1], &fileinfo);
    if (S_ISREG(fileinfo.st_mode)) {
        printf("The file is a regular file.\n");
    } else if (S_ISDIR(fileinfo.st_mode)) {
        printf("The file is a directory.\n");
    } else if (S_ISLNK(fileinfo.st_mode)) {
        printf("The file is a symbolic link.\n");
    } else if (S_ISCHR(fileinfo.st_mode)) {
        printf("The file is a character device.\n");
    } else if (S_ISBLK(fileinfo.st_mode)) {
        printf("The file is a block device.\n");
    } else if (S_ISFIFO(fileinfo.st_mode)) {
        printf("The file is a FIFO (named pipe).\n");
    } else if (S_ISSOCK(fileinfo.st_mode)) {
        printf("The file is a socket.\n");
    } else {
        printf("The file type is unknown.\n");
    }

    return 0;
}
