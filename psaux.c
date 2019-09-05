#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#define stdout 1
#define stdin 0

int main(int argc, char* argv[])
{
    int fd[2];
    pipe(fd);
    
    pid_t pid = fork();
    
    if (pid == -1)
    {
        perror("fork error");
        exit(-1);
    }
    else if (pid == 0) //子进程
    {
        int ret = 1;
        close(fd[1]);
        dup2(fd[0], stdin);
        execlp("grep", "grep", "--color=auto","bash", NULL);
    }
    else //父进程 写
    {
        close(fd[0]);
        dup2(fd[1], stdout);
        execlp("ps", "ps", "aux", NULL);
    }
    return 0;
}

