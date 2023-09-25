
#include "lucere.h"
#include "lucimpl.h"

/*
 *  Win32 Application implementation
 */

LucApp* lucCreateApp( const char* title, unsigned width, unsigned height,
  unsigned flags, LucEventRouter customRouter ) {

  return NULL;
}

unsigned lucReleaseApp( LucApp** appPtr ) {
  return 2;
}

unsigned lucExitApp( unsigned returnCode ) {
  return 2;
}

unsigned lucRouteEvents( LucApp* app ) {
  return 2;
}

unsigned lucWaitForNextEvent( LucApp* app ) {
  return 2;
}

/*
 *  Abstract Display implementation
 */

LucDisplay* lucCreateDisplay( LucApp* app,
  unsigned monitorIndex, LucGraphicsSystem* graphics ) {

  return NULL;
}

unsigned lucReleaseDisplay( LucDisplay** displayPtr ) {
  return 2;
}

/*
 *  Win32 Display implementation
 */

unsigned lucDisplayCount( LucApp* app ) {
  return 2;
}

LucDisplay* gdiDisplayCreate( LucApp* app, unsigned monitorIndex,
  LucGraphicsSystem* graphicsSystem ) {

  return NULL;
}

unsigned gdiDisplayRelease( LucDisplay** displayPtr ) {
  return 2;
}
