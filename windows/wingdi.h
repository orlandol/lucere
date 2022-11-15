#ifndef H_WINIMPL
#define H_WINIMPL

#include "l2dimpl.h"

/*
 *  Win32 context declarations
 */

typedef struct wingdiDisplay {
  size_t totalSize;
  unsigned displayID;
  L2DDisplayInterface methods;
} wingdiDisplay;

typedef struct wingdiDrawCtx {
  size_t totalSize;
  unsigned drawCtxID;
} wingdiDrawCtx;

typedef struct wingdiCanvas {
  size_t totalSize;
  unsigned canvasID;
  L2DCanvasInterface methods;
} wingdiCanvas;

typedef struct wingdiImage {
  size_t totalSize;
  unsigned imageID;
  L2DImageInterface methods;
} wingdiImage;

/*
 *  Display declarations
 */

L2DDisplay* wingdiCreateDisplay( unsigned monitorIndex );
L2DDisplay* wingdiCreateWindowedDisplay( unsigned monitorIndex,
  unsigned width, unsigned height );
L2DDisplay* wingdiCreateNullDisplay( unsigned width, unsigned height,
  L2DPixelFormat* ofPixelFormat );

void wingdiReleaseDisplay( L2DDisplay** displayPtr );

unsigned wingdiGetDisplayInfo( L2DDisplay* display, L2DGraphicsInfo* info );

L2DCanvas* wingdiCreateCanvas( L2DDisplay* display,
  unsigned width, unsigned height );
L2DCanvas* wingdiLoadCanvas( L2DDisplay* display, L2DImageLoad* source );

void wingdiCenterCanvas( L2DDisplay* display, L2DCanvas* canvas );
void wingdiFitCanvas( L2DDisplay* display, L2DCanvas* canvas );

/*
 *  Canvas declarations
 */

void wingdiReleaseCanvas( L2DCanvas** canvasPtr );

unsigned wingdiGetCanvasInfo( L2DCanvas* canvas, L2DGraphicsInfo* canvasInfo );

L2DImage* wingdiCreateImage( L2DCanvas* canvas, unsigned width, unsigned height );
L2DImage* wingdiCopyImage( L2DCanvas* canvas, L2DImage* image );
L2DImage* wingdiCaptureImage( L2DCanvas* canvas,
  int x1, int y1, int x2, int y2 );
L2DImage* wingdiLoadImage( L2DCanvas* canvas, L2DImageLoad* source );
L2DImage* wingdiLoadImageRect( L2DCanvas* canvas, L2DImageLoad* source,
  int x1, int y1, int x2, int y2 );

L2DDrawCtx* wingdiBeginDraw( L2DCanvas* canvas );
void wingdiEndDraw( L2DDrawCtx** drawCtxPtr );

void wingdiDrawImage( L2DDrawCtx* drawCtx, int x, int y, L2DImage* image );
void wingdiTransImage( L2DDrawCtx* drawCtx, int x, int y, L2DImage* image );
void wingdiBlendImage( L2DDrawCtx* drawCtx, int x, int y, L2DImage* image );

void wingdiLine( L2DDrawCtx* drawCtx,
  int x1, int y1, int x2, int y2, unsigned color );

void wingdiCircle( L2DDrawCtx* drawCtx,
  int x, int y, unsigned radius, unsigned color );

void wingdiEllipsoid( L2DDrawCtx* drawCtx,
  int x1, int y1, int x2, int y2, unsigned color );

/*
 *  Image declarations
 */

void wingdiReleaseImage( L2DImage** imagePtr );

#endif
