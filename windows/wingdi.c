
#include <stddef.h>

#include "../lucere2d.h"
#include "../l2dimpl.h"
#include "wingdi.h"

const L2DGraphicsInterface giWinGDI = {
  {
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
  },

  {
  // Canvas object
  wingdiReleaseCanvas,
  wingdiGetCanvasInfo,
  wingdiCreateImage,
  wingdiCopyImage,
  wingdiCaptureImage,
  wingdiLoadImage,
  wingdiLoadImageRect,

  wingdiBeginDraw,
  wingdiEndDraw,

  wingdiDrawImage,
  wingdiTransImage,
  wingdiBlendImage,

  wingdiLine,
  wingdiCircle,
  wingdiEllipsoid,
  },

  {
  // Image object
  wingdiReleaseImage
  }
};

/*
 *  Display implementation
 */

L2DDisplay* wingdiCreateDisplay( unsigned monitorIndex ) {

  return NULL;
}

L2DDisplay* wingdiCreateWindowedDisplay( unsigned monitorIndex,
  unsigned width, unsigned height ) {

  return NULL;
}

L2DDisplay* wingdiCreateNullDisplay( unsigned width, unsigned height,
  L2DPixelFormat* ofPixelFormat ) {

  return NULL;
}

void wingdiReleaseDisplay( L2DDisplay** displayPtr ) {
}

unsigned wingdiGetDisplayInfo( L2DDisplay* display, L2DGraphicsInfo* info ) {
  return 3;
}

L2DCanvas* wingdiCreateCanvas( L2DDisplay* display,
  unsigned width, unsigned height ) {

  return NULL;
}

L2DCanvas* wingdiLoadCanvas( L2DDisplay* display, L2DImageLoad* source ) {
  return NULL;
}

void wingdiCenterCanvas( L2DDisplay* display, L2DCanvas* canvas ) {
}

void wingdiFitCanvas( L2DDisplay* display, L2DCanvas* canvas ) {
}

/*
 *  Canvas implementation
 */

void wingdiReleaseCanvas( L2DCanvas** canvasPtr ) {
}

unsigned wingdiGetCanvasInfo( L2DCanvas* canvas, L2DGraphicsInfo* canvasInfo ) {
  return 3;
}

L2DImage* wingdiCreateImage( L2DCanvas* canvas, unsigned width, unsigned height ) {
  return NULL;
}

L2DImage* wingdiCopyImage( L2DCanvas* canvas, L2DImage* image ) {
  return NULL;
}

L2DImage* wingdiCaptureImage( L2DCanvas* canvas,
  int x1, int y1, int x2, int y2 ) {

  return NULL;
}

L2DImage* wingdiLoadImage( L2DCanvas* canvas, L2DImageLoad* source ) {
  return NULL;
}

L2DImage* wingdiLoadImageRect( L2DCanvas* canvas, L2DImageLoad* source,
  int x1, int y1, int x2, int y2 ) {

  return NULL;
}

L2DDrawCtx* wingdiBeginDraw( L2DCanvas* canvas ) {
  return NULL;
}

void wingdiEndDraw( L2DDrawCtx** drawCtxPtr ) {
}

void wingdiDrawImage( L2DDrawCtx* drawCtx, int x, int y, L2DImage* image ) {
}

void wingdiTransImage( L2DDrawCtx* drawCtx, int x, int y, L2DImage* image ) {
}

void wingdiBlendImage( L2DDrawCtx* drawCtx, int x, int y, L2DImage* image ) {
}

void wingdiLine( L2DDrawCtx* drawCtx,
  int x1, int y1, int x2, int y2, unsigned color ) {
}

void wingdiCircle( L2DDrawCtx* drawCtx,
  int x, int y, unsigned radius, unsigned color ) {
}

void wingdiEllipsoid( L2DDrawCtx* drawCtx,
  int x1, int y1, int x2, int y2, unsigned color ) {
}

/*
 *  Image implementation
 */

void wingdiReleaseImage( L2DImage** imagePtr ) {
}
