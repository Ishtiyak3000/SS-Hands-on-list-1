/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 7. Write a program to copy file1 into file2 ($cp file1 file2).
  ============================================================================================*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
   //Initially source file contains some information and Destination file is empty
   // We can also do it by giving file names from command line arguments 

    char buffer[1024];
    int bytes_read;
    int source_fd= open("source.txt", O_RDONLY);
    int destination_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC,0600);
    while (bytes_read = read(source_fd, buffer,1024)) {
        write(destination_fd, buffer, bytes_read);  
    }
    close(source_fd);
    close(destination_fd);
    return 0;
}
// you can check output in destination.txt file