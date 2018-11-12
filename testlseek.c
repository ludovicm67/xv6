#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

int
main(int argc, char *argv[])
{
    int n;
    int fd;
    int offset;
    int nb;
    int nbToRead;
    int whence;

    int nbRead = 0;

    if (argc != 4) {
        printf(2, "usage: %s filename offset nb\n", argv[0]);
    }

    if ((fd = open(argv[1], 0)) < 0) {
        printf(1, "%s: cannot open %s\n", argv[0], argv[1]);
        exit();
    }

    offset = atoi(argv[2]);
    nb = atoi(argv[3]);
    nbToRead = sizeof(buf);
    whence = SEEK_SET;
    if (offset < 0) {
        whence = SEEK_END;
    }

    if (lseek(fd, offset, whence) < 0) {
        printf(1, "%s: lseek error\n", argv[0], argv[1]);
        exit();
    }

    if (nbToRead > nb) {
        nbToRead = nb;
    }
    
    n = read(fd, buf, nbToRead);
    while (n > 0) {
        if (write(1, buf, n) != n) {
            printf(1, "%s: write error\n", argv[0]);
            exit();
        }
        nbRead += n;
        nbToRead = sizeof(buf);
        if (nbRead + nbToRead > nb) {
            nbToRead = nb - nbRead;
        }
        n = read(fd, buf, nbToRead);
    }

    if (n < 0) {
        printf(1, "%s: read error\n", argv[0]);
        exit();
    }
    
    printf(1, "\n");

    if ((close(fd)) == -1) {
        printf(1, "%s: close error\n", argv[0]);
        exit();
    }

    exit();
}
