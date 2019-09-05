#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int pp[2];
    pipe(pp);
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork error");
        exit(-1);
    }
    if (pid == 0) //父进程写入
    {
        close(pp[0]);
        char* str = "my name is zhao kun peng";
        write(pp[1], str,(size_t)strlen(str));
    }
    else
    {
        close(pp[1]);
        char buf[1024];
        int ret = read(pp[0], buf, sizeof(buf));
        if (ret == 0) printf("---------\n");
        printf("%s\n", buf);
    }
    return 0;
}
