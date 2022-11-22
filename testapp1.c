
#include <stdlib.h>
#include <stdio.h>

#include "lucere2d.h"

L2DApp* app = NULL;

void Cleanup() {
  ReleaseApp( &app );
}

int main( int argc, char** argv ) {
  atexit( Cleanup );

  app = CreateApp(0, 0, "TestApp1", NULL);

  while( AppIsOpen(app) ) {
  }

  Cleanup();

  return 0;
}
