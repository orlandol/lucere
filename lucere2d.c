
#include "lucere2d.h"
#include "l2dimpl.h"

/*
 *  Abstract display implementation
 */

L2DDisplay* CreateDisplay( const L2DGraphicsInterface* graphicsInterface,
  unsigned monitorIndex ) {

  L2DDisplay* newDisplay = NULL;

  if( graphicsInterface &&
    graphicsInterface->displayMethods.CreateDisplay ) {

    newDisplay =
      graphicsInterface->displayMethods.CreateDisplay(monitorIndex);
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

/*
 *  Abstract canvas implementation
 */

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

/*
 *  Abstract app implementation
 */

L2DApp* CreateAppFromDisplay( L2DDisplay* display,
  const char* title, L2DEventRouter* eventRouter ) {

  return NULL;
}

L2DApp* CreateApp( unsigned with, unsigned height,
  const char* title, L2DEventRouter* eventRouter ) {

  return NULL;
}

void ReleaseApp( L2DApp** appPtr ) {
}

void ExitApp( L2DApp* app, int returnCode ) {
}

unsigned AppIsOpen( L2DApp* app ) {
  return 0;
}
