#ifndef _PAGE_H
#define _PAGE_H

#define SetCr3(x) {\
	      __asm__ __volatile__ (\
        "movl %%eax,%%cr3\n"\
		    : :"a" ( x ));}

//刷新页表高速缓冲区,只要将页表的基址再次送入cr3寄存器,就会自动刷新
#define ReloadPageDir(pg_dir) \
        __asm__("movl %%eax,%%cr3": :"a"(pg_dir))

DWORD GetCr3(void);




void PageDirInit(void);
DWORD PutPage(unsigned long pg_dir,unsigned long page,unsigned long address);

#endif

