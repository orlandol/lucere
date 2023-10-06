
#include "lucere.h"
#include "lucimpl.h"

#include <stdlib.h>

#ifdef _WIN32
/*
 *  Win32 Application implementation
 */

unsigned lucAppError( LucApp* app ) {
  return (app ? app->friendlyError : UINT_MAX);
}

unsigned lucAppErrorIndex( LucApp* app ) {
  return (app ? app->errorIndex : UINT_MAX);
}

LRESULT CALLBACK win32EventRouter( HWND hwnd, UINT message,
    WPARAM wParam, LPARAM lParam ) {

  switch( message ) {
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;

  ///TODO: Handle events that affect window resize, cached draw, etc.

  case WM_KEYDOWN:
    return 0;

  case WM_KEYUP:
    return 0;
  }

  return DefWindowProc(hwnd, message, wParam, lParam);
}

LucApp* lucCreateApp( const char* title, unsigned width, unsigned height,
    unsigned flags, LucEventRouter customRouter ) {

  // Local variables
  static LucApp createAppError = {
    UINT_MAX, // structSize
    0, // friendlyError
    0, // errorIndex
    NULL, // window
    NULL // instance
  };
  LucAppImpl* newApp = NULL;
  WNDCLASSEX wcex;
  STARTUPINFO startupInfo = { };

  GetStartupInfo( &startupInfo );

  // Validate or initialize parameters
  createAppError.friendlyError = errorCreatingApp;

  createAppError.errorIndex = 6;
  if( !(title && (*title)) ) { goto ReturnError; }

  ///TODO: Enforce single instance if appMultiInstance isn't specified

  // Instantiate app state
  createAppError.errorIndex = 7;
  newApp = calloc(1, sizeof(LucAppImpl));
  if( newApp == NULL ) { goto ReturnError; }

  newApp->instance = GetModuleHandle(NULL);

  // Register window class
  createAppError.errorIndex = 8;

  memset( &wcex, 0, sizeof(wcex) );
  wcex.cbSize = sizeof(wcex);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = win32EventRouter;
  wcex.cbWndExtra = 0; // Multiples of sizeof(LONG) and/or sizeof(LONG_PTR)
  wcex.hInstance = newApp->instance;
  wcex.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));
  wcex.hCursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW));
  wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wcex.lpszClassName = "LucereApp";
  wcex.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));
  if( RegisterClassEx(&wcex) == 0 ) { goto ReturnError; }

  // Create app window
  newApp->window = CreateWindowEx(
    WS_EX_APPWINDOW | WS_EX_OVERLAPPEDWINDOW,
    "LucereApp", title,
    0,
    CW_USEDEFAULT, CW_USEDEFAULT,
    width ? width : CW_USEDEFAULT, height ? height : CW_USEDEFAULT,
    NULL, NULL, newApp->instance, NULL
  );

  if( newApp->window ) {
    ShowWindow( newApp->window, startupInfo.wShowWindow );
    UpdateWindow( newApp->window );

    return newApp;
  }

ReturnError:
  lucReleaseApp( &newApp );

  return &createAppError;
}

unsigned lucReleaseApp( LucApp** appPtr ) {
  if( !(appPtr && (*appPtr)) ) { return 1; }

  if( (*appPtr)->window ) {
    if( IsWindow((*appPtr)->window) == 0 ) { return 2; }

    DestroyWindow( (*appPtr)->window );
    (*appPtr)->window = NULL;
  }

  free( (*appPtr) );
  (*appPtr) = NULL;

  return 0;
}

unsigned lucAppRunning( LucApp* app ) {
  return ((app && app->window) ? 1 : 0 );
}

unsigned lucExitApp( LucApp* app, unsigned returnCode ) {
  if( !(app && app->window) ) { return 1; }

  (void)DestroyWindow( app->window );
  app->window = NULL;

  return 0;
}

LucEvent lucGetEvent( LucApp* app ) {
  LucEvent tempEvent = {};

  if( PeekMessage(&tempEvent.sysmsg, app->window, 0, 0, PM_REMOVE) ) {
    ///TODO: Check for WM_PAINT with a non-NULL region for removal from queue

    switch( tempEvent.sysmsg.message ) {
    case WM_KEYDOWN:
    case WM_KEYUP:
      tempEvent.what = tempEvent.sysmsg.message;
      tempEvent.key = tempEvent.sysmsg.wParam;
      break;

    default:
      TranslateMessage( &tempEvent.sysmsg );
      DispatchMessage( &tempEvent.sysmsg );
      memset( &tempEvent, 0, sizeof(tempEvent) );
    }
  }

  return tempEvent;
}

LucEvent lucWaitForEvent( LucApp* app ) {
  LucEvent tempEvent = {};

  if( GetMessage(&tempEvent.sysmsg, app->window, 0, 0) != 0 ) {
    switch( tempEvent.sysmsg.message ) {
    case WM_KEYDOWN:
    case WM_KEYUP:
      tempEvent.what = tempEvent.sysmsg.message;
      tempEvent.key = tempEvent.sysmsg.wParam;
      break;

    default:
      TranslateMessage( &tempEvent.sysmsg );
      DispatchMessage( &tempEvent.sysmsg );
      memset( &tempEvent, 0, sizeof(tempEvent) );
    }
  }

  return tempEvent;
}

unsigned lucPassEvent( LucApp* app, LucEvent* event ) {
  MSG* msgPtr = NULL;

  if( !(app && app->window) ) { return 1; }
  if( event == NULL ) { return 2; }

  msgPtr = (&event->sysmsg);

  (void)DefWindowProc( msgPtr->hwnd, msgPtr->message,
      msgPtr->wParam, msgPtr->lParam );

  return 0;
}
#endif // _WIN32

/*
 *  Abstract Display implementation
 */

LucDisplay* lucCreateDisplay( LucApp* app,
  unsigned monitorIndex, LucGraphicsSystem* graphics ) {

  return NULL;
}

unsigned lucReleaseDisplay( LucDisplay** displayPtr ) {
  unsigned result = 1;

  if( displayPtr && (*displayPtr) ) {
    result++;
    if( ((LucDisplayImpl*)(*displayPtr))->releaseDisplay ) {
      result = ((LucDisplayImpl*)(*displayPtr))->releaseDisplay( displayPtr );
    }

    free( (*displayPtr) );
    (*displayPtr) = NULL;
  }

  return result;
}

#ifdef _WIN32
/*
 *  Win32 Display implementation
 */

unsigned lucDisplayCount( LucApp* app ) {
  return 2;
}

LucDisplay* gdiDisplayCreate( LucApp* app, unsigned monitorIndex,
  LucGraphicsSystem* graphicsSystem ) {

  return NULL;
}

unsigned gdiDisplayRelease( LucDisplay** displayPtr ) {
  return 2;
}

#endif // __WIN32
