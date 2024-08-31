/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 12. Write a program to find out the opening mode of a file. Use fcntl.
  ============================================================================================*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int fd = open("sample.txt", O_RDWR);

    int flags = fcntl(fd, F_GETFL);
    if ((flags & 3) == 0)
    {
        printf("The file is opened in read-only mode.\n");
    }
    else if ((flags & 3) == 1)
    {
        printf("The file is opened in write-only mode.\n");
    }
    else if ((flags & 3) == 2)
    {
        printf("The file is opened in read-write mode.\n");
    }
    else
    {
        printf("Unknown file opening mode.\n");
    }
    close(fd);
    return 0;
}
