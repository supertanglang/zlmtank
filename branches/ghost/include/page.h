#ifndef _PAGE_H
#define _PAGE_H

#define SetCr3(x) {\
	      __asm__ __volatile__ (\
        "movl %%eax,%%cr3\n"\
		    : :"a" ( x ));}

//ˢ��ҳ����ٻ�����,ֻҪ��ҳ��Ļ�ַ�ٴ�����cr3�Ĵ���,�ͻ��Զ�ˢ��
#define ReloadPageDir(pg_dir) \
        __asm__("movl %%eax,%%cr3": :"a"(pg_dir))

DWORD GetCr3(void);




void PageDirInit(void);
DWORD PutPage(unsigned long pg_dir,unsigned long page,unsigned long address);

#endif

