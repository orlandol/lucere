@echo off
call clean.bat

if exist lucere.c tcc -m32 -c lucere.c -Wall -Werror
if exist lucimpl.c tcc -m32 -c lucimpl.c -Wall -Werror
tcc -m32 -ar lucere32.lib lucere.o lucimpl.o
if exist *.o del *.o

if exist lucere.c tcc -m64 -c lucere.c -Wall -Werror
if exist lucimpl.c tcc -m64 -c lucimpl.c -Wall -Werror
tcc -m64 -ar lucere64.lib lucere.o lucimpl.o
if exist *.o del *.o

if exist test1.c tcc -m32 test1.c lucere32.lib -luser32 -Wall -Werror
