
#include <stddef.h>

#include "lucere2d.h"
#include "winimpl.h"

L2DPointer wingdiCreate( unsigned monitorIndex, 
  unsigned width, unsigned height, PixelFormat* usingPixelFormat ) {

  return NULL;
}

void wingdiRelease( L2DPointer displayPtr ) {
}

int wingdiGetInfo( L2DPointer display, GraphicsInfo* info ) {
  return 0;
}

L2DPointer wingdiCreateCanvas( L2DPointer display,
  unsigned width, unsigned height, PixelFormat* usingPixelFormat ) {

  return NULL;
}

void wingdiReleaseCanvas( L2DPointer display, L2DPointer* canvasPtr ) {
}

int wingdiGetCanvasInfo( L2DPointer canvas, GraphicsInfo* canvasInfo ) {
  return 0;
}

L2DPointer wingdiBeginDraw( L2DPointer canvas ) {
  return NULL;
}

void wingdiEndDraw( L2DPointer canvas ) {
}

void wingdiCenterCanvas( L2DPointer display, L2DPointer canvas ) {
}

void wingdiFitCanvas( L2DPointer display, L2DPointer canvas ) {
}
