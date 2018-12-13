#include "types.h"
#include "spinlock.h"

void ncallsinit();

struct ncalls {
  int total;
  int proc;
};

// struct for the first part (total syscall count)
struct ncalls1 {
  int nb_calls; // gloal int containing the number of syscalls since boot
  struct spinlock lock;
};
struct ncalls1 nc1;