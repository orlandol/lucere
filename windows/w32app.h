#ifndef W32APP_H
#define W32APP_H

#include "lucere2d.h"
#include "l2dimpl.h"

#define L2D_APPID_WIN32 1

typedef struct L2DWin32App {
  size_t totalSize;
  unsigned objectID;
  HWND window;
} L2DWin32App;

extern HINSTANCE w32AppInstance;
extern int w32AppCmdShow;

#endif
