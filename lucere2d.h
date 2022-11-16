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

typedef struct L2DDisplayInterface L2DDisplayInterface;
typedef struct L2DDisplay L2DDisplay;

typedef struct L2DDrawCtx L2DDrawCtx;

typedef struct L2DCanvasInterface L2DCanvasInterface;
typedef struct L2DCanvas L2DCanvas;

typedef struct L2DImageInterface L2DImageInterface;
typedef struct L2DImage L2DImage;

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
 *  Abstract display interface
 */

L2DDisplay* CreateDisplay( const L2DGraphicsInterface* graphicsInterface,
  unsigned monitorIndex );
void ReleaseDisplay( L2DDisplay** displayPtr );

/*
 *  Abstract canvas interface
 */

L2DCanvas* CreateCanvas( L2DDisplay* display, unsigned width, unsigned height );
void ReleaseCanvas( L2DCanvas** canvasPtr );

/*
 *  Abstract app interface
 */

typedef struct L2DApp L2DApp;

L2DApp* CreateAppFromDisplay( L2DDisplay* display,
  const char* title, void* rsvd );
void ReleaseApp( L2DApp** appPtr );

void ExitApp( int returnCode );

unsigned AppIsOpen( L2DApp* app );

/*
 *  Win32 custom event handler declarations
 */

#ifdef _WIN32

#include "windows.h"

typedef LRESULT CALLBACK L2DEventHandler( HWND wpWindow,
  UINT wpMessage, WPARAM wpWParam, LPARAM wpLParam );

#define L2DAPP_DECLARE_EVENTHANDLER( HANDLERNAME )\
  LRESULT CALLBACK HANDLERNAME( HWND wpWindow,\
    UINT wpMessage, WPARAM wpWParam, LPARAM wpLParam );

#endif

/* Example usage
#ifdef _WIN32
  L2DW32APP_DECLARE_EVENTHANDLER( wbrHandleEvent )

  L2DW32APP_IMPLEMENT_EVENTHANDLER_BEGIN( wbrHandleEvent )
    if( EasyTab_HandleEvent(Window, Message, LParam, WParam) == EASYTAB_OK ) {
      return 1;
    }

    L2DW32APP_HANDLE_MESSAGE

  L2DW32APP_IMPLEMENT_EVENTHANDLER_END
  ...
  App* app = CreateAppFromDisplay(display, wbrHandleEvent);
  ...
#endif
*/


#endif
