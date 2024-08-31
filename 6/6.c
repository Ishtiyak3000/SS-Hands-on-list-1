/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 6. Write a program to take input from STDIN and display on STDOUT. Use only read
  write system calls 
  ============================================================================================*/
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
int main() {
    char buffer[1024];
    int bytesRead, bytesWritten;
    while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
          write(STDOUT_FILENO, buffer, bytesRead);
    }

    return 0;
}
/*Sample output:
HELLO I AM UNDERWATER
HELLO I AM UNDERWATER
*/