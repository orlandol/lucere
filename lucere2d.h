#ifndef H_LUCERE2D
#define H_LUCERE2D

/*
 *  Base type declarations
 */
#include <stdint.h>

typedef uint8_t  uint8;
typedef uint16_t Uint16;
typedef uint32_t Uint32;
typedef uint64_t Uint64;

typedef int8_t  int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

/*
 *  Base graphics declarations
 */

typedef struct L2DDisplayImpl L2DDisplay;
typedef struct L2DCanvasImpl L2DCanvas;
typedef struct L2DImageImpl L2DImage;

typedef struct L2DPixelFormat {
  unsigned bpp;

  uint8 redPos;
  uint8 bluePos;
  uint8 greenPos;
  uint8 alphaPos;

  uint8 redShift;
  uint8 greenShift;
  uint8 blueShift;
  uint8 alphaShift;

  unsigned rsvd;

  unsigned redMask;
  unsigned greenMask;
  unsigned blueMask;
  unsigned alphaMask;
} L2DPixelFormat;

typedef struct L2DGraphicsInfo {
  unsigned width;
  unsigned height;

  L2DPixelFormat pixfmt;
} L2DGraphicsInfo;

/*
 *  Base image I/O interface declaration
 */

typedef struct L2DImageIO {
} L2DImageIO;

/*
 *  Base graphics interface declaration
 */

typedef struct L2DGraphicsInterface {
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
  L2DCanvas* (*LoadCanvas)( L2DDisplay* display, L2DImageIO* imageIO );

  void (*CenterCanvas)( L2DDisplay* display, L2DCanvas* canvas );
  void (*FitCanvas)( L2DDisplay* display, L2DCanvas* canvas );

  // Canvas object
  void (*ReleaseCanvas)( L2DCanvas* canvasPtr );

  unsigned (*GetCanvasInfo)( L2DCanvas* canvas, L2DGraphicsInfo* canvasInfo );

  L2DImage* (*CreateImage)( L2DCanvas* canvas, unsigned width, unsigned height );
  L2DImage* (*LoadImage)( L2DCanvas* canvas, L2DImageIO* imageIO );

  // Image object
  void (*ReleaseImage)( L2DImage** imagePtr );
} L2DGraphicsInterface;

/*
 *  Graphics API specific interface declarations
 */

extern const L2DGraphicsInterface giWinGDI;

#endif
