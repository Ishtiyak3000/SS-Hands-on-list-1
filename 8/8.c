/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 8.Write a program to open a file in read only mode, read line by line and display 
  each line as it is read.Close the file when end of file is reached.
  ============================================================================================*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    char buff[2];
    int fd=open("source.txt",O_RDONLY);
    while(read(fd,buff,1))
    {
        if(buff[0]=='\n') getchar();
        else printf("%c",buff[0]);
    }
}
/*sample output:
Hello i am ishtiyak ahmad khan
from iiit bangalore
*/