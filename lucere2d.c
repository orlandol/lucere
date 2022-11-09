
#include "lucere2d.h"
#include "l2dimpl.h"

/*
 *  Abstract graphics interface
 */

L2DDisplay* CreateDisplay( const L2DGraphicsInterface* graphicsInterface,
  unsigned monitorIndex, const char* appTitle, void* rsvd ) {

  L2DDisplay* newDisplay = NULL;

  if( graphicsInterface &&
    graphicsInterface->displayMethods.CreateDisplay ) {

    newDisplay = graphicsInterface->displayMethods.CreateDisplay(
      monitorIndex, appTitle, rsvd );
  }

  return newDisplay;
}

void ReleaseDisplay( L2DDisplay** displayPtr ) {
  if( displayPtr ) {
    if( (*displayPtr) && ((*displayPtr)->methods.ReleaseDisplay) ) {
      (*displayPtr)->methods.ReleaseDisplay( displayPtr );
    }
  }
}

L2DCanvas* CreateCanvas( L2DDisplay* display, unsigned width, unsigned height ) {
  L2DCanvas* newCanvas = NULL;

  if( display && display->methods.CreateCanvas ) {
    newCanvas = display->methods.CreateCanvas(display, width, height);
  }

  return newCanvas;
}

void ReleaseCanvas( L2DCanvas** canvasPtr ) {
  if( canvasPtr ) {
    if( (*canvasPtr) && ((*canvasPtr)->methods.ReleaseCanvas) ) {
      (*canvasPtr)->methods.ReleaseCanvas( canvasPtr );
    }
  }
}
