#ifndef W32GDI_H
#define W32GDI_H

/*
 *  Win32 GDI display declarations
 */

unsigned gdiDisplayCount( LucApp* app );

LucDisplay* gdiDisplayCreate( LucApp* app, unsigned monitorIndex,
  LucGraphicsSystem* graphicsSystem );

unsigned gdiDisplayRelease( LucDisplay** displayPtr );


#endif
