@echo off
if exist lucere2d.lib del lucere2d.lib
if exist testgfx1.exe del testgfx1.exe

tcc -c lucere2d.c l2dimpl.c windows\wingdi.c -I. -Iwindows
tcc -ar lucere2d.lib lucere2d.o l2dimpl.o wingdi.o
if exist lucere2d.o del lucere2d.o
if exist l2dimpl.o del l2dimpl.o
if exist wingdi.o del wingdi.o

tcc testgfx1.c lucere2d.lib -Wl,-subsystem=windows
