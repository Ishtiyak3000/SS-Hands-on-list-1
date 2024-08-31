/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 3.Write a program to create a file and print the file descriptor value. Use 
  creat ( ) system call
  ============================================================================================*/
#include <fcntl.h> 
#include <unistd.h> 
#include <stdio.h>  

int main() {
   
    int fd = creat("sample.txt",0644);
    printf("File descriptor: %d\n", fd);
    close(fd);
    return 0;
}
/*sample output:
File descriptor: 3
*/