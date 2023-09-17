#ifndef W32APP_H
#define W32APP_H

#include "windows.h"

typedef struct LucereAppImpl {
  size_t structSize;
  HANDLE winHandle;
  HINSTANCE winInstance;
} LucereAppImpl;

#endif
