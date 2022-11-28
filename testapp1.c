
#include <stdlib.h>
#include <stdio.h>

#include "lucere2d.h"

L2DApp* app = NULL;

void Cleanup() {
  ReleaseApp( &app );
}

void LogMessage( const char* fileName, const char* message ) {
  FILE* logFile = NULL;

  if( fileName && (*fileName) ) {
    logFile = fopen(fileName, "a");
    if( logFile ) {
      fprintf( logFile, "%s\n", message );

      fclose( logFile );
      logFile = NULL;
    }
  }
}

int main( int argc, char** argv ) {
  atexit( Cleanup );

  LogMessage( "testapp1.log", "Starting program" );

  app = CreateApp(0, 0, "TestApp1", NULL);

  while( AppIsOpen(app) ) {
  }

  Cleanup();

  LogMessage( "testapp1.log", "Closing program" );

  return 0;
}
