#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
void main(int argc,char *argv[])
{
  int pid;
  pid = fork();
  if(pid < 0){
   fprintf(stderr, "Fork failed.");
   exit(-1);
  }
  else if(pid==0){
   execvp(argv[1], &argv[1]);
   perror("Exec failed.");
  }
  else{
   wait((int *)0);
   printf("Prog3 is Complete.\n");
   exit(0);
  }
  exit(0);
}



