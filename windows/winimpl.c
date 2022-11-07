
#include <stddef.h>

#include "lucere2d.h"
#include "winimpl.h"

const L2DGraphicsInterface apiWinGDI = {
  // Display object
  wingdiCreateDisplay,
  wingdiCreateWindowedDisplay,
  wingdiCreateNullDisplay,
  wingdiReleaseDisplay,
  wingdiGetDisplayInfo,
  wingdiCreateCanvas,
  wingdiLoadCanvas,
  wingdiCenterCanvas,
  wingdiFitCanvas,

  // Canvas object
  wingdiReleaseCanvas,
  wingdiGetCanvasInfo,
  wingdiCreateImage,
  wingdiLoadImage,

  // Image object
  wingdiReleaseImage
};

/*
 *  Display implementation
 */

L2DDisplay* wingdiCreateDisplay( unsigned monitorIndex, void* rsvd ) {
  return NULL;
}

L2DDisplay* wingdiCreateWindowedDisplay( unsigned monitorIndex,
  unsigned width, unsigned height, void* rsvd ) {

  return NULL;
}

L2DDisplay* wingdiCreateNullDisplay( unsigned width, unsigned height,
  L2DPixelFormat* ofPixelFormat, void* rsvd ) {

  return NULL;
}

void wingdiReleaseDisplay( L2DDisplay** displayPtr ) {
}

unsigned wingdiGetDisplayInfo( L2DDisplay* display, L2DGraphicsInfo* info ) {
  return 3;
}

L2DCanvas* wingdiCreateCanvas( L2DDisplay* display,
  unsigned width, unsigned height );
L2DCanvas* wingdiLoadCanvas( L2DDisplay* display, L2DImageIO* imageIO );

void wingdiCenterCanvas( L2DDisplay* display, L2DCanvas* canvas );
void wingdiFitCanvas( L2DDisplay* display, L2DCanvas* canvas );

/*
 *  Canvas implementation
 */

void wingdiReleaseCanvas( L2DCanvas* canvasPtr ) {
}

unsigned wingdiGetCanvasInfo( L2DCanvas* canvas, L2DGraphicsInfo* canvasInfo ) {
  return 3;
}

L2DImage* wingdiCreateImage( L2DCanvas* canvas, unsigned width, unsigned height ) {
  return NULL;
}

L2DImage* wingdiLoadImage( L2DCanvas* canvas, L2DImageIO* imageIO ) {
  return NULL;
}

/*
 *  Image implementation
 */

void wingdiReleaseImage( L2DImage** imagePtr ) {
}
