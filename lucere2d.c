
#include "lucere2d.h"
#include "impl.h"

/*
 *  General graphics interface
 */

L2DDisplay* CreateDisplay( const L2DGraphicsInterface* graphicsInterface, unsigned monitorIndex, void* rsvd ) {
  L2DDisplay* newDisplay = NULL;

  if( graphicsInterface && graphicsInterface->CreateDisplay ) {
    newDisplay = graphicsInterface->CreateDisplay(monitorIndex, rsvd);
  }

  return newDisplay;
}

void ReleaseDisplay( L2DDisplay** displayPtr ) {
  if( displayPtr ) {
    if( (*displayPtr) ) {
      (*displayPtr)->ReleaseDisplay( displayPtr );
    }
  }
}

L2DCanvas* CreateCanvas( L2DDisplay* display, unsigned width, unsigned height ) {
  return NULL;
}

void ReleaseCanvas( L2DCanvas** canvasPtr ) {
  if( canvasPtr ) {
    if( (*canvasPtr) ) {
      (*canvasPtr)->ReleaseCanvas( canvasPtr );
    }
  }
}
