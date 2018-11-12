#include "types.h"
#include "user.h"

int main(int argc, char * argv[]) {
  char * filename;
  short major;
  short minor;

  if (argc != 4) {
    printf(2, "usage: %s filename major minor\n", argv[0]);
    exit();
  }

  filename = argv[1];
  major = atoi(argv[2]);
  minor = atoi(argv[3]);

  if (mknod(filename, major, minor) < 0) {
    printf(2, "%s: mknod error\n", argv[0]);
    exit();
  }

  exit();
}