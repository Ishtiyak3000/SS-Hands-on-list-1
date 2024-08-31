/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 17-P1- Write a program to open a file, store a ticket number and exit. Write a separate 
  program, to open the file, implement write lock, read the ticket number, increment the 
  number and print the new ticket number then close the file.
  ============================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct booking 
{
    int ticket_number;
};

int main() {
    //This is first program to open the file and writing a ticket number
    struct booking passenger;
    passenger.ticket_number = 62;
    int fd = open("ticket", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, &passenger, sizeof(passenger));
    printf("Ticket number: %d\n", passenger.ticket_number);
    close(fd);

    return 0;
}
