#ifndef L2DIMPL_H
#define L2DIMPL_H

#include "lucere2d.h"

typedef struct L2DDisplayInterface {
  L2DDisplay* (*CreateDisplay)( unsigned monitorIndex,
    const char* appTitle, void* rsvd );
  L2DDisplay* (*CreateWindowedDisplay)( unsigned monitorIndex,
    unsigned width, unsigned height, const char* appTitle, void* rsvd );
  L2DDisplay* (*CreateNullDisplay)( unsigned width, unsigned height,
    L2DPixelFormat* ofPixelFormat, const char* appTitle, void* rsvd );

  void (*ReleaseDisplay)( L2DDisplay** displayPtr );

  unsigned (*GetDisplayInfo)( L2DDisplay* display, L2DGraphicsInfo* info );

  L2DCanvas* (*CreateCanvas)( L2DDisplay* display,
    unsigned width, unsigned height );
  L2DCanvas* (*LoadCanvas)( L2DDisplay* display, L2DImageLoad* source );

  void (*CenterCanvas)( L2DDisplay* display, L2DCanvas* canvas );
  void (*FitCanvas)( L2DDisplay* display, L2DCanvas* canvas );
} L2DDisplayInterface;

typedef struct L2DDisplay {
  size_t totalSize;
  unsigned displayID;
  L2DDisplayInterface methods;
} L2DDisplay;

typedef struct L2DCanvasInterface {
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
} L2DCanvasInterface;

typedef struct L2DCanvas {
  size_t totalSize;
  unsigned canvasID;
  L2DCanvasInterface methods;
} L2DCanvas;

typedef struct L2DImageInterface {
  void (*ReleaseImage)( L2DImage** imagePtr );
} L2DImageInterface;

typedef struct L2DImage {
  L2DImageInterface methods;
} L2DImage;

typedef struct L2DGraphicsInterface {
  L2DDisplayInterface displayMethods;
  L2DCanvasInterface canvasMethods;
  L2DImageInterface imageMethods;
} L2DGraphicsInterface;

#endif