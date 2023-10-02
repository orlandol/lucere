
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

  while( lucAppIsRunning(app) ) {
    event = lucGetEvent(app);

    if( event.what == lucEventExit ) {
      lucExitApp( app, 0 );
      break;
    }

    switch( event.what ) {
    case lucEventExit:
      lucExitApp( app, 0 );
      break;

    case lucEventKeyDown:
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
