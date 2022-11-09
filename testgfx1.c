
#include <stdlib.h>
#include <stdio.h>

#include "lucere2d.h"

L2DDisplay* display = NULL;
L2DCanvas* canvas = NULL;

void Cleanup() {
  ReleaseCanvas( &canvas );
  ReleaseDisplay( &display );
}

int main( int argc, char** argv ) {
  atexit( Cleanup );

  display = CreateDisplay(&giWinGDI, 0, "TestGfx1", NULL);
  canvas = CreateCanvas(display, 0, 0);

  Cleanup();

  return 0;
}
