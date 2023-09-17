#ifndef LUCERE_H
#define LUCERE_H

/*
 *  Base declarations
 */

// App state structure
typedef struct LucereAppImpl LucereApp;

// Display state structure
typedef struct LucereDisplayImpl LucereDisplay;

/*
 *  Required platform specific declarations
 */
#ifdef _WIN32

#include "windows.h"

typedef WNDPROC LucereEventRouter;

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

typedef struct GraphicsInterface {
} GraphicsInterface;

/*
 *  App declarations
 */

// Abstract app declarations
LucereApp* lucCreateApp( const char* title, unsigned width, unsigned height,
  unsigned flags, LucereEventRouter customRouter );
unsigned lucReleaseApp( LucereApp** appPtr );

unsigned lucExitApp( unsigned returnCode );

unsigned lucRouteEvents( LucereApp* app );
unsigned lucPauseForEvents( LucereApp* app );

#endif
