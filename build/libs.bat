set LIBS_DIR=libs
set COMPILER_FLAG=-fpack-struct -std=c99 -c -fno-builtin

:clean

del /Q %LIBS_DIR%\*.*


:build

gcc %COMPILER_FLAG% ..\%LIBS_DIR%\stdlib.c -o %LIBS_DIR%\stdlib.o -I ..\include