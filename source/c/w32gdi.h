#ifndef W32GDI_H
#define W32GDI_H

/*
 *  Win32 GDI display declarations
 */
LucereDisplay* win32GdiDisplayCreate( LucereApp* app, unsigned monitorID,
  GraphicsInterface* graphicsSystem );
unsigned win32GdiDisplayRelease( LucereDisplay** displayPtr );


#endif
