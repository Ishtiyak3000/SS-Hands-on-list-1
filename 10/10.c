/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 10. Write a program to open a file with read write mode, write 10 bytes, move the 
  file pointer by 10 bytes (use lseek) and write again 10 bytes.
  a. check the return value of lseek
  b. open the file with od and check the empty spaces in between the data. 
  ============================================================================================*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    char *first10bytes = "IshtiyakAh";
    char *second10bytes = "madKhan062";
    int fd = open("sample.txt", O_RDWR | O_CREAT, 0644);
    write(fd, first10bytes, 10);
    long int offset = lseek(fd, 10, SEEK_CUR);
    printf("File pointer moved to position: %ld\n", offset);
    write(fd, second10bytes, 10);
    close(fd);
    printf("Checking spaces in file by od command:\n");
    system("od -c sample.txt");
    return 0;
}
// ouput is appended in file sample.txt