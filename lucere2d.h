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

typedef struct L2DDisplayInterface L2DDisplayInterface;
typedef struct L2DDisplay L2DDisplay;

typedef struct L2DCanvasInterface L2DCanvasInterface;
typedef struct L2DCanvas L2DCanvas;

typedef struct L2DImageInterface L2DImageInterface;
typedef struct L2DImage L2DImage;

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

typedef struct L2DImageLoad L2DImageLoad;

/*
 *  Base graphics interface declaration
 */

typedef struct L2DGraphicsInterface L2DGraphicsInterface;

/*
 *  Graphics API specific interface declarations
 */

extern const L2DGraphicsInterface giWinGDI;

/*
 *  Abstract graphics interface
 */

L2DDisplay* CreateDisplay( const L2DGraphicsInterface* graphicsInterface,
  unsigned monitorIndex, const char* appTitle, void* rsvd );
void ReleaseDisplay( L2DDisplay** displayPtr );

L2DCanvas* CreateCanvas( L2DDisplay* display, unsigned width, unsigned height );
void ReleaseCanvas( L2DCanvas** canvasPtr );

#endif
