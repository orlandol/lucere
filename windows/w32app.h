#ifndef W32APP_H
#define W32APP_H

#include "lucere2d.h"
#include "l2dimpl.h"

#include "windows.h"

typedef struct L2DWin32App {
  size_t totalSize;
  unsigned objectID;
  HWND window;
} L2DWin32App;

extern HINSTANCE w32AppInstance;
extern int w32AppCmdShow;

#endif
