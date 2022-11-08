#ifndef H_WINIMPL
#define H_WINIMPL

/*
 *  Win32 context declarations
 */

typedef struct wingdiDisplay {
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
} wingdiDisplay;

typedef struct wingdiCanvas {
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
} wingdiCanvas;

typedef struct wingdiImage {
  void (*ReleaseImage)( L2DImage** imagePtr );
} wingdiImage;

/*
 *  Display declarations
 */

L2DDisplay* wingdiCreateDisplay( unsigned monitorIndex, void* rsvd );
L2DDisplay* wingdiCreateWindowedDisplay( unsigned monitorIndex,
  unsigned width, unsigned height, void* rsvd );
L2DDisplay* wingdiCreateNullDisplay( unsigned width, unsigned height,
  L2DPixelFormat* ofPixelFormat, void* rsvd );

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

void wingdiDrawImage( L2DCanvas* canvas, int x, int y, L2DImage* image );
void wingdiTransImage( L2DCanvas* canvas, int x, int y, L2DImage* image );
void wingdiBlendImage( L2DCanvas* canvas, int x, int y, L2DImage* image );

void wingdiLine( L2DCanvas* canvas,
  int x1, int y1, int x2, int y2, unsigned color );

void wingdiCircle( L2DCanvas* canvas,
  int x, int y, unsigned radius, unsigned color );

void wingdiEllipsoid( L2DCanvas* canvas,
  int x1, int y1, int x2, int y2, unsigned color );

/*
 *  Image declarations
 */

void wingdiReleaseImage( L2DImage** imagePtr );

#endif
