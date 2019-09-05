#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("./lsls filename\n");
        exit(-1);
    }
    struct stat st;
    int ret = stat(argv[1], &st);
    if (ret == -1)
    {
        perror("stat error");
        exit(-1);
    }
    int size = (int)st.st_size;
    printf("%d\n", size);
    return 0;
}
