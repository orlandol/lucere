
#include <stdlib.h>
#include <stdio.h>

#include "lucere2d.h"

L2DDisplay* display = NULL;
L2DApp* app = NULL;
L2DCanvas* canvas = NULL;

void Cleanup() {
  ReleaseCanvas( &canvas );
  ReleaseApp( &app );
  ReleaseDisplay( &display );
}

int main( int argc, char** argv ) {
  atexit( Cleanup );

  display = CreateDisplay(&giWinGDI, 0);
  app = CreateAppFromDisplay(display, "TestGfx1", NULL);
  canvas = CreateCanvas(display, 0, 0);

  while( AppIsOpen(app) ) {
  }

  Cleanup();

  return 0;
}
