#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    int ret = access("abc", F_OK);
    int fd;
    if (ret != 0)
    {
        ret =  mkfifo("abc", 0777);
        if (ret != 0)
        {
            perror("mkfifo");
            exit(-1);
        }
    }
    fd = open("abc", O_WRONLY);
    while(1)
    {
        sleep(1);
        char *str = "myname";
        write(fd, str, sizeof(str));
    }
    close(fd);
    return 0;
}
