#include "types.h"
#include "defs.h"
#include "ncalls.h"

void
ncallsinit()
{
  initlock(&nc1.lock, "nc1");
}