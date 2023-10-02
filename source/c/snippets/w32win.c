
#include <string.h>

#include "windows.h"

LRESULT CALLBACK mainWindowProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) {
  switch( uMsg ) {
  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  case WM_KEYDOWN:
    return 0;
  }

  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

HWND CreateMainWindow( const char* title, unsigned width, unsigned height ) {
  STARTUPINFO startupInfo;
  WNDCLASSEX wcex;
  HWND newWindow = NULL;

  memset( &startupInfo, 0, sizeof(startupInfo) );
  GetStartupInfo( &startupInfo );

  memset( &wcex, 0, sizeof(wcex) );
  wcex.cbSize = sizeof(wcex);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = mainWindowProc;
  wcex.cbWndExtra = sizeof(LONG);
  wcex.hInstance = GetModuleHandle(NULL);
  wcex.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));
  wcex.hCursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW));
  wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
  wcex.lpszClassName = "main.WindowProc";
  wcex.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));
  if( RegisterClassEx(&wcex) == 0 ) { return NULL; }

  newWindow = CreateWindowEx(
    WS_EX_APPWINDOW | WS_EX_OVERLAPPEDWINDOW,
    "main.WindowProc", title,
    0,
    CW_USEDEFAULT, CW_USEDEFAULT,
    width ? width : CW_USEDEFAULT, height ? height : CW_USEDEFAULT,
    NULL, NULL, NULL, NULL
  );
  if( newWindow ) {
    ShowWindow( newWindow, startupInfo.wShowWindow );
    UpdateWindow( newWindow );
  }

  return newWindow;
}

int main( int argc, char* argv[] ) {
  HWND window = NULL;
  MSG msg;

  window = CreateMainWindow("Test", 640, 480);
  if( window == NULL ) { return 1; }

  memset( &msg, 0, sizeof(msg) );
  while( GetMessage(&msg, window, 0, 0) != 0 ) {
    if( msg.message == WM_QUIT ) {
      break;
    }

    if( msg.message == WM_KEYDOWN ) {
      if( msg.wParam == VK_ESCAPE ) {
        break;
      } else {
        DefWindowProc( msg.hwnd, msg.message, msg.wParam, msg.lParam );
      }
    } else {
      TranslateMessage( &msg );
      DispatchMessage( &msg );
    }
  }

  DestroyWindow(window);
  window = NULL;

  return 0;
}
