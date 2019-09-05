#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define STDOUT 1
#define STDIN 0


int main(void)
{
    pid_t pid;
    int fd[2];
    pipe(fd);
    pid = fork();
    if (pid == -1)
    {
        perror("fork error");
        exit(-1);
    }
    if (pid == 0) //子进程 读
    {
        close(fd[1]);
        printf("当前子进程ID:%d\n", getpid());
        dup2(fd[0], STDIN);
        execlp("grep", "grep", "--color=auto", "bash", NULL);
    }
    else //父进程 写 回收子进程
    {
        close(fd[0]);
        printf("回收了子进程：%d\n", pid);
        dup2(fd[1], STDOUT);
        execlp("ps", "ps", "aux", NULL);
        pid = wait();
        if (pid == -1)
        {
            perror("wait");
            exit(-1);
        }
    }
    return 0;
}
