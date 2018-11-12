#include "types.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"

int
drvmemread(struct inode *ip, char *dst, uint off, int n)
{
  return 0;
}

int
drvmemwrite(struct inode *ip, char *buf, uint off, int n)
{
  return 0;
}

void
drvmeminit(void)
{
  devsw[DRVMEM].write = drvmemwrite;
  devsw[DRVMEM].read = drvmemread;
}
