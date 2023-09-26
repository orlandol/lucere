#ifndef LUCERE_H
#define LUCERE_H

#ifdef _WIN32

  /*
   *  Win32 event router declarations
   */

  #include "windows.h"

  typedef WNDPROC LucEventRouter;

  #define LUC_DECLARE_EVENTROUTER(name) \
    LRESULT name( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam );

  #define LUC_BEGIN_EVENTROUTER_IMPLEMENTATION(name) \
    LRESULT name( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam ) {

  #define LUC_ROUTE_EVENTS() \
      switch( Msg ) { \
      }

  #define LUC_END_EVENTROUTER_IMPLEMENTATION() \
      return DefWindowProc(hWnd, Msg, wParam, lParam); \
    }

#endif // _WIN32

/*
 *  Abstract Application declarations
 */

// App state structure
typedef struct LucAppImpl LucApp;

// Abstract app declarations
LucApp* lucCreateApp( const char* title, unsigned width, unsigned height,
  unsigned flags, LucEventRouter eventRouter );

unsigned lucReleaseApp( LucApp** appPtr );

unsigned lucExitApp( unsigned returnCode );

unsigned lucRouteEvents( LucApp* app );

unsigned lucWaitForNextEvent( LucApp* app );

/*
 *  Abstract Surface declarations
 */

typedef struct LucSurfaceInfoImpl LucSurfaceInfo;

/*
 *  Abstract Graphics declarations
 */

typedef struct LucGraphicsSystemImpl LucGraphicsSystem;

/*
 *  Abstract Display declarations
 */

// Display state structure
typedef struct LucDisplayImpl LucDisplay;

unsigned lucDisplayCount( LucApp* app );

LucDisplay* lucCreateDisplay( LucApp* app,
  unsigned monitorIndex, LucGraphicsSystem* graphics );

unsigned lucReleaseDisplay( LucDisplay** displayPtr );

/*
 *  Abstract Canvas declarations
 */

typedef struct LucCanvasImpl LucCanvas;

#endif
