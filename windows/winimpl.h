#ifndef H_WINIMPL
#define H_WINIMPL

/*
 *  Win32 context declarations
 */

typedef struct wingdiDisplay {
} wingdiDisplay;

typedef struct wingdiCanvas {
} wingdiCanvas;

typedef struct wingdiImage {
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
L2DCanvas* wingdiLoadCanvas( L2DDisplay* display, L2DImageIO* imageIO );

void wingdiCenterCanvas( L2DDisplay* display, L2DCanvas* canvas );
void wingdiFitCanvas( L2DDisplay* display, L2DCanvas* canvas );

/*
 *  Canvas declarations
 */

void wingdiReleaseCanvas( L2DCanvas* canvasPtr );

unsigned wingdiGetCanvasInfo( L2DCanvas* canvas, L2DGraphicsInfo* canvasInfo );

L2DImage* wingdiCreateImage( L2DCanvas* canvas, unsigned width, unsigned height );
L2DImage* wingdiLoadImage( L2DCanvas* canvas, L2DImageIO* imageIO );


/*
 *  Image declarations
 */

void wingdiReleaseImage( L2DImage** imagePtr );

#endif
