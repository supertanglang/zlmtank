set NTLDR_DIR=ntldr
set LIBS_DIR=libs


:clean

del /Q %NTLDR_DIR%\*.*


:build

nasm ..\%NTLDR_DIR%\ntldr16.asm -o %NTLDR_DIR%\ntldr16.s -i ..\%NTLDR_DIR%\

nasm -f elf ..\%NTLDR_DIR%\ntldr32pre.asm -o %NTLDR_DIR%\ntldr32pre.s -i ..\%NTLDR_DIR%\
objcopy -R .note -R .comment -S -O binary %NTLDR_DIR%\ntldr32pre.s %NTLDR_DIR%\ntldr32pre.out

nasm -f elf ..\%NTLDR_DIR%\ntldr32.asm -o %NTLDR_DIR%\ntldr32.s -i ..\%NTLDR_DIR%\



gcc -fpack-struct -std=c99 -c ..\%NTLDR_DIR%\ntldr32.c -o %NTLDR_DIR%\ntldr32.o -I %CD%\..\include

gcc -fpack-struct -std=c99 -c ..\%NTLDR_DIR%\vga.c -o %NTLDR_DIR%\vga.o -I %CD%\..\include


ld -o %NTLDR_DIR%\ntldr32.bin -Ttext 0x400000 -e ntldr_entry %NTLDR_DIR%\ntldr32.s %NTLDR_DIR%\ntldr32.o %LIBS_DIR%\stdlib.o %NTLDR_DIR%\vga.o

objcopy -R .note -R .comment -S -O binary %NTLDR_DIR%\ntldr32.bin %NTLDR_DIR%\ntldr32.out

mkimg %NTLDR_DIR%\ntldr %NTLDR_DIR%\ntldr16.s %NTLDR_DIR%\ntldr32pre.out %NTLDR_DIR%\ntldr32.out