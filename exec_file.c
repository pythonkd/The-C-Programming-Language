#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define stdout 1

int main(void)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork error!");
        exit(-1);
    }
    else if (pid > 0)
    {
        sleep(1);
        printf("parent");
    }
    else
    {
        int fd = open("text.txt", O_WRONLY|O_CREAT);
        dup2(fd, stdout);
        execl("./pth", "pth", NULL);
    }
    return 0;
}
