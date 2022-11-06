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

typedef struct PixelFormat {
  unsigned bpp;

  uint8 redPos;
  uint8 bluePos;
  uint8 greenPos;
  uint8 alphaPos;

  uint8 redShift;
  uint8 greenShift;
  uint8 blueShift;
  uint8 alphaShift;

  unsigned redMask;
  unsigned greenMask;
  unsigned blueMask;
  unsigned alphaMask;
} PixelFormat;

typedef struct GraphicsInfo {
  unsigned width;
  unsigned height;
  PixelFormat pixfmt;
} GraphicsInfo;

typedef struct DisplayInterface {
  L2DDisplay* (*Create)( unsigned monitorIndex,
    unsigned width, unsigned height, PixelFormat* usingPixelFormat );
  void (*Release)( L2DDisplay** displayPtr );

  int (*GetInfo)( L2DDisplay* display, GraphicsInfo* info );

  L2DCanvas* (*CreateCanvas)( L2DDisplay* display,
    unsigned width, unsigned height, PixelFormat* ofPixelFormat );
  void (*ReleaseCanvas)( L2DDisplay* display, L2DCanvas* canvasPtr );

  int (*GetCanvasInfo)( L2DCanvas* canvas, GraphicsInfo* canvasInfo );

  void (*CenterCanvas)( L2DDisplay* display, L2DCanvas* canvas );
  void (*FitCanvas)( L2DDisplay* display, L2DCanvas* canvas );
} DisplayInterface;

/*
 *  Windows GDI placeholders
 */

static const DisplayInterface WinGDI;

#endif
