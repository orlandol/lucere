#ifndef LUCERE_H
#define LUCERE_H

#ifdef _WIN32
#include "windows.h"
#endif // _WIN32 includes

#ifdef _WIN32
/*
 *  Win32 event router declarations
 */

typedef WNDPROC LucEventRouter;

#define LUC_DECLARE_EVENTROUTER(name) \
  LRESULT name( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam );

#define LUC_BEGIN_EVENTROUTER_IMPLEMENTATION(name) \
  LRESULT name( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam ) {

#define LUC_ROUTE_EVENTS() \
    switch( Msg ) { \
    }

#define LUC_END_EVENTROUTER_IMPLEMENTATION() \
    return DefWindowProc(hWnd, Msg, wParam, lParam); \
  }

#endif // _WIN32 event router declarations

#ifdef _WIN32
/*
 *  Win32 message code aliases
 */

#define eventCleanup (WM_QUIT)

#define eventKeyDown (WM_KEYDOWN)
#define eventKeyUp (WM_KEYUP)

#endif // _WIN32 message code aliases

#ifdef _WIN32
/*
 *  Win32 key code aliases
 */

#define lucKeyEscape VK_ESCAPE

#endif // _WIN32 key code aliases

/*
 *  Abstract Application declarations
 */

// Friendly error codes
enum LucFriendlyErrorCodes {
  errorUnsupportedOption = 1,
  errorCreatingApp
};

// App creation flags
enum LucCreateAppFlags {
  appMultiInstance = 1
};

// App state structure
typedef struct LucAppImpl LucApp;

// Event structure
typedef struct LucEvent {
  size_t structSize; // = sizeof(LucEvent)

  unsigned what;
  unsigned key;

#ifdef _WIN32
  MSG sysmsg; // Required for lucPassEvent
#endif
} LucEvent;

// Abstract app declarations

unsigned lucAppError( LucApp* app );

unsigned lucAppErrorIndex( LucApp* app );

LucApp* lucCreateApp( const char* title, unsigned width, unsigned height,
  unsigned flags, LucEventRouter eventRouter );

unsigned lucReleaseApp( LucApp** appPtr );

unsigned lucAppRunning( LucApp* app );

unsigned lucExitApp( LucApp* app, unsigned returnCode );

LucEvent lucGetEvent( LucApp* app );

LucEvent lucWaitEvent( LucApp* app );

unsigned lucPassEvent( LucApp* app, LucEvent* event );

/*
 *  Abstract Surface declarations
 */

typedef struct LucSurfaceInfoImpl LucSurfaceInfo;

typedef struct LucSurfaceImpl LucSurface;

/*
 *  Abstract Graphics declarations
 */

typedef struct LucGraphicsSystemImpl LucGraphicsSystem;

/*
 *  Abstract Display declarations
 */

// Display state structure
typedef struct LucDisplayImpl LucDisplay;

// Begin: Draft header documentation format
//
//  Function: lucDisplayCount
//
//  Returns the number of connected screens based on the application object.
//
//  Returns:
//  - UINT_MAX on error
//  - Screen count
//
//  Parameters:
//  - app = App state with implementation specific contexts/data
//
// End: Draft header documentation format
unsigned lucDisplayCount( LucApp* app );

LucDisplay* lucCreateDisplay( LucApp* app,
  unsigned monitorIndex, LucGraphicsSystem* graphics );

unsigned lucReleaseDisplay( LucDisplay** displayPtr );

/*
 *  Abstract Canvas declarations
 */

typedef struct LucCanvasImpl LucCanvas;

/*
 *  Abstract Image declarations
 */

typedef struct LucImageImpl LucImage;

#endif
