#ifndef H_LUCERE2D
#define H_LUCERE2D

/*
 *  Base type declarations
 */
  typedef void* L2DPointer; // General implementation pointer

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
    L2DPointer (*Create)( unsigned monitorIndex, 
      unsigned width, unsigned height, PixelFormat* usingPixelFormat );
    void (*Release)( L2DPointer displayPtr );

    int (*GetInfo)( L2DPointer display, GraphicsInfo* info );

    L2DPointer (*CreateCanvas)( L2DPointer display,
      unsigned width, unsigned height, PixelFormat* usingPixelFormat );
    void (*ReleaseCanvas)( L2DPointer display, L2DPointer* canvasPtr );

    int (*GetCanvasInfo)( L2DPointer canvas, GraphicsInfo* canvasInfo );

    L2DPointer (*BeginDraw)( L2DPointer canvas );
    void (*EndDraw)( L2DPointer canvas );

    void (*CenterCanvas)( L2DPointer display, L2DPointer canvas );
    void (*FitCanvas)( L2DPointer display, L2DPointer canvas );
  } DisplayInterface;

/*
 *  Windows GDI declarations
 */

    L2DPointer wingdiCreate( unsigned monitorIndex, 
      unsigned width, unsigned height, PixelFormat* usingPixelFormat );
    void wingdiRelease( L2DPointer displayPtr );

    int wingdiGetInfo( L2DPointer display, GraphicsInfo* info );

    L2DPointer wingdiCreateCanvas( L2DPointer display,
      unsigned width, unsigned height, PixelFormat* usingPixelFormat );
    void wingdiReleaseCanvas( L2DPointer display, L2DPointer* canvasPtr );

    int wingdiGetCanvasInfo( L2DPointer canvas, GraphicsInfo* canvasInfo );

    L2DPointer wingdiBeginDraw( L2DPointer canvas );
    void wingdiEndDraw( L2DPointer canvas );

    void wingdiCenterCanvas( L2DPointer display, L2DPointer canvas );
    void wingdiFitCanvas( L2DPointer display, L2DPointer canvas );

  static const DisplayInterface WinGDI = {
    wingdiCreate,
    wingdiRelease,
    wingdiGetInfo,
    wingdiCreateCanvas,
    wingdiReleaseCanvas,
    wingdiGetCanvasInfo,
    wingdiBeginDraw,
    wingdiEndDraw,
    wingdiCenterCanvas,
    wingdiFitCanvas
  };

#endif
