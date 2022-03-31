#ifndef H_LUCERE2D
#define H_LUCERE2D

/*
 *  Base graphics declarations
 */

  typedef struct GraphicsContextInterface {
    void* (*Create)();
    void (*Release)( void** graphicsContext );
  } GraphicsContextInterface;

  typedef struct DisplayInterface {
  } DisplayInterface;

/*
 *  Windows GDI declarations
 */
  void* wingdiCreateContext();
  void wingdiReleaseContext( void** graphicsContext );

  static const GraphicsContextInterface WinGDI = {
    wingdiCreateContext,
    wingdiReleaseContext
  };

#endif
