#ifndef LUCIMPL_H
#define LUCIMPL_H

#include "lucere.h"

/*
 *  Abstract app declarations
 */

#ifdef _WIN32
/*
 *  Win32 app declarations
 */

#include "windows.h"

typedef struct LucAppImpl {
  size_t structSize; // = sizeof(LucApp)

  unsigned friendlyError;
  unsigned errorIndex;

  HANDLE window;
  HINSTANCE instance;
} LucAppImpl;

/*
 *  Abstract Surface declarations
 */

typedef struct LucSurfaceInfoImpl {
  size_t structSize; // = sizeof(LucSurfaceInfo) [mem] or 0 [var]
} LucSurfaceInfoImpl;

typedef unsigned (*LucReleaseSurfaceFunc)( LucSurface** surfacePointer );

typedef struct LucSurfaceImpl {
  size_t structSize; // = sizeof(LucSurfaceImpl);

  LucReleaseSurfaceFunc releaseSurface;

  unsigned char* surface;
} LucSurfaceImpl;

/*
 *  Abstract Graphics System declarations
 */

typedef LucDisplay* (*LucCreateDisplayFunc)( LucApp* app,
  unsigned monitorIndex, LucGraphicsSystem* graphics );

// Display prototypes
typedef unsigned (*LucReleaseDisplayFunc)( LucDisplay** displayPtr );

typedef unsigned (*LucCenterCanvasFunc)( LucDisplay* display,
  LucCanvas* canvas );
typedef unsigned (*LucFitCanvasHFunc)( LucDisplay* display,
  LucCanvas* canvas );
typedef unsigned (*LucFitCanvasVFunc)( LucDisplay* display,
  LucCanvas* canvas );
typedef unsigned (*LucStretchCanvasFunc)( LucDisplay* display,
  LucCanvas* canvas );

typedef LucCanvas* (*LucCreateCanvasFunc)( LucDisplay* display,
  unsigned width, unsigned height );

// Canvas prototypes
typedef unsigned (*LucReleaseCanvasFunc)( LucCanvas** canvasPointer );

typedef unsigned (*LucCanvasSurfaceTypeFunc)( LucCanvas* canvas );

typedef LucSurface* (*LucAccessCanvasSurfaceFunc)( LucCanvas* canvas,
  LucSurfaceInfo* destSurfaceInfo );

typedef unsigned (*LucReleaseCanvasSurfaceFunc)( LucCanvas** canvasPointer );

// Image prototypes
typedef unsigned (*LucReleaseImageFunc)( LucImage** imagePointer );

typedef unsigned (*LucImageSurfaceTypeFunc)( LucCanvas* canvas );

typedef LucSurface* (*LucAccessImageSurfaceFunc)( LucCanvas* canvas,
  LucSurfaceInfo* destSurfaceInfo );

typedef unsigned (*LucReleaseImageSurfaceFunc)(
  LucSurface** surfacePointrer );

// Graphics System Interface
typedef struct LucGraphicsSystemImpl {
  LucCreateDisplayFunc createDisplay;

  // Display interface
  LucReleaseDisplayFunc releaseDisplay;

  LucCenterCanvasFunc centerCanvas;
  LucFitCanvasHFunc fitCanvasH;
  LucFitCanvasVFunc fitCanvasV;
  LucStretchCanvasFunc stretchCanvas;

  LucCreateCanvasFunc createCanvas;

  // Canvas interface
  LucReleaseCanvasFunc releaseCanvas;

  LucCanvasSurfaceTypeFunc canvasSurfaceType;
  LucAccessCanvasSurfaceFunc accessCanvasSurface;
  LucReleaseCanvasSurfaceFunc releaseCanvasSurface;

  // Image interface
  LucReleaseImageFunc releaseImage;

  LucImageSurfaceTypeFunc imageSurfaceType;
  LucAccessImageSurfaceFunc accessImageSurface;
  LucReleaseImageSurfaceFunc releaseImageSurface;

  // Surface interface
} LucGraphicsSystemImpl;

/*
 *  Win32 GDI display declarations
 */

unsigned gdiDisplayCount( LucApp* app );

LucDisplay* gdiDisplayCreate( LucApp* app, unsigned monitorIndex,
  LucGraphicsSystem* graphicsSystem );

unsigned gdiDisplayRelease( LucDisplay** displayPtr );

/*
 *  Abstract Image internal declarations
 */

typedef struct LucImageImpl {
  size_t structSize; // = sizeof(LucImageImpl)

  LucReleaseImageFunc releaseImage;
} LucImageImpl;

#endif // _WIN32

#endif // LUCIMPL_H
