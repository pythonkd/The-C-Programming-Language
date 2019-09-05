#include <stdio.h>

int main(void)
{
    char *s = "asdhdash";
    *s = 'a';
    printf("%s", s);
    return 0;
}
