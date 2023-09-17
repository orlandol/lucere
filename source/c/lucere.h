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
 *  Abstract declarations
 */

LucereApp* lucCreateApp( const char* title, unsigned width, unsigned height,
  unsigned flags, LucereEventRouter customRouter );

void lucReleaseApp( LucereApp** appPtr );

void lucExitApp( unsigned returnCode );

unsigned lucRouteEvents( LucereApp* app );

typedef struct GraphicsInterface {
} GraphicsInterface;

///TODO: Define OS specific macros to abstract event routers
typedef void (*LucereEventRouter)();

enum AppCreateResult {
  appCreateSuccess = 0,
  appCreateErrorInTitle = 1,
  appCreateErrorInWidth = 2,
  appCreateErrorInHeight = 3,
  appCreateErrorInFlags = 4,
  appCreateErrorInEventRouter = 5,
};

/*
 *  App declarations
 */

// Abstract app declarations
LucereApp* appCreate( const char* title, unsigned width, unsigned height,
  unsigned flags, LucereEventRouter eventRouter );

int appRelease( LucereApp** appPointer );

// Win32 app declarations
LucereApp* win32AppCreate( const char* title, unsigned width, unsigned height,
  unsigned flags, LucereEventRouter eventRouter );

int win32AppRelease( LucereApp** appPointer );

/*
 *  Win32 GDI specific display declarations
 */
LucereDisplay* win32GdiDisplayCreate( LucereApp* app, unsigned monitorID,
  GraphicsInterface* graphicsSystem );

int win32GdiDisplayRelease( LucereDisplay** displayPtr );

#endif
