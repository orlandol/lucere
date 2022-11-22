
#include <stdlib.h>

#include "windows.h"

#include "../lucere2d.h"
#include "../l2dimpl.h"
#include "w32app.h"

/*
 *  Win32 specific variables
 */

HINSTANCE w32AppInstance = NULL;
HINSTANCE w32AppPrevInstance = NULL;
int w32AppCmdShow = SW_SHOWNORMAL;

/*
 *  Win32 helper functions
 */

unsigned GetDesktopResolution( unsigned* width, unsigned* height,
  unsigned* bpp ) {

  MONITORINFO monitorInfo = {};
  POINT point = {};
  HMONITOR monitor;
  HDC dc;
  unsigned calculatedWidth;
  unsigned calculatedHeight;
  unsigned desktopBPP;

  monitor = MonitorFromPoint(point, MONITOR_DEFAULTTOPRIMARY);

  monitorInfo.cbSize = sizeof(monitorInfo);
  if( GetMonitorInfo(monitor, &monitorInfo) == 0 ) {
    return 4;
  }

  calculatedWidth = abs(monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left);
  if( width ) {
    *width = calculatedWidth;
  }

  calculatedHeight = abs(monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor. top);
  if( height ) {
    *height = calculatedHeight;
  }

  ///TODO: Get Desktop BPP using the correct method
  ///TODO: Distinguish between 15/16-BPP
  if( bpp ) {
    dc = GetDC(0);
    if( dc ) {
      desktopBPP = GetDeviceCaps(dc, PLANES) * GetDeviceCaps(dc, BITSPIXEL);
      *bpp = desktopBPP;
      ReleaseDC(0, dc);
    }
  }

  return 0;
}

void ResizeClient( HWND window, unsigned toWidth, unsigned toHeight ) {
  RECT winRect;
  RECT clientRect;
  int winWidth;
  int winHeight;
  int clientWidth;
  int clientHeight;
  int ncWidth;
  int ncHeight;
  int newWidth;
  int newHeight;

  if( window && (newWidth || newHeight) ) {
    GetWindowRect( window, &winRect );
    winWidth = (winRect.right - winRect.left);
    winHeight = (winRect.bottom - winRect.top);

    GetClientRect( window, &clientRect );
    clientWidth = (clientRect.right - clientRect.left);
    clientHeight = (clientRect.bottom - clientRect.top);

    ncWidth = winWidth - clientWidth;
    ncHeight = winHeight - clientHeight;

    newWidth = ncWidth + toWidth;
    newHeight = ncHeight + toHeight;

    SetWindowPos( window, 0, winRect.left, winRect.top,
      newWidth, newHeight,
      SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE
    );
  }
}

void CenterWindow( HWND window ) {
}

/*
 *  Abstract app Win32 implementation
 */

L2DApp* CreateAppFromDisplay( L2DDisplay* display,
  const char* title, L2DEventRouter* eventRouter ) {

  return NULL;
}

LRESULT CALLBACK L2DWin32EventRouter( HWND wpWindow,
  UINT wpMessage, WPARAM wpWParam, LPARAM wpLParam ) {

  PAINTSTRUCT paintStruct = {};
  HDC paintDC;
  L2DWin32App* appImpl;

  appImpl = NULL;
  if( wpWindow ) {
    appImpl = (L2DWin32App*)GetWindowLongPtr(wpWindow, GWLP_USERDATA);
  }

  switch( wpMessage ) {
  case WM_ERASEBKGND:
    return 1;

  case WM_PAINT:
    paintDC = BeginPaint(wpWindow, &paintStruct);
    EndPaint( wpWindow, &paintStruct );
    return 0;

  case WM_DISPLAYCHANGE:
    break; /// TODO: Handle resolution/bpp changes

  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  }

  return DefWindowProc(wpWindow, wpMessage, wpWParam, wpLParam);
}

L2DApp* CreateApp( unsigned width, unsigned height,
  const char* title, L2DEventRouter* eventRouter ) {

  L2DWin32App* newApp = NULL;
  WNDCLASSEX wcex = {};
  unsigned appWidth = width;
  unsigned appHeight = height;

  newApp = calloc(1, sizeof(L2DWin32App));
  if( newApp == NULL ) { goto ReturnError; }

  wcex.cbSize = sizeof(wcex);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = L2DWin32EventRouter;
  if( eventRouter ) {
    wcex.lpfnWndProc = eventRouter;
  }
  wcex.hInstance = w32AppInstance;
  wcex.hIcon = LoadIcon(0, IDI_APPLICATION);
  wcex.hCursor = LoadCursor(0, IDC_ARROW);
  wcex.lpszClassName = "L2DApp";
  wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);
  if( RegisterClassEx(&wcex) == 0 ) {
    goto ReturnError;
  }

  newApp->window = CreateWindow(
    "L2DApp", title,
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT,
    0, 0,
    0, 0, w32AppInstance, 0
  );
  if( newApp->window == NULL ) {
    goto ReturnError;
  }

  ResizeClient( newApp->window, width, height );
  CenterWindow( newApp->window );

  ShowWindow( newApp->window, w32AppCmdShow );
  UpdateWindow( newApp->window );

  return newApp;

ReturnError:
  if( newApp ) {
    free( newApp );
    newApp = NULL;
  }
}

void ReleaseApp( L2DApp** appPtr ) {
}

void ExitApp( L2DApp* app, int returnCode ) {
}

unsigned AppIsOpen( L2DApp* app ) {
  return 0;
}

/*
 *  WinMain to main adapter
 */

extern int main( int argc, char** argv );

int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
  PWSTR pCmdLine, int nCmdShow ) {

  w32AppInstance = hInstance;
  w32AppPrevInstance = hPrevInstance;
  w32AppCmdShow = nCmdShow;

  int argc = 0;
  char** argv = NULL;

  return main(argc, argv);
}
