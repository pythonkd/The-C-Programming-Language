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
    else if (pid == 0)
    {
        printf("children will sleep(3) s\n");
        sleep(3);
        printf("children has died\n");
    }
    else
    {
        while (1)
        {
            int status;
            pid_t wpid = wait(&status);
            printf("wpid = %d \t status = %d\n",wpid, status);
            printf("parent will sleep 1 s\n");
            sleep(1);
        }
    }

    return 0;
}
