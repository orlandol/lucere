
#include "lucere.h"
#include "lucimpl.h"
#include "w32app.h"

/*
 *  App implementation
 */

LucereApp* lucCreateApp( const char* title, unsigned width, unsigned height,
  unsigned flags, LucereEventRouter customRouter ) {

  return NULL;
}

unsigned lucReleaseApp( LucereApp** appPtr ) {
  return 2;
}

unsigned lucExitApp( unsigned returnCode ) {
  return 2;
}

unsigned lucRouteEvents( LucereApp* app ) {
  return 2;
}

unsigned lucPauseForEvents( LucereApp* app ) {
  return 2;
}
