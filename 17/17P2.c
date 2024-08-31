/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 17-P2- Write a program to open a file, store a ticket number and exit. Write a separate 
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
int main()
{
  // this is the second program to read the ticket number and incrementing it then printing it
  struct booking passenger;
  int fd = open("ticket", O_RDWR);
  int pid = getpid();
  struct flock lock = {F_WRLCK, SEEK_SET, 0, 0, pid};
  fcntl(fd, F_SETLKW, &lock);
  read(fd, &passenger, sizeof(passenger));
  passenger.ticket_number++;
  printf("Ticket Number : %d\n",passenger.ticket_number);
  lock.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &lock);
  close(fd);
  return 0;
}
