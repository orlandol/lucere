#ifndef LUCERE_H
#define LUCERE_H

/*
 *  Base declarations
 */

// App state structure
typedef struct LucAppImpl LucApp;

// Display state structure
typedef struct LucDisplayImpl LucDisplay;

/*
 *  Required platform specific declarations
 */
#ifdef _WIN32

#include "windows.h"

typedef WNDPROC LucEventRouter;

#define LUC_DECLARE_EVENTROUTER(name) \
  LRESULT name( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam );

#define LUC_BEGIN_EVENTROUTER_IMPLEMENTATION(name) \
  LRESULT name( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam ) {

#define LUC_END_EVENTROUTER_IMPLEMENTATION() \
    return DefWindowProc(hWnd, Msg, wParam, lParam); \
  }
#endif // _WIN32

/*
 *  Abstract declarations
 */

typedef LucDisplay* (*LucCreateDisplayFunc)( LucApp* app, struct LucGraphicsInterface* graphics );
typedef unsigned (*LucReleaseDisplayFunc)( LucDisplay** displayPtr );

typedef struct LucGraphicsInterface {
  LucCreateDisplayFunc createDisplay;
  LucReleaseDisplayFunc releaseDisplay;
} LucGraphicsInterface;

/*
 *  App declarations
 */

// Abstract app declarations
LucApp* lucCreateApp( const char* title, unsigned width, unsigned height,
  unsigned flags, LucEventRouter eventRouter );
unsigned lucReleaseApp( LucApp** appPtr );

unsigned lucExitApp( unsigned returnCode );

unsigned lucRouteEvents( LucApp* app );
unsigned lucPauseForEvents( LucApp* app );

#endif
