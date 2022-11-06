
#include <stdlib.h>

#include "lucere2d.h"

void Cleanup() {
}

int main( int argc, char** argv ) {
  atexit( Cleanup );

  return 0;
}
