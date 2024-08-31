#include <stdio.h>
#include <unistd.h>
// To create a executable file
int main(int arguments,char *arg[]) {
  
      char *s="John";
      printf("%s  %s\n",s,arg[1]);
    return 0;
}