@echo off
if exist gsuinfo.c tcc gsuinfo.c -Wl,-subsystem=windows
if exist w32win.c tcc w32win.c -Wl,-subsystem=windows -luser32
