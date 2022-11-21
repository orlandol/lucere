#ifndef H_LUCERE2D
#define H_LUCERE2D

/*
 *  Lucere2D object IDs
 */

#define L2D_OBJECTID_W32APP 1

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
 *  Win32 custom event handler declarations
 */

#ifdef _WIN32

#include "windows.h"

typedef LRESULT CALLBACK L2DEventRouter( HWND wpWindow,
  UINT wpMessage, WPARAM wpWParam, LPARAM wpLParam );

#define L2DAPP_DECLARE_EVENTROUTER( ROUTERNAME )\
  LRESULT CALLBACK ROUTERNAME( HWND wpWindow,\
    UINT wpMessage, WPARAM wpWParam, LPARAM wpLParam );

#define L2DAPP_IMPLEMENT_EVENTROUTER( ROUTERNAME )\
  LRESULT CALLBACK ROUTERNAME( HWND wpWindow,\
    UINT wpMessage, WPARAM wpWParam, LPARAM wpLParam ) {

#define L2DAPP_ROUTE_INTERNALEVENTS\
  switch( wpMessage ) {\
  }

#define L2DAPP_DELEGATE_TO_SYSTEM\
  return DefWindowProc(wpWindow, wpMessage, wpWParam, wpLParam);

#define L2DAPP_IMPLEMENT_EVENTROUTER_END\
  }

#endif

/* Example usage
#ifdef _WIN32
  L2DAPP_DECLARE_EVENTROUTER( wbrRouteEvent )

  L2DAPP_IMPLEMENT_EVENTROUTER_BEGIN( wbrRouteEvent )
    if( EasyTab_HandleEvent(wpWindow, wpMessage, wpLParam, wpWParam) == EASYTAB_OK ) {
      return 1;
    }

    L2DAPP_ROUTE_INTERNALEVENTS
    L2DAPP_ROUTE_SYSTEMEVENTS

  L2DAPP_IMPLEMENT_EVENTROUTER_END

  ...
  App* app = CreateAppFromDisplay(display, wbrRouteEvent);
  ...
#endif
*/

/*
 *  Abstract app interface
 */

typedef struct L2DApp L2DApp;

L2DApp* CreateAppFromDisplay( L2DDisplay* display,
  const char* title, L2DEventRouter* eventRouter );
L2DApp* CreateApp( unsigned width, unsigned height,
  const char* title, L2DEventRouter* eventRouter );
void ReleaseApp( L2DApp** appPtr );

void ExitApp( L2DApp* app, int returnCode );

unsigned AppIsOpen( L2DApp* app );

#endif
