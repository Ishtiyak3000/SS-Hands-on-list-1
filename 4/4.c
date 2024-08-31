/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 4. Write a program to open an existing file with read write mode. Try O_EXCL flag 
  also. 
  ============================================================================================*/


#include <fcntl.h>  
#include <unistd.h>
#include <stdio.h>

int main() {
    //Opening the file without using O_EXCL
    int fd = open("sample.txt", O_RDWR);
    printf("File descriptor: %d\n", fd);
    close(fd);
    //Opening the file with O_EXCL
    fd = open("sample.txt", O_RDWR | O_EXCL);
    if(fd==-1) {perror("open O_RDWR | O_EXCL");return 1;}
    
    return 0;
}
/*sample output:
File descriptor: 3
*/