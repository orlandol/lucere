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
 *  Abstract Graphics declarations
 */

// Graphics system declarations
typedef unsigned (*LucDisplayCountFunc)( LucApp* app );

typedef LucDisplay* (*LucCreateDisplayFunc)( LucApp* app,
  unsigned monitorIndex, struct LucGraphicsSystem* graphics );

typedef unsigned (*LucReleaseDisplayFunc)( LucDisplay** displayPtr );

typedef struct LucGraphicsSystem {
  LucDisplayCountFunc displayCount;
  LucCreateDisplayFunc createDisplay;
  LucReleaseDisplayFunc releaseDisplay;
} LucGraphicsSystem;

/*
 *  Abstract App declarations
 */

// Abstract app declarations
LucApp* lucCreateApp( const char* title, unsigned width, unsigned height,
  unsigned flags, LucEventRouter eventRouter );

unsigned lucReleaseApp( LucApp** appPtr );

unsigned lucExitApp( unsigned returnCode );

unsigned lucRouteEvents( LucApp* app );

unsigned lucWaitForNextEvent( LucApp* app );

/*
 *  Abstract Display declarations
 */

unsigned lucDisplayCount( LucApp* app );

LucDisplay* lucCreateDisplay( LucApp* app,
  unsigned monitorIndex, LucGraphicsSystem* graphics );

unsigned lucReleaseDisplay( LucDisplay** displayPtr );

#endif
