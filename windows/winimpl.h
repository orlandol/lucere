#ifndef H_WINIMPL
#define H_WINIMPL

typedef struct wingdiDisplay {
} wingdiDisplay;

typedef struct wingdiCanvas {
} wingdiCanvas;

typedef struct wingdiImage {
} wingdiImage;

L2DDisplay* wingdiCreateDisplay( unsigned monitorIndex,
  unsigned width, unsigned height, PixelFormat* usingPixelFormat );
void wingdiReleaseDisplay( L2DDisplay** displayPtr );

int wingdiGetInfo( L2DDisplay* display, GraphicsInfo* info );

L2DCanvas* wingdiCreateCanvas( L2DDisplay* display,
  unsigned width, unsigned height, PixelFormat* ofPixelFormat );
void wingdiReleaseCanvas( L2DDisplay* display, L2DCanvas* canvasPtr );

int wingdiGetCanvasInfo( L2DCanvas* canvas, GraphicsInfo* canvasInfo );

void wingdiCenterCanvas( L2DDisplay* display, L2DCanvas* canvas );
void wingdiFitCanvas( L2DDisplay* display, L2DCanvas* canvas );

#endif
