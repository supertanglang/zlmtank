#include <types.h>
#include <vga.h>
#include <bootinfo.h>
#include <stdlib.h>
#include <dbg.h>

#include <gdt.h>
#include <idt.h>
#include <irq.h>
#include <traps.h>
#include <time.h>
#include <serial.h>
//刚刚进入c入口
//此时我们在4M多一点点的位子
//刚刚进入保护模式
//GDT只有3张表
//code / data段重叠,都是0-4G


//我要做的事情
//启动分页,系统使用高2G (0x80000000-0xffffffff)
//用户程序使用低2G 0x00000000-0x7fffffff
//重新调整GDT,IDT,PTE

//参见syscfg.h




void PrintBootInfo();
void ntldr_initsyscfg();


void ntldr_main()
{
  InitSerialPort();


  //bios默认在文本模式,还是初始化一下
  vga_init();
  // 清屏
  vga_clrscr();

  SetStd((stdputs)vga_puts);

  PrintBootInfo();

  // 初始化GDT
  gdt_init();

  //初始化IDT
  idt_init();

  //初始化irq
  irq_init();

  //初始化trap
  traps_init();

  //初始化定时器
  timer_init();
  
  SerialTest();

  
  for(;;);
  
  return;
}


void PrintBootInfo()
{
  BYTE *ptr = (BYTE *)BOOTINFO_PTR;
  BOOTINFO *bootinfo = (BOOTINFO *)ptr;
  E820_MAP_ITEM *map_item_ptr = NULL;
  DWORD ii = 0;

  printf(" e801 : memsize = %x (%d kb)\n",
  	     bootinfo->e801_mem_len,
  	     bootinfo->e801_mem_len);

  map_item_ptr = bootinfo->e820_map_ptr;
  for (ii = 0; ii < bootinfo->e820_map_num; ii++)
  {
    printf(" e820: 0x%x%x, 0x%x%x, 0x%x\n",
		   map_item_ptr->mem_base_up32,
		   map_item_ptr->mem_base_low32,
		   map_item_ptr->mem_len_up32,
		   map_item_ptr->mem_len_low32,
		   map_item_ptr->mem_type);
  }
  
}



