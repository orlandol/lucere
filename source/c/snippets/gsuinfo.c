
#include "windows.h"

#include <stdio.h>

int main( int argc, char* argv[] ) {
  STARTUPINFO suinfo = {};

  GetStartupInfo( &suinfo );

  FILE* logFile = fopen("gsuinfo.txt", "w");
  if( logFile ) {
    fprintf( logFile, "cb == %u\n", suinfo.cb );
    fprintf( logFile, "lpReserved == '%s'\n", suinfo.lpReserved );
    fprintf( logFile, "lpDesktop == '%s'\n",  suinfo.lpDesktop );
    fprintf( logFile, "lpTitle == '%s'\n", suinfo.lpTitle );
    fprintf( logFile, "dwX == %u\n", suinfo.dwX );
    fprintf( logFile, "dwY == %u\n", suinfo.dwY );
    fprintf( logFile, "dwXSize == %u\n", suinfo.dwXSize );
    fprintf( logFile, "dwYSize == %u\n", suinfo.dwYSize );
    fprintf( logFile, "dwXCountChars == %u\n", suinfo.dwXCountChars );
    fprintf( logFile, "dwYCountChars == %u\n", suinfo.dwYCountChars );
    fprintf( logFile, "dwFillAttribute == %u\n", suinfo.dwFillAttribute );
    fprintf( logFile, "dwFlags == %0x\n", suinfo.dwFlags );
    fprintf( logFile, "wShowWindow == %u\n", suinfo.wShowWindow );
    fprintf( logFile, "cbReserved2 == %u\n", suinfo.cbReserved2 );
    fprintf( logFile, "lpReserved2 == %u\n", suinfo.lpReserved2 ? *(suinfo.lpReserved2) : 0 );
    fprintf( logFile, "hStdInput is %sNULL\n", suinfo.hStdInput ? "non-" : "" );
    fprintf( logFile, "hStdOutput is %sNULL\n", suinfo.hStdOutput ? "non-" : "" );
    fprintf( logFile, "hStdError is %sNULL\n", suinfo.hStdError ? "non-" : "" );

    fclose( logFile );
    logFile = NULL;
  }

  return 0;
}
