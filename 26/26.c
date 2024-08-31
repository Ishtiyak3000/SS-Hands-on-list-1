/*Name-Ishtiyak Ahmad Khan
  Roll No-MT2024062
  Date :- 30 AUG 2024
  ============================================================================================
  Question 26. Write a program to execute an executable program.
  a. use some executable program
  b. pass some input to an executable program. (for example execute an executable of $./a.out name)
  ============================================================================================*/
  #include <stdio.h>
#include <unistd.h>

int main(int arg,char *args[]) {
  
    char *executable = "./helper";
    char *arg1 = args[1];
    execlp(executable, executable, arg1, (char *)NULL);
    
    return 1;
}
// In the helper program John + the argument passed is printed
// which is Cena .To check correctness run: ./a.out Cena
/*sample output
John Cena
*/
