/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 25 AUG 2024
  ============================================================================================
  Question 9. Write a program to print the following information about a given file.
  a. inode
  b. number of hard links
  c. uid
  d. gid
  e. size
  f. block size
  g. number of blocks
  h. time of last access
  i. time of last modification
  j. time of last change
  ============================================================================================*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main()
{

    struct stat buffer;
    stat("source.txt", &buffer);
    printf("Inode:  %ld\n", buffer.st_ino);
    printf("Number of hardlinks:  %ld\n", buffer.st_nlink);
    printf("UID:  %d\n", buffer.st_uid);
    printf("GID:  %d\n", buffer.st_gid);
    printf("Size:  %ld\n", buffer.st_size);
    printf("Block Size:  %ld\n", buffer.st_blksize);
    printf("Number of Blocks:  %ld\n", buffer.st_blocks);
    printf("Time of last access:  %s", ctime(&buffer.st_atime));
    printf("Time of last modification:  %s", ctime(&buffer.st_mtime));
    printf("Time of last change:  %s", ctime(&buffer.st_ctime));
    return 0;
}
/*sample output:
Inode:  7610612
Number of hardlinks:  1
UID:  1000
GID:  1000
Size:  51
Block Size:  4096
Number of Blocks:  8
Time of last access:  Sun Aug 25 18:45:49 2024
Time of last modification:  Sun Aug 25 18:45:49 2024
Time of last change:  Sun Aug 25 18:45:49 2024
*/