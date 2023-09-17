
#include "lucere.h"
#include "lucimpl.h"
#include "w32gdi.h"

LucereDisplay* win32GdiDisplayCreate( LucereApp* app, unsigned monitorID,
  GraphicsInterface* graphicsSystem );

unsigned win32GdiDisplayRelease( LucereDisplay** displayPtr );
