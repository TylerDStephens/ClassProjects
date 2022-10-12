#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
main(){
 char *path, *argv[20], buf[80], n, *p;
 int m, status, inword, continu;
 while(1) {
    inword = 0;
    p = buf;
    m = 0;
    continu=0;
    printf( "\nshhh> ");
    while ( ( n = getchar() ) != '\n'  || continu ) {
        if ( n ==  ' ' ) {
            if ( inword ) {
                inword = 0;
                *p++ = 0;
            }
        }
        else if ( n == '\n' ) continu = 0;
        else if ( n == '\\' && !inword ) continu = 1;
        else {
            if ( !inword ) {
                inword = 1;
                argv[m++] = p;
                *p++ = n;
            }
            else{
                *p++ = n;
            }
        }
    }
    *p++ = 0;
    argv[m] = 0;
    //No need to change anything above. Your program will continue from here.
    if ( strcmp(argv[0],"exit") == 0 ){exit (0);}
    int i=0, j=0, m=0, k[20], kit = 1; k[0]=0;
    char inp[20], out[20];
    int input = 0, output = 0, f;
    int pipes = 0, pid;
    int right_fd[2], left_fd[2];
    for(j = 0; argv[j] != 0; j++){
        if(strcmp(argv[j], "<") == 0){
            strcpy(inp,argv[j+1]);
            argv[j] = 0;
            input = 1;
        }
        else if(strcmp(argv[j], ">") == 0){
            strcpy(out, argv[j+1]);
            argv[j] = 0;
            output = 1;
        }
        else if(strcmp(argv[j], "|") == 0){
            argv[j] = 0;
            k[kit] = j + 1;
            pipes++;
            kit++;
        } 
    }kit--;
    for(i = 0; i <= pipes; i++){
        if (pipes > 0 && i != pipes){//create a right pipe
            pipe(right_fd);
        }
        pid = fork();
        if (pid < 0){
            printf("Error");
            exit(-1);
        }
        else if (pid > 0){
            if (i > 0) {
                close(left_fd[0]);
                close(left_fd[1]);
            }
            left_fd[0] = right_fd[0];
            left_fd[1] = right_fd[1];
            wait(&status);
        }
        else{ 
            if( input == 1 && i == 0){
                // deal with input redirection
                f = open(inp, O_RDONLY);
                close(0);
                dup(f);
                close(f);
            }
            if(pipes > 0){
            	if (i == 0){
                    close(1);
                    dup(right_fd[1]);
                    close(right_fd[1]);
                    close(right_fd[0]);
                }
            	else if (i < pipes){
                    close(0);
                    dup(left_fd[0]);
                    close(left_fd[0]);
                    close(left_fd[1]);
                    close(1);
                    dup(right_fd[1]);
                    close(right_fd[0]);
                    close(right_fd[1]);
            	}
                else{
                    close(0);
                    dup(left_fd[0]);
                    close(left_fd[0]);
                    close(left_fd[1]);
           	}
	    }
            if( output == 1 && pipes == i){
                //deal with output redirection
                f = open(out, O_WRONLY);
                close(1);
                dup(f);
                close(f);
            }  
        execvp(argv[k[i]], &argv[k[i]]);
        perror("execution of command failed\n");
      }
      //execvp(argv[k[i]], &argv[k[i]]);
      //perror("execution of command failed\n");    
    }
   wait(&status);
   int q;//Reset the two arrays
   for(q = 0; q <= 20; q++){
    argv[q] = 0;
    k[q] = 0;
  }
 }
}
