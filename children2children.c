#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define STDIN 0
#define STDOUT 1

int main(void)
{
    int fd[2];
    pipe(fd);
    int i;
    pid_t pid;
    int pid_nums[3];
    for (i=0; i<2; i++)
    {
        pid = fork();
        if (pid == 0) break;
    }
    if (i == 0) //子进程1 读
    {
        printf("pid = %d\t ppid = %d\n", getpid(), getppid());
        close(fd[1]);
        char buf[1024];
        int ret;
        ret = read(fd[0], buf, sizeof(buf));
        if (ret == -1)
        {
            perror("read error");
            exit(-1);
        }
        printf("%s\n", buf);
    }
    if (i == 1) //子进程2 写
    {
        printf("pid = %d\t, ppid = %d\n", getpid(), getppid());
        close(fd[0]);
        char s[] = "my name is zzz";
        write(fd[1], s, strlen(s));
    }
    else if (i == 2)
    {
        close(fd[0]);
        close(fd[1]);
        printf("pid = %d\n", getpid());
        for (i = 0; i< 2; i++)
        {
            wait();
        }
    }
    

    return 0;
}
