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
  size_t structSize;
  HANDLE window;
  HINSTANCE instance;
} LucAppImpl;

/*
 *  Abstract Surface declarations
 */

typedef struct LucSurfaceInfoImpl {
  size_t structSize; // = sizeof(LucSurfaceInfo) [mem] or 0 [var]
} LucSurfaceInfoImpl;

/*
 *  Abstract Graphics System declarations
 */

typedef LucDisplay* (*LucCreateDisplayFunc)( LucApp* app,
  unsigned monitorIndex, LucGraphicsSystem* graphics );

// Display prototypes
typedef unsigned (*LucReleaseDisplayFunc)( LucDisplay** displayPtr );

typedef unsigned (*LucCenterCanvas)( LucDisplay* display,
  LucCanvas* canvas );
typedef unsigned (*LucFitCanvasH)( LucDisplay* display,
  LucCanvas* canvas );
typedef unsigned (*LucFitCanvasV)( LucDisplay* display,
  LucCanvas* canvas );
typedef unsigned (*LucStretchCanvas)( LucDisplay* display,
  LucCanvas* canvas );

typedef LucCanvas* (*LucCreateCanvasFunc)( LucDisplay* display,
  unsigned width, unsigned height );

// Canvas prototypes
typedef unsigned (*LucReleaseCanvasFunc)( LucCanvas** canvasPointer );

typedef unsigned (*LucCanvasSurfaceType)( LucCanvas* canvas );

typedef LucSurface* (*LucAccessCanvasSurface)( LucCanvas* canvas,
  LucSurfaceInfo* destSurfaceInfo );

typedef unsigned (*LucReleaseCanvasSurface)( LucCanvas** canvasPointer );

// Image prototypes
typedef unsigned (*LucReleaseImageFunc)( LucImage** imagePointer );

typedef unsigned (*LucImageSurfaceTypeFunc)( LucCanvas* canvas );

typedef LucSurface* (*LucImageAccessSurfaceFunc)( LucCanvas* canvas,
  LucSurfaceInfo* destSurfaceInfo );

typedef unsigned (*LucImageReleaseSurfaceFunc)(
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

  LucCanvasSurfaceType canvasSurfaceType;
  LucAccessCanvasSurfaceFunc accessCanvasSurface;
  LucReleaseCanvasSurfaceFunc releaseCanvasSurface;

  // Image interface
  LucReleaseImageFunc releaseImage;

  LucImageSurfaceTypeFunc imageSurfaceType;
  LucImageAccessSurfaceFunc accessImageSurface;
  LucImageReleaseSurfaceFunc releaseImageSurface;

  // Surface interface
} LucGraphicsSystemImpl;

/*
 *  Win32 GDI display declarations
 */

unsigned gdiDisplayCount( LucApp* app );

LucDisplay* gdiDisplayCreate( LucApp* app, unsigned monitorIndex,
  LucGraphicsSystem* graphicsSystem );

unsigned gdiDisplayRelease( LucDisplay** displayPtr );

#endif // _WIN32

#endif // LUCIMPL_H
