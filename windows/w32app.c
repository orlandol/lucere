
#include "lucere2d.h"
#include "l2dimpl.h"
#include "w32app.h"

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
  wcex.hInstance = win32AppInstance;
  wcex.hIcon = LoadIcon(0, IDI_APPLICATION);
  wcex.hCursor = LoadCursor(0, IDC_ARROW);
  wcex.lpszClassName = "L2DApp";
  hIconSm = LoadIcon(0, IDI_APPLICATION);
  if( RegisterClassEx(&wcex) == 0 ) {
    goto ReturnError;
  }

  newApp->window = CreateWindow(
    "L2DApp", title,
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT,
    0, 0,
    0, 0, win32AppInstance, 0
  );
  if( newApp->window == NULL ) {
    goto ReturnError;
  }

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

HINSTANCE w32AppInstance;
int w32AppCmdShow;

int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
  PWSTR pCmdLine, int nCmdShow ) {

  w32AppInstance = hInstance;
  w32AppCmdShow = nCmdShow;

  int argc = 0;
  char** argv = NULL;

  return main(argc, argv);
}
