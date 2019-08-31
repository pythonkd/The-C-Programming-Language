#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int i;
    pid_t pid;
    int n = 3;
    for (i=0 ;i < n; i++)
    {
        pid = fork();
        if (pid == 0 && i == 0)
        {
            execl("/bin/ps", "ps", "-aux", NULL);
            break;
        }
        else if (pid == 0 && i == 1)
        {
            execl("./se", "se", NULL);
            break;
        }
        else if (pid == 0 && i == 2)
        {
            execl("./rt", "ri", NULL);
            break;
        }
    }

    do
    {
        pid = waitpid(-1, NULL, WNOHANG);
        if (pid > 0) n--;
    }while (n > 0);
    sleep(30);
    printf("parent 结束了\n");
    return 0;
}
