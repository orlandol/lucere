@echo off
if exist lucere32.lib del lucere32.lib
if exist lucere64.lib del lucere64.lib
if exist *.o del *.o

if exist lucere.c tcc -m32 -c lucere.c
if exist lucimpl.c tcc -m32 -c lucimpl.c
if exist w32app.c tcc -m32 -c w32app.c
if exist w32gdi.c tcc -m32 -c w32gdi.c
tcc -m32 -ar lucere32.lib lucere.o lucimpl.o w32app.o w32gdi.o
if exist *.o del *.o

if exist lucere.c tcc -m64 -c lucere.c
if exist lucimpl.c tcc -m64 -c lucimpl.c
if exist w32app.c tcc -m64 -c w32app.c
if exist w32gdi.c tcc -m64 -c w32gdi.c
tcc -m64 -ar lucere64.lib lucere.o lucimpl.o w32app.o w32gdi.o
if exist *.o del *.o
