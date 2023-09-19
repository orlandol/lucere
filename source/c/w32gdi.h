#ifndef W32GDI_H
#define W32GDI_H

/*
 *  Win32 GDI display declarations
 */
LucDisplay* win32GdiDisplayCreate( LucApp* app, unsigned monitorIndex,
  LucGraphicsInterface* graphicsSystem );
unsigned win32GdiDisplayRelease( LucDisplay** displayPtr );


#endif
