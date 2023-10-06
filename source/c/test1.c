
#include <stdlib.h>

#include "lucere.h"

int main( int argc, char** argv ) {
  LucApp* app = NULL;
  LucEvent event;

  app = lucCreateApp("Test1", 640, 480, 0, NULL);
  if( app == NULL ) {
    ///TODO: Pop up message using lucError variable
    exit(1);
  }

  while( lucAppRunning(app) ) {
    event = lucGetEvent(app);

    if( event.what == eventCleanup ) {
      lucExitApp( app, 0 );
      break;
    }

    switch( event.what ) {
    case eventKeyDown:
      if( event.key == lucKeyEscape ) {
        lucExitApp( app, 0 );
        break;
      }
      lucPassEvent( app, &event );
      break;
    }
  }

  lucReleaseApp( &app );

  return 0;
}
