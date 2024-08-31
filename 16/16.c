/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 26 AUG 2024
  ============================================================================================
  Question 16. Write a program to perform mandatory locking.
  a. Implement write lock
  b. Implement read lock
  ============================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{

  int fd = open("sample.txt", O_RDWR);
  int pid = getpid();
  struct flock lock = {F_WRLCK, SEEK_SET, 0, 0, pid};

  // a-Applying write lock
  printf("Press Enter to apply write lock\n");
  getchar();
  fcntl(fd, F_SETLKW, &lock);
  printf("Write lock applied. Press Enter to release it \n");
  getchar();
  lock.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &lock);
  printf("Write lock released.\n");

  // b-Applying read lock

  printf("Press Enter to apply Read Lock\n");
  getchar();
  lock.l_type = F_RDLCK;
  fcntl(fd, F_SETLKW, &lock);
  printf("Read lock applied. Press Enter to release it\n");
  getchar();
  lock.l_type = F_UNLCK;
  fcntl(fd, F_SETLK, &lock);
  printf("Read lock released.\n");


  close(fd);
  return 0;
}
