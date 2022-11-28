@echo off
call clean.bat

tcc -c lucere2d.c l2dimpl.c windows\wingdi.c windows\w32app.c
tcc -ar lucere2d.lib lucere2d.o l2dimpl.o wingdi.o w32app.o
if exist lucere2d.o del lucere2d.o
if exist l2dimpl.o del l2dimpl.o
if exist wingdi.o del wingdi.o
if exist w32app.o del w32app.o

tcc testapp1.c lucere2d.lib -Wl,-subsystem=windows -luser32 -lgdi32
tcc testgfx1.c lucere2d.lib -Wl,-subsystem=windows -luser32 -lgdi32
