#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("abc", O_RDONLY);
    char buf[1024];
    while (1)
    {
        sleep(1);
        int ret = read(fd, buf, sizeof(buf));
        if (ret == -1)
        {
            perror("read error");
            exit(-1);
        }
        if (ret != 0)
            printf("%s\n", buf);
    }
    close(fd);
    return 0;
}
