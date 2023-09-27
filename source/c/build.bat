@echo off
call clean.bat

if exist lucere.c tcc -m32 -Wall -Werror -c lucere.c
if exist lucimpl.c tcc -m32 -Wall -Werror -c lucimpl.c
tcc -m32 -ar lucere32.lib lucere.o lucimpl.o
if exist *.o del *.o

if exist lucere.c tcc -m64 -Wall -Werror -c lucere.c
if exist lucimpl.c tcc -m64 -Wall -Werror -c lucimpl.c
tcc -m64 -ar lucere64.lib lucere.o lucimpl.o
if exist *.o del *.o

if exist test1.c tcc -m32 test1.c lucere32.lib
