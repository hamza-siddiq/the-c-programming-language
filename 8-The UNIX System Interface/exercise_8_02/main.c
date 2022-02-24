#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void filecopy(FILE *fp);
int main(int argc, char *argv[]) {
    int fd;

    seek(fd, 3, 3);     /* seek position */
    seek(fd, 464, 1);
    lseek(fd, 2000, 0); /* lseek equivalent */
}