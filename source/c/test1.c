
#include <stdlib.h>

#include "lucere.h"

int main( int argc, char** argv ) {
  LucApp* app = NULL;

  lucCreateApp("Test1", 640, 480, 0, NULL);
  if( app == NULL ) {
    ///TODO: Pop up message using lucError variable
    exit(1);
  }

  while( lucRouteEvents(app) ) {
  }

  lucReleaseApp( &app );

  return 0;
}
