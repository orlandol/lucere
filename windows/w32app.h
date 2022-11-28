#ifndef W32APP_H
#define W32APP_H

#include "../lucere2d.h"
#include "../l2dimpl.h"

typedef struct L2DWin32App {
  size_t totalSize;
  unsigned objectID;
  HWND window;
} L2DWin32App;

unsigned GetDesktopResolution( unsigned* width, unsigned* height,
  unsigned* bpp );

void ResizeClient( HWND window, unsigned clientWidth, unsigned clientnewHeight );
void CenterWindow( HWND window );

#endif
