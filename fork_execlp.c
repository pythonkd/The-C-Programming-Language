#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork error");
        exit(-1);
    }
    else if (pid > 1)
    {
        sleep(1);
        printf("parent\n");
    }
    else 
    {
        execl("/bin/ls", "ls", "-l", NULL);
    }
    return 0;
}
