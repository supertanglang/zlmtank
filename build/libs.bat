set LIBS_DIR=libs


:clean

del /Q %LIBS_DIR%\*.*


:build

gcc -fpack-struct -std=c99 -c ..\%LIBS_DIR%\stdlib.c -o %LIBS_DIR%\stdlib.o -I ..\include