
#include "lucere.h"
#include "lucimpl.h"
#include "w32gdi.h"

LucDisplay* win32GdiDisplayCreate( LucApp* app, unsigned monitorID,
  LucGraphicsInterface* graphicsSystem );

unsigned win32GdiDisplayRelease( LucDisplay** displayPtr );
