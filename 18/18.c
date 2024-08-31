/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 29 AUG 2024
  ============================================================================================
  Question 18-Write a program to perform Record locking.
  a. Implement write lock
  b. Implement read lock
  Create three records in a file. Whenever you access a particular record, first lock it then modify/access
  to avoid race condition.
  ============================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct booking {
    char name[20];
    int ticket_number;
} p[3], q[3], r[3];

void apply_write_lock(int fd, int offset, int length) {
    int pid = getpid();
    struct flock lock = {F_WRLCK, SEEK_SET, offset, length, pid};
    fcntl(fd, F_SETLKW, &lock);
}

void release_write_lock(int fd, int offset, int length) {
    int pid = getpid();
    struct flock lock = {F_UNLCK, SEEK_SET, offset, length, pid};
    fcntl(fd, F_SETLK, &lock);
}

void apply_read_lock(int fd, int offset, int length) {
    int pid = getpid();
    struct flock lock = {F_RDLCK, SEEK_SET, offset, length, pid};
    fcntl(fd, F_SETLKW, &lock);
}

void release_read_lock(int fd, int offset, int length) {
    int pid = getpid();
    struct flock lock = {F_UNLCK, SEEK_SET, offset, length, pid};
    fcntl(fd, F_SETLK, &lock);
}

void print_records(struct booking records[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Ticket No.: %d\n", records[i].name, records[i].ticket_number);
    }
}

int main() {
    char *namelist[] = {"Virat", "Dhoni", "Rohit"};
    for (int i = 0; i < 3; i++) {
        strcpy(p[i].name, namelist[i]);
        p[i].ticket_number = i + 5;
    }
    int fd = open("record", O_RDWR | O_CREAT | O_TRUNC, 0744);
    write(fd, p, sizeof(p));
    printf("Before Modification:\n");
    apply_read_lock(fd, 0, sizeof(p));
    lseek(fd, 0, SEEK_SET);
    read(fd, q, sizeof(q));
    print_records(q, 3);
    release_read_lock(fd, 0, sizeof(p));

    printf("Enter record no. you want to change:");
    int i;
    scanf("%d",&i);
    int offset = i * sizeof(struct booking);
    apply_write_lock(fd, offset, sizeof(struct booking));
    lseek(fd, offset, SEEK_SET);
    read(fd, &q[i], sizeof(struct booking));
    q[i].ticket_number = 62;
    lseek(fd, offset, SEEK_SET);
    write(fd, &q[i], sizeof(struct booking));
    release_write_lock(fd, offset, sizeof(struct booking));

    printf("\nRecords After Modification:\n");
    apply_read_lock(fd, 0, sizeof(p));
    lseek(fd, 0, SEEK_SET);
    read(fd, r, sizeof(r));
    print_records(r, 3);
    release_read_lock(fd, 0, sizeof(p));

    close(fd);
    return 0;
}
// Sample output
/*
Before Modification:
Name: Virat, Ticket No.: 5
Name: Dhoni, Ticket No.: 6
Name: Rohit, Ticket No.: 7
Enter record no. you want to change:0

Records After Modification:
Name: Virat, Ticket No.: 62
Name: Dhoni, Ticket No.: 6
Name: Rohit, Ticket No.: 7
*/