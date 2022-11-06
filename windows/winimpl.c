
#include <stddef.h>

#include "lucere2d.h"
#include "winimpl.h"

static const DisplayInterface WinGDI = {
  wingdiCreateDisplay,
  wingdiReleaseDisplay,
  wingdiGetInfo,
  wingdiCreateCanvas,
  wingdiReleaseCanvas,
  wingdiGetCanvasInfo,
  wingdiCenterCanvas,
  wingdiFitCanvas
};

L2DDisplay* wingdiCreateDisplay( unsigned monitorIndex,
  unsigned width, unsigned height, PixelFormat* usingPixelFormat ) {

  return NULL;
}

void wingdiReleaseDisplay( L2DDisplay** displayPtr ) {
}

int wingdiGetInfo( L2DDisplay* display, GraphicsInfo* info ) {
  return 0;
}

L2DCanvas* wingdiCreateCanvas( L2DDisplay* display,
  unsigned width, unsigned height, PixelFormat* ofPixelFormat ) {

  return NULL;
}

void wingdiReleaseCanvas( L2DDisplay* display, L2DCanvas* canvasPtr ) {
}

int wingdiGetCanvasInfo( L2DCanvas* canvas, GraphicsInfo* canvasInfo ) {
  return 0;
}

void wingdiCenterCanvas( L2DDisplay* display, L2DCanvas* canvas ) {
}

void wingdiFitCanvas( L2DDisplay* display, L2DCanvas* canvas ) {
}
