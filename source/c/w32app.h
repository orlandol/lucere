#ifndef W32APP_H
#define W32APP_H

#include "windows.h"

/*
 *  Win32 app declarations
 */

typedef struct LucAppImpl {
  size_t structSize;
  HANDLE winHandle;
  HINSTANCE winInstance;
} Win32AppImpl;

#endif
