@echo off
if exist lucere2d.lib del lucere2d.lib
if exist testgfx1.exe del testgfx1.exe

tcc -c lucere2d.c windows\winimpl.c -I. -Iwindows
tcc -ar lucere2d.lib lucere2d.o winimpl.o
if exist lucere2d.o del lucere2d.o
if exist winimpl.o del winimpl.o

tcc testgfx1.c lucere2d.lib -Wl,-subsystem=windows
