#ifndef IMPL_H
#define IMPL_H

#include "lucere2d.h"

typedef struct L2DDisplayImpl {
  L2DDisplay* (*CreateDisplay)( unsigned monitorIndex, void* rsvd );
  L2DDisplay* (*CreateWindowedDisplay)( unsigned monitorIndex,
    unsigned width, unsigned height, void* rsvd );
  L2DDisplay* (*CreateNullDisplay)( unsigned width, unsigned height,
    L2DPixelFormat* ofPixelFormat, void* rsvd );

  void (*ReleaseDisplay)( L2DDisplay** displayPtr );

  unsigned (*GetDisplayInfo)( L2DDisplay* display, L2DGraphicsInfo* info );

  L2DCanvas* (*CreateCanvas)( L2DDisplay* display,
    unsigned width, unsigned height );
  L2DCanvas* (*LoadCanvas)( L2DDisplay* display, L2DImageLoad* source );

  void (*CenterCanvas)( L2DDisplay* display, L2DCanvas* canvas );
  void (*FitCanvas)( L2DDisplay* display, L2DCanvas* canvas );
} L2DDisplay;

typedef struct L2DCanvasImpl {
  void (*ReleaseCanvas)( L2DCanvas** canvasPtr );

  unsigned (*GetCanvasInfo)( L2DCanvas* canvas,
    L2DGraphicsInfo* canvasInfo );

  L2DImage* (*CreateImage)( L2DCanvas* canvas,
    unsigned width, unsigned height );
  L2DImage* (*CopyImage)( L2DCanvas* canvas, L2DImage* image );
  L2DImage* (*CaptureImage)( L2DCanvas* canvas,
    int x1, int y1, int x2, int y2 );
  L2DImage* (*LoadImage)( L2DCanvas* canvas, L2DImageLoad* source );
  L2DImage* (*LoadImageRect)( L2DCanvas* canvas, L2DImageLoad* source,
    int x1, int y1, int x2, int y2 );

  void (*DrawImage)( L2DCanvas* canvas, int x, int y, L2DImage* image );
  void (*TransImage)( L2DCanvas* canvas, int x, int y, L2DImage* image );
  void (*BlendImage)( L2DCanvas* canvas, int x, int y, L2DImage* image );

  void (*Line)( L2DCanvas* canvas,
    int x1, int y1, int x2, int y2, unsigned color );
  void (*Circle)( L2DCanvas* canvas, int centerX, int centerY,
    unsigned radius, unsigned color );
  void (*Ellipsoid)( L2DCanvas* canvas,
    int x1, int y1, int x2, int y2, unsigned color );
} L2DCanvas;

typedef struct L2DImageImpl {
  void (*ReleaseImage)( L2DImage** imagePtr );
} L2DImage;

typedef struct L2DGraphicsInterfaceImpl {
  // Display object
  L2DDisplay* (*CreateDisplay)( unsigned monitorIndex, void* rsvd );
  L2DDisplay* (*CreateWindowedDisplay)( unsigned monitorIndex,
    unsigned width, unsigned height, void* rsvd );
  L2DDisplay* (*CreateNullDisplay)( unsigned width, unsigned height,
    L2DPixelFormat* ofPixelFormat, void* rsvd );

  void (*ReleaseDisplay)( L2DDisplay** displayPtr );

  unsigned (*GetDisplayInfo)( L2DDisplay* display, L2DGraphicsInfo* info );

  L2DCanvas* (*CreateCanvas)( L2DDisplay* display,
    unsigned width, unsigned height );
  L2DCanvas* (*LoadCanvas)( L2DDisplay* display, L2DImageLoad* source );

  void (*CenterCanvas)( L2DDisplay* display, L2DCanvas* canvas );
  void (*FitCanvas)( L2DDisplay* display, L2DCanvas* canvas );

  // Canvas object
  void (*ReleaseCanvas)( L2DCanvas** canvasPtr );

  unsigned (*GetCanvasInfo)( L2DCanvas* canvas,
    L2DGraphicsInfo* canvasInfo );

  L2DImage* (*CreateImage)( L2DCanvas* canvas,
    unsigned width, unsigned height );
  L2DImage* (*CopyImage)( L2DCanvas* canvas, L2DImage* image );
  L2DImage* (*CaptureImage)( L2DCanvas* canvas,
    int x1, int y1, int x2, int y2 );
  L2DImage* (*LoadImage)( L2DCanvas* canvas, L2DImageLoad* source );
  L2DImage* (*LoadImageRect)( L2DCanvas* canvas, L2DImageLoad* source,
    int x1, int y1, int x2, int y2 );

  void (*DrawImage)( L2DCanvas* canvas, int x, int y, L2DImage* image );
  void (*TransImage)( L2DCanvas* canvas, int x, int y, L2DImage* image );
  void (*BlendImage)( L2DCanvas* canvas, int x, int y, L2DImage* image );

  void (*Line)( L2DCanvas* canvas,
    int x1, int y1, int x2, int y2, unsigned color );
  void (*Circle)( L2DCanvas* canvas, int centerX, int centerY,
    unsigned radius, unsigned color );
  void (*Ellipsoid)( L2DCanvas* canvas,
    int x1, int y1, int x2, int y2, unsigned color );

  // Image object
  void (*ReleaseImage)( L2DImage** imagePtr );
} L2DGraphicsInterface;

#endif
