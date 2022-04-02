@echo off
if exist lucere2d.lib del lucere2d.lib

tcc -c lucere2d.c windows\winimpl.c -I. -Iwindows
tcc -ar lucere2d.lib lucere2d.o winimpl.o
