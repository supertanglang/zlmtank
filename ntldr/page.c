#include <type.h>
#include <page.h>



//--------------------------------------------------------------------------------------------
//
// 启用分页寄存器
//
//---------------------------------------------------------------------------------------------
void PageEnable(void)
{
  unsigned long cr0;

  __asm__ ("movl %%cr0, %0" : "=r" (cr0));
  __asm__ ("movl %%eax, %%cr3": :"a"(PG_DIR_ADDR));

   /* set most significant bit of CR0 */
  cr0 |= 0x80000000;
  __asm__("movl %%eax, %%cr0": :"a"(cr0));
	__asm__ ("jmp  1f\n\t"\
		   "1:\n\t"\
			 "movl $1f,%eax\n\t"\
       "jmp *%eax\n\t"\
			 "1:");

}



//--------------------------------------------------------------------------------------------
//
// 页目录初始化
//
//---------------------------------------------------------------------------------------------
void PageDirInit(void)
{
  BYTE *
  //初始化页目录,4096字节
  memset();






	unsigned long  index;
	unsigned long  VIDEOMEM;

    //初始化内核目录表
	
	//设置0号页目录4GB空间为     U/S=0 R/W=0  P=0
	for(index=0;index<0x400;index++)
	{
		*(unsigned long*)(PG_DIR_ADDR+index*4) = 0;
	}

  //填如目录表的第一项
	//设置物理空间 0 ~ 8MB                     1 个页表
  for(index=0;index<0x002;index++)     
	{
	  *(unsigned long *)(PG_DIR_ADDR+index*4) = 
		 (PG_TABLE_ADDR+index*4096)|7;
	}


	//设置剩下的 8MB ~ 12M 空间为显存映射   1 个页表
	for(index=0x300;index<0x301;index++)		//3g
	{
    *(unsigned long*)(PG_DIR_ADDR+index*4) =
		 (VESA_INFO_PTE+(index-0x300)*4096)|7;
	}
  
  
  //设置剩下的 12MB ~ 16M 空间为显存映射   1 个页表
	for(index=0x3e8;index<0x3e9;index++)
	{
    *(unsigned long*)(PG_DIR_ADDR+index*4) =
		 (VESA_PTE+(index-0x3e8)*4096)|7;
	}


  
	
	
	
	//设置0号页目录的1个页表映射到物理内存 0~4MB
	for (index=0;index<0x400;index++)	          //0x400 = 1k pages * 4KB= 4MB
	{
    *((unsigned long*)(SYS_PTE+index*4)) = (index * 4096)|7;
	}


	//建立显存映射页表
	for (index=0;index<0x400;index++)         // 1k pages * 4KB =4 MB
	{
		*((unsigned long *)(VESA_PTE+index*4))=(PG_VRAM+index*4096)|7;
	}

	//建立显示模式信息区
	for (index=0;index<0x400;index++)         // 1k pages * 4KB =4 MB
	{
		*((unsigned long *)(VESA_INFO_PTE+index*4))=(V_MODE+index*4096)|7;
	}
	
	PageEnable();
	SetCr3(GetCr3());
}


//-----------------------------------------------------------------------



//-----------------------------------------------------------------------
unsigned long GetCr3(void)
{
  register unsigned long x;
  __asm__ __volatile__ ("movl %%cr3,%0" : "=r" (x));
  return (x);
}
