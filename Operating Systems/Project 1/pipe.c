#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
void main()
{
  int pid, p[2];
  pipe(p);
  pid = fork();
  if(p == -1)
  {
   perror("pipe call");
   exit(1);
  }
  if(pid < 0){
   fprintf(stderr, "Fork failed");
   exit(-1);
  }
  else if(pid == 0){
  close(1);
  dup(p[1]);
  close(p[0]);
  close(p[1]);
  write(p[1], execl("./pre", "pre", 0), NULL);
  }
  else{
  wait(NULL);
  close(0);
  dup(p[0]);
  close(p[1]);
  close(p[0]);
  read(p[0], execl("./sort", "sort", 0), NULL);
  exit(0);
  }
}
