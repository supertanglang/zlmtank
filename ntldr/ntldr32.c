#include <types.h>
#include <vga.h>

//刚刚进入c入口
//此时我们在4M多一点点的位子
//刚刚进入保护模式
//GDT只有3张表
//code / data段重叠,都是0-4G





void ntldr_main()
{
  //
  vga_init();
  vga_puts("aaaa\n");
  for(;;);
  
  return;
}

