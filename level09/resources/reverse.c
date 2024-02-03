#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    int fd = open(argv[1], O_RDONLY);
    char buff[4096];
    int ret = read(fd, buff, 4096);
    int log = open("output", O_APPEND);
    for (int i = 0; i < ret; i++)
    {
        char c = buff[i];
        c -= i;
        write(1,&c,1);
    }
}
