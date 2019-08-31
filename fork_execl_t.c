#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork error!");
        exit(-1);
    }
    else if (pid == 0)
    {
        execl("./pth", "pth", NULL);
    }
    else
    {
        sleep(1);
        printf("parent\n");
    }
    return 0;
}
