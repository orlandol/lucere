
#include "lucere.h"
#include "lucimpl.h"
#include "w32gdi.h"

unsigned gdiDisplayCount( LucApp* app ) {
  return 0;
}

LucDisplay* gdiDisplayCreate( LucApp* app, unsigned monitorID,
  LucGraphicsSystem* graphicsSystem ) {

  return NULL;
}

unsigned gdiDisplayRelease( LucDisplay** displayPtr ) {
  return 2;
}
