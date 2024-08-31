/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 31 AUG 2024
  ============================================================================================
  Question 5.. Write a program to create five new files with infinite loop. Execute the program 
  in the background and check the file descriptor table at /proc/pid/fd
 
  ============================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
   
    char *filenames[5] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
    for (int i = 0; i < 5; i++) {
        int fd = open(filenames[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        printf("Created %s with file descriptor %d\n", filenames[i], fd);
    }
    while (1) {
        sleep(1);
    }
    return 0;
}
/*sample output:
[1] 7811
Created file1.txt with file descriptor 3
Created file2.txt with file descriptor 4
Created file3.txt with file descriptor 5
Created file4.txt with file descriptor 6
Created file5.txt with file descriptor 7
*/