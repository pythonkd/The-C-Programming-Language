#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
    int fd = open("aa", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
        exit(-1);
    }
    int ret = lseek(fd, 0, SEEK_END);
    printf("file length= %d\n", ret);

    ret =lseek(fd, 2000, SEEK_END);
    printf("return value %d\n", ret);

    write(fd, "a", 1);
    close(fd);
    return 0;
}
