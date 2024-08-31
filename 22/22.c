/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 22. Write a program, open a file, call fork, and then write to the file by both the 
  child as well as the parent processes. Check output of the file. 
  ============================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{

    char *parent_msg = "Parent Process!\n";
    char *child_msg = "Child Process!\n";
    int fd = open("sample.txt", O_WRONLY | O_CREAT, 0644);
    int pid = fork();
    if (pid == 0)
    {
        write(fd, child_msg, strlen(child_msg));
        
    }
    else
    {
        write(fd, parent_msg, strlen(parent_msg));
       
    }
    close(fd);

    return 0;
}
// Output is appended in sample.txt file
//Parent Process!
//Child Process!