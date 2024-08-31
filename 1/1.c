/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 1. Create the following types of a files using (i) shell command (ii) system call
  a. soft link (symlink system call)
  b. hard link (link system call)
  c. FIFO (mkfifo Library Function or mknod system call)
  ============================================================================================*/

#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
int main() {
  //a- Creating Soft link using symlink system call
    symlink("sample.txt", "softlink");
   //b-Creating Hard link using link system call
   link("sample.txt","hardlink");
   //c-making FIFO file
   mkfifo("fifo",0644);



  //using shell we can run these commands
  system("ln -s sample.txt softlinkshell");//soft link
  system("ln sample.txt hardlinkshell");// hard link
  system("mkfifo fifoshell");//fifo file

    return 0;
}
