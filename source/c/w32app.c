
#include "lucere.h"
#include "lucimpl.h"
#include "w32app.h"

/*
 *  App implementation
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
